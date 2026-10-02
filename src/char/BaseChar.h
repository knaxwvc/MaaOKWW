#pragma once
#include <array>
#include <functional>

struct RoleState {
    double last_e = -100;
    double last_q = -100;
    double last_r = -100;
    double last_heavy = -100;
    bool linnai_heavy = false;
    int linnai_followup = 0;
    bool lucilla_transformed = false;
    bool lucilla_con_seen = false;
    double lucilla_transform_end = -1;
    bool mornye_waiting_con = false;
    double mornye_con_wait_start = -1;
    bool mornye_dodge_sent = false;
    bool mornye_echo_ready_start = false;
    bool has_intro = false;
    bool has_all_buff = false;
    int hiyuki_kendo_count = 0;
    int hiyuki_mode = 0;
    double hiyuki_post_res_until = -1;
    int chisa_forte_stage = 0;
    double last_lib2 = -100;
};

struct CombatOps {
    const FrameState& frame;
    double now;
    int tick;
    int phase_elapsed_ms;
    RoleState& state;
    bool& denia_lib1_casted;
    bool target_locked;
    std::function<double()> seconds;
    std::function<bool(int, double, const char*)> cast;
    std::function<bool(const char*, int, int, int, int, double)> match;
    std::function<bool(int, int)> heavy;
    std::function<bool(int, int)> hold_key;
    std::function<bool(int)> hold_liberation;
    std::function<bool()> click;
    std::function<bool()> right_click;
    std::function<bool(int)> send_key;
    std::function<double(char)> cooldown_remaining;
    std::function<bool()> stop_requested;

    bool feature(const char* name, int x, int y, int width, int height,
                 double threshold = 0.7) {
        return match(name, x, y, width, height, threshold);
    }
};

