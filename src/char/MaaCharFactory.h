#pragma once
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>
#include "CharFactory.h"

// Original OK-WW CharFactory.get_char_by_pos compares all registered portrait
// templates inside box_char_1/2/3 and accepts the best score >= 0.6.
// These 720p boxes are scaled from assets/coco_annotations.json image 152.
struct CharacterMatch {
    const CharacterDefinition* definition = nullptr;
    double confidence = 0;
    bool reused = false;
};
struct CharacterBox { int x, y, width, height; };
inline constexpr std::array<CharacterBox, 3> original_character_boxes{{
    {1172, 139, 43, 52}, {1172, 229, 42, 50}, {1172, 318, 44, 50}
}};

template<class Score>
std::array<CharacterMatch, 3> recognize_original_team(Score&& score,
    const std::array<CharacterMatch,3>& previous={},int count=3) {
    std::array<CharacterMatch, 3> matches{};
    for (size_t slot = 0; slot < size_t(count); ++slot) {
        const auto& box = original_character_boxes[slot];
        const auto& old=previous[slot];
        if(old.definition && old.confidence>0.92){
            double confidence=score(old.definition->portrait_image.data(),box);
            if(old.definition->alternate_portrait_image)confidence=std::max(confidence,
                score(old.definition->alternate_portrait_image,box));
            if(confidence>=0.6){matches[slot]=old;matches[slot].reused=true;continue;}
        }
        for (const auto& definition : character_definitions) {
            double confidence = score(definition.portrait_image.data(), box);
            if (definition.alternate_portrait_image) {
                confidence = std::max(confidence,
                    score(definition.alternate_portrait_image, box));
            }
            if (confidence >= 0.6 && confidence > matches[slot].confidence)
                matches[slot] = {&definition, confidence};
        }
        if(!matches[slot].definition && old.definition){matches[slot]=old;matches[slot].reused=true;}
    }
    return matches;
}

// MaaTaskerPostRecognition receives one cached screenshot for all 50 original
// character templates, matching OK-WW's one-frame get_char_by_pos semantics.
// The Maa resource already contains the original resized portrait images.
inline std::array<CharacterMatch, 3> recognize_maafw_team(
    HMODULE dll, MaaTasker* tasker, MaaController* controller) {
    auto ctrl_post = api<decltype(&MaaControllerPostScreencap)>(dll, "MaaControllerPostScreencap");
    auto ctrl_wait = api<decltype(&MaaControllerWait)>(dll, "MaaControllerWait");
    auto ctrl_cached = api<decltype(&MaaControllerCachedImage)>(dll, "MaaControllerCachedImage");
    auto image_create = api<decltype(&MaaImageBufferCreate)>(dll, "MaaImageBufferCreate");
    auto image_destroy = api<decltype(&MaaImageBufferDestroy)>(dll, "MaaImageBufferDestroy");
    auto post = api<decltype(&MaaTaskerPostRecognition)>(dll, "MaaTaskerPostRecognition");
    auto wait = api<decltype(&MaaTaskerWait)>(dll, "MaaTaskerWait");
    auto task_detail = api<decltype(&MaaTaskerGetTaskDetail)>(dll, "MaaTaskerGetTaskDetail");
    auto node_detail = api<decltype(&MaaTaskerGetNodeDetail)>(dll, "MaaTaskerGetNodeDetail");
    auto reco_detail = api<decltype(&MaaTaskerGetRecognitionDetail)>(dll, "MaaTaskerGetRecognitionDetail");
    auto str_create = api<decltype(&MaaStringBufferCreate)>(dll, "MaaStringBufferCreate");
    auto str_destroy = api<decltype(&MaaStringBufferDestroy)>(dll, "MaaStringBufferDestroy");
    auto str_get = api<decltype(&MaaStringBufferGet)>(dll, "MaaStringBufferGet");
    MaaImageBuffer* image = image_create();
    if (!image || ctrl_wait(controller, ctrl_post(controller)) != MaaStatus_Succeeded ||
        !ctrl_cached(controller, image)) {
        if (image) image_destroy(image);
        throw std::runtime_error("Maa character snapshot failed");
    }
    const auto score = [&](const char* filename, CharacterBox box) {
        const std::string params = std::string("{\"template\":\"") + filename +
            "\",\"threshold\":0.01,\"order_by\":\"Score\",\"roi\":[" +
            std::to_string(box.x) + ',' + std::to_string(box.y) + ',' +
            std::to_string(box.width) + ',' + std::to_string(box.height) + "]}";
        const MaaTaskId id = post(tasker, "TemplateMatch", params.c_str(), image);
        (void)wait(tasker, id);
        MaaNodeId nodes[8]{};
        MaaSize count = 8;
        MaaStatus actual = MaaStatus_Invalid;
        MaaStringBuffer* entry = str_create();
        double value = 0;
        if (entry && task_detail(tasker, id, entry, nodes, &count, &actual) && count) {
            MaaRecoId reco = MaaInvalidId;
            MaaActId action = MaaInvalidId;
            MaaBool complete = false;
            MaaStringBuffer* node = str_create();
            if (node && node_detail(tasker, nodes[count - 1], node, &reco, &action, &complete) &&
                reco != MaaInvalidId) {
                MaaStringBuffer* algorithm = str_create();
                MaaStringBuffer* detail = str_create();
                MaaBool hit = false;
                MaaRect result_box{};
                if (algorithm && detail && reco_detail(tasker, reco, node, algorithm, &hit,
                    &result_box, detail, nullptr, nullptr)) {
                    const char* raw = str_get(detail);
                    const std::string details = raw ? raw : "";
                    const size_t best = details.find("\"best\"");
                    const size_t key = best==std::string::npos?std::string::npos:details.find("\"score\"",best);
                    if (key != std::string::npos) {
                        const size_t colon = details.find(':', key);
                        if (colon != std::string::npos) {
                            char* end = nullptr;
                            const double parsed = std::strtod(details.c_str() + colon + 1, &end);
                            if (end != details.c_str() + colon + 1) value = parsed;
                        }
                    }
                }
                if (detail) str_destroy(detail);
                if (algorithm) str_destroy(algorithm);
            }
            if (node) str_destroy(node);
        }
        if (entry) str_destroy(entry);
        return value;
    };
    auto matches = recognize_original_team(score);
    image_destroy(image);
    return matches;
}

inline bool original_team_is(const std::array<CharacterMatch, 3>& team,
                             const char* first, const char* second, const char* third) {
    return team[0].definition && team[1].definition && team[2].definition &&
           team[0].definition->class_name == first &&
           team[1].definition->class_name == second &&
           team[2].definition->class_name == third;
}
