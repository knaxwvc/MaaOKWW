#pragma once
#include <array>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <cstdint>
#include <regex>
#include <string>
#include <vector>
#include "MaaFramework/MaaAPI.h"
#include "OriginalBoxes.h"
#include "MaaRecognitionSession.h"

// Port of BaseCombatTask.refresh_cd/get_cd and
// BaseWWTask.isolate_white_text_to_black. MaaFramework performs OCR; this
// class prepares the original single HUD ROI and distributes recognized
// numbers to the three original E/Q/R columns.
class OriginalCooldown {
    HMODULE dll_;
    MaaController* controller_;
    MaaTasker* tasker_;
    MaaRecognitionSession recognition_;
    MaaImageBuffer* prepared_=nullptr;
    MaaImageBuffer* own_screen_=nullptr;
    std::vector<unsigned char> isolated_;
    struct Cache {
        double read_at=0;
        std::array<double,3> values{};
        std::string detail;
        bool valid = false;
    };
    std::array<Cache,3> cache_{};
    std::uint64_t scene_version_=0,refreshed_scene_=~std::uint64_t(0);
    int refreshed_slot_=0;
    std::function<double()> seconds_=[](){return std::chrono::duration<double>(
        std::chrono::system_clock::now().time_since_epoch()).count();};
    std::function<double(double)> elapsed_;
    template<class F> F fn(const char* name) const {
        return reinterpret_cast<F>(GetProcAddress(dll_, name));
    }
    static double convert_cd(const std::string& text) {
        char* end = nullptr;
        const double number = std::strtod(text.c_str(), &end);
        if (end != text.c_str() && *end == '\0') return number;
        static const std::regex cd_regex(R"(\d{1,2}\.\d)");
        std::smatch match;
        if (std::regex_search(text, match, cd_regex)) return std::strtod(match.str().c_str(), nullptr);
        return 1.0;
    }
    static std::vector<std::pair<int,std::string>> parse_ocr_all(const std::string& detail) {
        std::vector<std::pair<int,std::string>> found;
        const auto key = detail.find("\"all\":[");
        if (key == std::string::npos) return found;
        const auto end = detail.find("],\"best\"", key);
        const auto all = detail.substr(key, end == std::string::npos ? std::string::npos : end - key);
        static const std::regex item(
            R"re(\{"box":\[(\d+),(\d+),(\d+),(\d+)\],"score":[0-9.eE+-]+,"text":"([^"]*)"\})re");
        for (auto it = std::sregex_iterator(all.begin(), all.end(), item);
             it != std::sregex_iterator(); ++it)
            found.emplace_back(std::stoi((*it)[1].str()), (*it)[5].str());
        return found;
    }
public:
    OriginalCooldown(HMODULE dll, MaaController* controller, MaaTasker* tasker,MaaContext* context=nullptr)
        : dll_(dll), controller_(controller), tasker_(tasker),recognition_(dll,tasker,context) {
        prepared_=fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate")();
        if(!prepared_)throw std::runtime_error("Maa OCR image buffer unavailable");
    }
    ~OriginalCooldown(){
        const auto destroy=fn<decltype(&MaaImageBufferDestroy)>("MaaImageBufferDestroy");
        if(prepared_)destroy(prepared_);
        if(own_screen_)destroy(own_screen_);
    }
    OriginalCooldown(const OriginalCooldown&)=delete;
    OriginalCooldown& operator=(const OriginalCooldown&)=delete;
    std::uint64_t recognition_calls() const{return recognition_.calls;}
    double recognition_ms() const{return recognition_.elapsed_ms;}
    const std::string& last_detail(int slot) const { return cache_.at(slot - 1).detail; }
    void set_timing(std::function<double()> seconds,std::function<double(double)> elapsed) {
        seconds_=std::move(seconds);elapsed_=std::move(elapsed);
    }
    void reset_scene(){++scene_version_;}
    void reset_combat(){cache_={};reset_scene();refreshed_scene_=~std::uint64_t(0);refreshed_slot_=0;}
    bool refresh_scene(int slot,MaaImageBuffer* frame) {
        if(slot<1 || slot>3)return false;
        return (refreshed_scene_==scene_version_ && refreshed_slot_==slot) || refresh(slot,frame);
    }
    double remaining(char key, int slot, bool allow_refresh = true) {
        if (slot < 1 || slot > 3) return 0;
        const int column = key == 'E' ? 0 : key == 'Q' ? 1 : key == 'R' ? 2 : -1;
        if (column < 0) return 0;
        auto& cache = cache_[slot - 1];
        // BaseCombatTask.refresh_cd runs once per scene, with no 500 ms cache.
        if (allow_refresh && (refreshed_scene_!=scene_version_ || refreshed_slot_!=slot))refresh(slot);
        if (!cache.valid) return 0;
        return cache.values[column]-(elapsed_?elapsed_(cache.read_at):seconds_()-cache.read_at);
    }
    bool refresh(int slot,MaaImageBuffer* supplied_frame=nullptr) {
        if (slot < 1 || slot > 3) return false;
        auto post_capture = fn<decltype(&MaaControllerPostScreencap)>("MaaControllerPostScreencap");
        auto ctrl_wait = fn<decltype(&MaaControllerWait)>("MaaControllerWait");
        auto cached = fn<decltype(&MaaControllerCachedImage)>("MaaControllerCachedImage");
        auto create = fn<decltype(&MaaImageBufferCreate)>("MaaImageBufferCreate");
        auto raw = fn<decltype(&MaaImageBufferGetRawData)>("MaaImageBufferGetRawData");
        auto width = fn<decltype(&MaaImageBufferWidth)>("MaaImageBufferWidth");
        auto height = fn<decltype(&MaaImageBufferHeight)>("MaaImageBufferHeight");
        auto channels = fn<decltype(&MaaImageBufferChannels)>("MaaImageBufferChannels");
        auto set_raw = fn<decltype(&MaaImageBufferSetRawData)>("MaaImageBufferSetRawData");
        if(!supplied_frame && !own_screen_)own_screen_=create();
        MaaImageBuffer* screen = supplied_frame?supplied_frame:own_screen_;
        if (!screen || !prepared_)return false;
        bool okay = false;
        do {
            if (!supplied_frame && (ctrl_wait(controller_, post_capture(controller_)) != MaaStatus_Succeeded ||
                !cached(controller_, screen))) break;
            const double read_at=seconds_();
            const int w = width(screen), h = height(screen), c = channels(screen);
            const auto* pixels = static_cast<const unsigned char*>(raw(screen));
            if (!pixels || w <= 0 || h <= 0 || c < 3) break;
            const auto roi=original_screen_box(w,h,0.82,0.86,0.97,0.93);
            const int x0=roi.x,y0=roi.y,x1=roi.x+roi.width,y1=roi.y+roi.height;
            const int roi_w = x1 - x0, roi_h = y1 - y0;
            if (roi_w <= 0 || roi_h <= 0 || x0 < 0 || y0 < 0 || x1 > w || y1 > h) break;
            isolated_.resize(static_cast<size_t>(roi_w) * roi_h * 3);
            for (int y = 0; y < roi_h; ++y) for (int x = 0; x < roi_w; ++x) {
                const auto* source = pixels + ((y0 + y) * w + x0 + x) * c;
                // cv2.inRange(BGR, [0,0,0], [240,240,240]), then GRAY2BGR.
                const unsigned char value = source[0] <= 240 && source[1] <= 240 &&
                                            source[2] <= 240 ? 255 : 0;
                auto* target = isolated_.data() + (y * roi_w + x) * 3;
                target[0] = target[1] = target[2] = value;
            }
            // CV_8UC3; MaaImageBufferSetRawData takes a deep copy of pixels.
            if (!set_raw(prepared_, isolated_.data(), roi_w, roi_h, 16)) break;
            const std::string detail=recognition_.run("OCR",
                "{\"expected\":\"\\\\d{1,2}\\\\.\\\\d\",\"threshold\":0.3}",prepared_).detail;
            auto& result = cache_[slot-1];
            result.values = {0,0,0};
            result.detail = detail;
            const double reference_width = std::min(double(w), double(h) * 16.0 / 9.0);
            const double e_boundary = w - (1.0 - 0.86) * reference_width - x0;
            const double r_boundary = w - (1.0 - 0.91) * reference_width - x0;
            static const std::regex cd_regex(R"(\d{1,2}\.\d)");
            for (const auto& [x, text] : parse_ocr_all(detail)) {
                if (!std::regex_search(text, cd_regex)) continue;
                const int column = x < e_boundary ? 0 : x > r_boundary ? 2 : 1;
                result.values[column] = convert_cd(text);
            }
            result.read_at = read_at;
            result.valid = true;
            refreshed_scene_=scene_version_;
            refreshed_slot_=slot;
            okay = true;
        } while (false);
        return okay;
    }
};
