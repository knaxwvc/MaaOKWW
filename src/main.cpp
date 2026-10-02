#define NOMINMAX
#include <Windows.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "MaaFramework/MaaAPI.h"

namespace fs = std::filesystem;

template<class F> F api(HMODULE module, const char* name) {
    auto p = GetProcAddress(module, name);
    if (!p) throw std::runtime_error(std::string("Missing Maa API: ") + name);
    return reinterpret_cast<F>(p);
}

struct WindowSearch { HWND hwnd = nullptr; };


#include "task/BaseCombatTask.h"
#include "combat/OriginalCooldown.h"

struct StaticImageController {
    std::vector<unsigned char> encoded;
    decltype(&MaaImageBufferSetEncoded) set_image = nullptr;
    decltype(&MaaStringBufferSet) set_string = nullptr;
};

static MaaBool static_connect(void*) { return true; }
static MaaBool static_connected(void*) { return true; }
static MaaBool static_uuid(void* arg, MaaStringBuffer* buffer) {
    return static_cast<StaticImageController*>(arg)->set_string(buffer, "maa-okww-static-test");
}
static MaaControllerFeature static_features(void*) { return 0; }
static MaaBool static_screencap(void* arg, MaaImageBuffer* buffer) {
    auto* state = static_cast<StaticImageController*>(arg);
    return state->set_image(buffer, state->encoded.data(), state->encoded.size());
}
static MaaBool static_inactive(void*) { return true; }

BOOL CALLBACK find_game(HWND hwnd, LPARAM value) {
    wchar_t class_name[128]{};
    wchar_t title[512]{};
    GetClassNameW(hwnd, class_name, 128);
    GetWindowTextW(hwnd, title, 512);
    if (wcscmp(class_name, L"UnrealWindow") == 0 &&
        (wcsstr(title, L"鳴潮") || wcsstr(title, L"鸣潮") || wcsstr(title,L"Wuthering Waves"))) {
        reinterpret_cast<WindowSearch*>(value)->hwnd = hwnd;
        return FALSE;
    }
    return TRUE;
}

int wmain(int argc, wchar_t** argv) {
    fs::path root = fs::absolute(argv[0]).parent_path();
    std::ofstream log(root / "native_run.log", std::ios::app);
    std::cout.rdbuf(log.rdbuf());
    std::cerr.rdbuf(log.rdbuf());
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    std::cout << "native_session build=20261002-hsin-local-rotations-4 root=" << root.generic_u8string() << '\n';
    try {
        if (argc < 2 || argc > 3) {
            std::wcerr << L"Usage: MaaOKWWNative.exe <pipeline-entry> [debug-image]\n";
            return 2;
        }
        fs::path bin = root / "bin";
        if (!SetDllDirectoryW(bin.c_str())) throw std::runtime_error("SetDllDirectory failed");
        HMODULE dll = LoadLibraryW((bin / "MaaFramework.dll").c_str());
        if (!dll) throw std::runtime_error("MaaFramework.dll load failed");

        auto ctrl_win = api<decltype(&MaaWin32ControllerCreate)>(dll, "MaaWin32ControllerCreate");
        auto ctrl_custom = api<decltype(&MaaCustomControllerCreate)>(dll, "MaaCustomControllerCreate");
        auto ctrl_connect = api<decltype(&MaaControllerPostConnection)>(dll, "MaaControllerPostConnection");
        auto ctrl_wait = api<decltype(&MaaControllerWait)>(dll, "MaaControllerWait");
        auto ctrl_destroy = api<decltype(&MaaControllerDestroy)>(dll, "MaaControllerDestroy");
        auto ctrl_screencap = api<decltype(&MaaControllerPostScreencap)>(dll, "MaaControllerPostScreencap");
        auto ctrl_cached = api<decltype(&MaaControllerCachedImage)>(dll, "MaaControllerCachedImage");
        auto image_create = api<decltype(&MaaImageBufferCreate)>(dll, "MaaImageBufferCreate");
        auto image_destroy = api<decltype(&MaaImageBufferDestroy)>(dll, "MaaImageBufferDestroy");
        auto image_data = api<decltype(&MaaImageBufferGetRawData)>(dll, "MaaImageBufferGetRawData");
        auto image_width = api<decltype(&MaaImageBufferWidth)>(dll, "MaaImageBufferWidth");
        auto image_height = api<decltype(&MaaImageBufferHeight)>(dll, "MaaImageBufferHeight");
        auto image_channels = api<decltype(&MaaImageBufferChannels)>(dll, "MaaImageBufferChannels");
        auto image_encoded = api<decltype(&MaaImageBufferGetEncoded)>(dll, "MaaImageBufferGetEncoded");
        auto image_encoded_size = api<decltype(&MaaImageBufferGetEncodedSize)>(dll, "MaaImageBufferGetEncodedSize");
        auto image_set_encoded = api<decltype(&MaaImageBufferSetEncoded)>(dll, "MaaImageBufferSetEncoded");
        auto string_set = api<decltype(&MaaStringBufferSet)>(dll, "MaaStringBufferSet");
        auto res_create = api<decltype(&MaaResourceCreate)>(dll, "MaaResourceCreate");
        auto res_bundle = api<decltype(&MaaResourcePostBundle)>(dll, "MaaResourcePostBundle");
        auto res_wait = api<decltype(&MaaResourceWait)>(dll, "MaaResourceWait");
        auto res_destroy = api<decltype(&MaaResourceDestroy)>(dll, "MaaResourceDestroy");
        auto task_create = api<decltype(&MaaTaskerCreate)>(dll, "MaaTaskerCreate");
        auto task_bind_resource = api<decltype(&MaaTaskerBindResource)>(dll, "MaaTaskerBindResource");
        auto task_bind_controller = api<decltype(&MaaTaskerBindController)>(dll, "MaaTaskerBindController");
        auto task_inited = api<decltype(&MaaTaskerInited)>(dll, "MaaTaskerInited");
        auto task_post = api<decltype(&MaaTaskerPostTask)>(dll, "MaaTaskerPostTask");
        auto task_wait = api<decltype(&MaaTaskerWait)>(dll, "MaaTaskerWait");
        auto task_destroy = api<decltype(&MaaTaskerDestroy)>(dll, "MaaTaskerDestroy");
        auto task_detail = api<decltype(&MaaTaskerGetTaskDetail)>(dll, "MaaTaskerGetTaskDetail");
        auto node_detail = api<decltype(&MaaTaskerGetNodeDetail)>(dll, "MaaTaskerGetNodeDetail");
        auto reco_detail = api<decltype(&MaaTaskerGetRecognitionDetail)>(dll, "MaaTaskerGetRecognitionDetail");
        auto string_create = api<decltype(&MaaStringBufferCreate)>(dll, "MaaStringBufferCreate");
        auto string_destroy = api<decltype(&MaaStringBufferDestroy)>(dll, "MaaStringBufferDestroy");
        auto string_get = api<decltype(&MaaStringBufferGet)>(dll, "MaaStringBufferGet");

        MaaController* controller = nullptr;
        StaticImageController static_image;
        MaaCustomControllerCallbacks static_callbacks{};
        if (argc == 3) {
            std::ifstream source(fs::path(argv[2]), std::ios::binary);
            if (!source) throw std::runtime_error("Static test image not found");
            static_image.encoded.assign(std::istreambuf_iterator<char>(source), std::istreambuf_iterator<char>());
            static_image.set_image = image_set_encoded;
            static_image.set_string = string_set;
            static_callbacks.connect = static_connect;
            static_callbacks.connected = static_connected;
            static_callbacks.request_uuid = static_uuid;
            static_callbacks.get_features = static_features;
            static_callbacks.screencap = static_screencap;
            static_callbacks.inactive = static_inactive;
            controller = ctrl_custom(&static_callbacks, &static_image);
        } else {
            WindowSearch game;
            do {
                EnumWindows(find_game, reinterpret_cast<LPARAM>(&game));
                if(game.hwnd)break;
                if(fs::exists(root/"stop.flag"))return 0;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }while(!game.hwnd);
            controller = ctrl_win(game.hwnd, MaaWin32ScreencapMethod_Background,
                                  MaaWin32InputMethod_PostMessage, MaaWin32InputMethod_PostMessage);
        }
        if (!controller || ctrl_wait(controller, ctrl_connect(controller)) != MaaStatus_Succeeded)
            throw std::runtime_error("Maa controller connection failed");

        MaaResource* resource = res_create();
        std::string resource_path = (root / "resource").string();
        if (!resource || res_wait(resource, res_bundle(resource, resource_path.c_str())) != MaaStatus_Succeeded)
            throw std::runtime_error("Maa resource load failed");

        MaaTasker* tasker = task_create();
        if (!tasker || !task_bind_resource(tasker, resource) ||
            !task_bind_controller(tasker, controller) || !task_inited(tasker))
            throw std::runtime_error("Maa tasker init failed");

        std::string entry = fs::path(argv[1]).string();
        MaaStatus status = MaaStatus_Invalid;
        if (entry == "--roster") {
            const char* names[] = {"aemeath", "linnai", "moning", "qingxiao", "denia",
                                   "shorekeeper", "hiyuki", "lucilla", "chisa"};
            for (int index = 0; index < 9; ++index) {
                const char* name = names[index];
                std::string node = std::string("OKWW_char_") + name;
                const int slot_y[3] = {130, 215, 305};
                std::string override_json = "{\"" + node + "\":{\"roi\":[1150," +
                    std::to_string(slot_y[index % 3]) + ",80,75],\"threshold\":0.82}}";
                auto id = task_post(tasker, node.c_str(), override_json.c_str());
                auto result = task_wait(tasker, id);
                std::cout << name << " status=" << result;
                MaaNodeId nodes[16]{};
                MaaSize count = 16;
                MaaStatus actual = MaaStatus_Invalid;
                auto entry_buf = string_create();
                if (task_detail(tasker, id, entry_buf, nodes, &count, &actual) && count) {
                    MaaRecoId reco = MaaInvalidId;
                    MaaActId act = MaaInvalidId;
                    MaaBool complete = false;
                    auto node_buf = string_create();
                    if (node_detail(tasker, nodes[count - 1], node_buf, &reco, &act, &complete) && reco) {
                        auto algo_buf = string_create();
                        auto detail_buf = string_create();
                        MaaBool hit = false;
                        MaaRect box{};
                        if (reco_detail(tasker, reco, node_buf, algo_buf, &hit, &box, detail_buf, nullptr, nullptr)) {
                            std::cout << " hit=" << int(hit) << " box=" << box.x << ',' << box.y
                                      << ',' << box.width << ',' << box.height
                                      << " detail=" << string_get(detail_buf);
                        }
                        string_destroy(detail_buf);
                        string_destroy(algo_buf);
                    }
                    string_destroy(node_buf);
                }
                string_destroy(entry_buf);
                std::cout << '\n';
            }
            status = MaaStatus_Succeeded;
        } else if (entry == "--roster-all") {
            const auto team = recognize_maafw_team(dll, tasker, controller);
            for (size_t slot = 0; slot < team.size(); ++slot)
                std::cout << "character_slot=" << slot + 1 << " class="
                          << (team[slot].definition ? team[slot].definition->class_name : "unknown")
                          << " score=" << team[slot].confidence << '\n';
            status = MaaStatus_Succeeded;
        } else if (entry == "--hud-probe") {
            bool raw_size=true;
            if(!api<decltype(&MaaControllerSetOption)>(dll,"MaaControllerSetOption")(
                controller,MaaCtrlOption_ScreenshotUseRawSize,&raw_size,sizeof(raw_size)))
                throw std::runtime_error("Maa HUD raw capture option failed");
            const auto started=std::chrono::steady_clock::now();
            MaaFrameRecognition snapshot(dll,tasker,controller,root);
            if(!snapshot.capture())throw std::runtime_error("HUD snapshot failed");
            std::array<double,3> scores{{-1,-1,-1}};
            const int slot=snapshot.active_slot(&scores);
            std::cout<<"hud_probe frame="<<snapshot.width<<'x'<<snapshot.height
                <<" active="<<slot<<" labels="<<scores[0]<<','<<scores[1]<<','<<scores[2]
                <<" elapsed_ms="<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-started).count()<<'\n';
            snapshot.save(root/"native_capture.png");
            status=MaaStatus_Succeeded;
        } else if (entry == "--cooldown-probe") {
            OriginalCooldown cooldown(dll, controller, tasker);
            const auto e = cooldown.remaining('E', 1);
            const auto q = cooldown.remaining('Q', 1);
            const auto r = cooldown.remaining('R', 1);
            std::cout << "cooldown_probe E=" << e << " Q=" << q << " R=" << r << '\n';
            std::cout << "cooldown_detail=" << cooldown.last_detail(1) << '\n';
            status = MaaStatus_Succeeded;
        } else if (entry == "--combat-one" || entry == "--combat-one-team1" ||
                   entry == "--combat-one-team2" || entry == "--combat-one-team3") {
            status = run_combat(root, dll, controller, tasker, entry, argc);
        } else if (entry == "--target-probe") {
            const int regions[][4] = {{946, 629, 40, 40}, {880, 620, 45, 50}, {817, 624, 45, 45}};
            for (int roi = 0; roi < 3; ++roi) {
                const std::string params = "{\"NativeTargetStateCompare\":{\"roi\":[" +
                    std::to_string(regions[roi][0]) + ',' + std::to_string(regions[roi][1]) + ',' +
                    std::to_string(regions[roi][2]) + ',' + std::to_string(regions[roi][3]) +
                    "],\"threshold\":[0.01,0.01]}}";
                const MaaTaskId id = task_post(tasker, "NativeTargetStateCompare", params.c_str());
                const auto result = task_wait(tasker, id);
                std::cout << "NativeTargetStateCompare roi=" << roi << " status=" << result;
                MaaNodeId node_ids[8]{};
                MaaSize count = 8;
                MaaStatus actual = MaaStatus_Invalid;
                auto entry_buf = string_create();
                if (task_detail(tasker, id, entry_buf, node_ids, &count, &actual) && count) {
                    MaaRecoId reco = MaaInvalidId;
                    MaaActId action = MaaInvalidId;
                    MaaBool complete = false;
                    auto node_buf = string_create();
                    if (node_detail(tasker, node_ids[count - 1], node_buf, &reco, &action, &complete) && reco) {
                        auto algo_buf = string_create();
                        auto detail_buf = string_create();
                        MaaBool hit = false;
                        MaaRect box{};
                        if (reco_detail(tasker, reco, node_buf, algo_buf, &hit, &box,
                                        detail_buf, nullptr, nullptr))
                            std::cout << " hit=" << int(hit) << " detail=" << string_get(detail_buf);
                        string_destroy(detail_buf);
                        string_destroy(algo_buf);
                    }
                    string_destroy(node_buf);
                }
                string_destroy(entry_buf);
                std::cout << '\n';
            }
            status = MaaStatus_Succeeded;
        } else if (entry == "--ocr-probe") {
            for (const char* node : {"NativeOCRProbe", "NativeCooldownOCR"}) {
                const MaaTaskId id = task_post(tasker, node, "{}");
                const auto result = task_wait(tasker, id);
                std::cout << node << " status=" << result;
                MaaNodeId node_ids[8]{};
                MaaSize count = 8;
                MaaStatus actual = MaaStatus_Invalid;
                auto entry_buf = string_create();
                if (task_detail(tasker, id, entry_buf, node_ids, &count, &actual) && count) {
                    MaaRecoId reco = MaaInvalidId;
                    MaaActId action = MaaInvalidId;
                    MaaBool complete = false;
                    auto node_buf = string_create();
                    if (node_detail(tasker, node_ids[count - 1], node_buf, &reco, &action, &complete) && reco) {
                        auto algo_buf = string_create();
                        auto detail_buf = string_create();
                        MaaBool hit = false;
                        MaaRect box{};
                        if (reco_detail(tasker, reco, node_buf, algo_buf, &hit, &box,
                                        detail_buf, nullptr, nullptr))
                            std::cout << " hit=" << int(hit) << " detail=" << string_get(detail_buf);
                        string_destroy(detail_buf);
                        string_destroy(algo_buf);
                    }
                    string_destroy(node_buf);
                }
                string_destroy(entry_buf);
                std::cout << '\n';
            }
            status = MaaStatus_Succeeded;
        } else if (entry == "--probe") {
            CombatCheck combat_check(dll, controller);
            auto hud = combat_check.capture();
            auto buffer = image_create();
            status = ctrl_wait(controller, ctrl_screencap(controller));
            if (status == MaaStatus_Succeeded && ctrl_cached(controller, buffer)) {
                std::ofstream screenshot(root / "native_capture.png", std::ios::binary);
                screenshot.write(reinterpret_cast<const char*>(image_encoded(buffer)),
                                 static_cast<std::streamsize>(image_encoded_size(buffer)));
                const int width = image_width(buffer);
                const int height = image_height(buffer);
                const int channels = image_channels(buffer);
                const auto* pixels = static_cast<const unsigned char*>(image_data(buffer));
                int max_red_run = 0;
                int max_red_row = -1;
                if (pixels && channels >= 3) {
                    for (int y = 0; y < height; ++y) {
                        int run = 0;
                        for (int x = 0; x < width; ++x) {
                            const auto* p = pixels + (y * width + x) * channels;
                            const bool red = p[2] >= 174 && p[2] <= 225 &&
                                             p[1] >= 55 && p[1] <= 85 &&
                                             p[0] >= 55 && p[0] <= 76;
                            run = red ? run + 1 : 0;
                            if (run > max_red_run) { max_red_run = run; max_red_row = y; }
                        }
                    }
                }
                std::cout << "frame=" << width << 'x' << height << " channels=" << channels
                          << " max_red_run=" << max_red_run << " row=" << max_red_row
                          << " concerto_coverage=" << hud.concerto_coverage
                          << " concerto_full=" << hud.concerto_full << '\n';
                for (const char* name : {"OKWW_has_target_169", "OKWW_no_target_169",
                                         "OKWW_char_1_text", "OKWW_char_2_text", "OKWW_char_3_text"}) {
                    auto result = task_wait(tasker, task_post(tasker, name, "{}"));
                    std::cout << name << '=' << result << '\n';
                }
                int label_count = 0, missing_slot = -1;
                const int label_y[3] = {130, 215, 305};
                for (int i = 0; i < 3; ++i) {
                    std::string node = "OKWW_char_" + std::to_string(i + 1) + "_text";
                    std::string params = "{\"" + node + "\":{\"roi\":[1150," +
                        std::to_string(label_y[i]) + ",80,75],\"threshold\":0.8}}";
                    const bool hit = task_wait(tasker, task_post(tasker, node.c_str(), params.c_str())) == MaaStatus_Succeeded;
                    std::cout << "slot_label_" << i + 1 << '=' << hit << '\n';
                    if (hit) ++label_count;
                    else missing_slot = i + 1;
                }
                std::cout << "active_slot_candidate="
                          << (label_count == 2 ? missing_slot : -1) << '\n';
            }
            image_destroy(buffer);
        } else {
            status = task_wait(tasker, task_post(tasker, entry.c_str(), "{}"));
            std::cout << "entry=" << entry << " status=" << status << '\n';
        }
        task_destroy(tasker);
        res_destroy(resource);
        ctrl_destroy(controller);
        FreeLibrary(dll);
        return status == MaaStatus_Succeeded ? 0 : 1;
    } catch (const std::exception& ex) {
        std::cerr << "Maa native error: " << ex.what() << '\n';
        return 1;
    }
}




