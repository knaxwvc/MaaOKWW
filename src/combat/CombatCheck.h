#pragma once
#include "OriginalConcerto.h"
#include "OriginalBoxes.h"
#include <memory>
struct FramePixels {
    std::shared_ptr<std::vector<unsigned char>> bytes;
    bool empty() const {return !bytes || bytes->empty();}
    const unsigned char* data() const {return bytes?bytes->data():nullptr;}
    size_t size() const {return bytes?bytes->size():0;}
    void assign(const unsigned char* begin,const unsigned char* end){
        bytes=std::make_shared<std::vector<unsigned char>>(begin,end);
    }
};
struct FrameState {
    int width = 0;
    int height = 0;
    int channels = 0;
    FramePixels pixels;
    int red_run = 0;
    int boss_run = 0;
    double resonance_white = 0;
    double echo_white = 0;
    double liberation_white = 0;
    double forte_white = 0;
    double linnai_color_white = 0;
    double cantarella_forte_white = 0;
    double xigelika_forte_white = 0;
    double luhesi_lib_white = 0;
    double levitator_white = 0;
    double concerto_coverage = 0;
    bool concerto_full = false;
    int concerto_color_index = -1;
    std::vector<unsigned char> portraits;
};
inline bool in_combat(const FrameState& state) { return state.red_run >= 8 || state.boss_run >= 40; }


class CombatCheck {
    OriginalConcerto concerto;
    MaaController* controller;
    decltype(&MaaControllerWait) ctrl_wait;
    decltype(&MaaControllerPostScreencap) ctrl_screencap;
    decltype(&MaaControllerCachedImage) ctrl_cached;
    decltype(&MaaImageBufferCreate) image_create;
    decltype(&MaaImageBufferDestroy) image_destroy;
    decltype(&MaaImageBufferGetRawData) image_data;
    decltype(&MaaImageBufferWidth) image_width;
    decltype(&MaaImageBufferHeight) image_height;
    decltype(&MaaImageBufferChannels) image_channels;
public:
    void load_calibrations(const std::filesystem::path& runtime,const std::filesystem::path& original){concerto.load_calibrations(runtime,original);}
    void set_ring_index(int index) { concerto.set_color_index(index); }
    CombatCheck(HMODULE dll, MaaController* c) : controller(c),
        ctrl_wait(api<decltype(&MaaControllerWait)>(dll, "MaaControllerWait")),
        ctrl_screencap(api<decltype(&MaaControllerPostScreencap)>(dll, "MaaControllerPostScreencap")),
        ctrl_cached(api<decltype(&MaaControllerCachedImage)>(dll, "MaaControllerCachedImage")),
        image_create(api<decltype(&MaaImageBufferCreate)>(dll, "MaaImageBufferCreate")),
        image_destroy(api<decltype(&MaaImageBufferDestroy)>(dll, "MaaImageBufferDestroy")),
        image_data(api<decltype(&MaaImageBufferGetRawData)>(dll, "MaaImageBufferGetRawData")),
        image_width(api<decltype(&MaaImageBufferWidth)>(dll, "MaaImageBufferWidth")),
        image_height(api<decltype(&MaaImageBufferHeight)>(dll, "MaaImageBufferHeight")),
        image_channels(api<decltype(&MaaImageBufferChannels)>(dll, "MaaImageBufferChannels")) {}
    FrameState capture(bool fresh = true,MaaImageBuffer* supplied_frame=nullptr,bool legacy_scan=true) {
                FrameState state;
                auto buffer = supplied_frame?supplied_frame:image_create();
                if (supplied_frame || ((!fresh || ctrl_wait(controller, ctrl_screencap(controller)) == MaaStatus_Succeeded) &&
                    ctrl_cached(controller, buffer))) {
                    state.width = image_width(buffer);
                    state.height = image_height(buffer);
                    const int channels = image_channels(buffer);
                    state.channels = channels;
                    const auto* pixels = static_cast<const unsigned char*>(image_data(buffer));
                    if (pixels && channels >= 3 && state.width >= 1000 && state.height >= 700) {
                        state.pixels.assign(pixels, pixels + size_t(state.width)*state.height*channels);
                        auto color_ratio = [&](ScreenBox box, int blue, int green, int red) {
                            if (box.x < 0 || box.y < 0 || box.width <= 0 || box.height <= 0 ||
                                box.x + box.width > state.width || box.y + box.height > state.height) return 0.0;
                            int total = 0, white = 0;
                            for (int y = box.y; y < box.y + box.height; ++y)
                                for (int x = box.x; x < box.x + box.width; ++x) {
                                const auto* p = pixels + (y * state.width + x) * channels;
                                ++total;
                                if (p[0] >= blue && p[1] >= green && p[2] >= red) ++white;
                            }
                            return total ? double(white) / total : 0.0;
                        };
                        auto original_white = [&](std::string_view name) {
                            const auto* source = find_original_box(name);
                            return source ? color_ratio(scale_original_box(*source,state.width,state.height),
                                                        244,244,244) : 0.0;
                        };
                        state.resonance_white = original_white("box_resonance");
                        state.echo_white = original_white("box_echo");
                        state.liberation_white = original_white("box_liberation");
                        state.levitator_white = original_white("edge_levitator");
                        // BaseChar.is_forte_full uses a 3840x2160 hcenter box
                        // (2251,1993)-(2311,2016) and forte_white_color.
                        const double hud_scale=std::min(double(state.width)/3840.0,
                                                        double(state.height)/2160.0);
                        const ScreenBox forte_box{
                            static_cast<int>(std::round(state.width*0.5+(2251-1920)*hud_scale)),
                            state.height-static_cast<int>(std::round((2160-1993)*hud_scale)),
                            static_cast<int>(std::round(60*hud_scale)),
                            static_cast<int>(std::round(23*hud_scale))};
                        state.forte_white = color_ratio(forte_box,250,246,244);
                        const double color_scale = std::min(double(state.width)/5120.0,
                                                            double(state.height)/2880.0);
                        const ScreenBox linnai_box{
                            static_cast<int>(std::round(state.width*0.5+(2846-2560)*color_scale)),
                            state.height-static_cast<int>(std::round((2880-2602)*color_scale)),
                            static_cast<int>(std::round(43*color_scale)),
                            static_cast<int>(std::round(88*color_scale))};
                        state.linnai_color_white = color_ratio(linnai_box,250,246,244);
                        auto wide_forte_white = [&](int left, int top, int right, int bottom) {
                            const double scale = std::min(double(state.width)/5120.0,
                                                          double(state.height)/2880.0);
                            const ScreenBox box{
                                static_cast<int>(std::round(state.width*0.5+(left-2560)*scale)),
                                state.height-static_cast<int>(std::round((2880-top)*scale)),
                                static_cast<int>(std::round((right-left)*scale)),
                                static_cast<int>(std::round((bottom-top)*scale))};
                            return color_ratio(box,250,246,244);
                        };
                        state.cantarella_forte_white = wide_forte_white(3034,2640,3090,2700);
                        state.xigelika_forte_white = wide_forte_white(3032,2654,3076,2700);
                        state.luhesi_lib_white = original_white("box_luhesi_lib");
                        const auto ring = concerto.measure(pixels, state.width, state.height, channels);
                        state.concerto_coverage = ring.percent;
                        state.concerto_full = ring.full;
                        state.concerto_color_index = ring.color_index;
                        if(legacy_scan)for (int y = 0; y < state.height; ++y) {
                            int red = 0, boss = 0;
                            for (int x = 0; x < state.width; ++x) {
                                const auto* p = pixels + (y * state.width + x) * channels;
                                const bool is_red = p[2] >= 174 && p[2] <= 225 &&
                                    p[1] >= 55 && p[1] <= 85 && p[0] >= 55 && p[0] <= 76;
                                const bool is_boss = p[2] >= 245 && p[1] >= 30 && p[1] <= 185 &&
                                    p[0] >= 4 && p[0] <= 75;
                                red = is_red ? red + 1 : 0;
                                boss = is_boss ? boss + 1 : 0;
                                state.red_run = std::max(state.red_run, red);
                                if (y < 140) state.boss_run = std::max(state.boss_run, boss);
                            }
                        }
                        if(legacy_scan)for (int y = 110; y < 390; y += 2) for (int x = 1130; x < 1270; x += 2) {
                            const auto* p = pixels + (y * state.width + x) * channels;
                            state.portraits.insert(state.portraits.end(), p, p + 3);
                        }
                    }
                }
                if(!supplied_frame)image_destroy(buffer);
                return state;

    }
};

