#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Luhesi.py
// Port source SHA256: d3e77331aa2c98c16036d0ed7ab65d71c96a4de4b6a7e31570eff4e5b3fc016e
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Luhesi.py
class LuhesiOriginal final : public OriginalBaseChar {
    bool luhesi_lib_available() {
        return task.frame().luhesi_lib_white > 0 && !has_cd('R');
    }
    bool lib() {
        if (!luhesi_lib_available() || !click_liberation(-1, false, 0)) return false;
        f_break();
        return true;
    }
    bool detect_elbow_strike(bool ready) { return ready && !available('Q', true); }
    bool check_res() {
        return task.active_slot() > 0 &&
            (find_feature_in_box("has_target", "target_box_long2", 0.6) ||
             find_feature_in_box("no_target", "target_box_long2", 0.6));
    }
    bool handle_heavy(int res_count) {
        const double start = task.seconds();
        bool have_kick = false;
        while (find_feature("luhesi_kick", 0.7) && task.seconds()-start < 3 &&
               !task.stop_requested()) {
            have_kick = true;
            if (res_count < 3) f_break();
            task.click(); sleep(0.1);
        }
        return have_kick;
    }
    void perform_everything() {
        continues_normal_attack(1.1);
        if (!state.has_sub_dps_intro) { send_resonance_key(0.1); return; }
        state.last_intro = task.seconds();
        if (!flying()) wait_until([&]() { return flying(); }, 0.2,
                                  [&]() { task.jump(); });
        const bool detect_ready = echo_available();
        const double start = task.seconds();
        int res_count = 0;
        bool try_jump = false;
        while (time_elapsed_accounting_for_freeze(start) < 12 && !task.stop_requested()) {
            if (detect_elbow_strike(detect_ready)) {
                wait_until([&]() { return !detect_elbow_strike(detect_ready); }, 1.5,
                           [&]() { continues_right_click(0.05); });
            } else if (handle_heavy(res_count) && res_count > 2) {
                lib(); return;
            } else if (try_jump && !check_res()) {
                wait_until([&]() { return find_feature("luhesi_kick", 0.7) ||
                                           detect_elbow_strike(detect_ready); }, 1,
                           [&]() { send_resonance_key(); });
                if (detect_elbow_strike(detect_ready)) continue;
                try_jump = false;
                if (find_feature("luhesi_kick", 0.7)) ++res_count;
                else { if (res_count == 2) wait_down(); lib(); return; }
            } else if (check_res()) {
                task.jump(); try_jump = true;
            } else task.click();
            sleep(0.01);
        }
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(task.seconds()-state.last_intro>24 && has_intro)return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override { perform_everything(); switch_next_char(); }
};
