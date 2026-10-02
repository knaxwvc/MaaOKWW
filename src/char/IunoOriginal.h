#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Iuno.py
// Port source SHA256: b25c5bb96ad7d5461036efe3af508e400ce84b859e7f2da8339b77bca38b676c
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Iuno.py
class IunoOriginal final : public OriginalBaseChar {
    double last_heavy = -10000;
    bool do_everything(double timeout = 1.5) {
        if (state.has_intro) timeout += 4;
        double start = task.seconds();
        bool last_action_click = true;
        click_echo();
        bool c6_performed = false, jumped = false;
        while (time_elapsed_accounting_for_freeze(start) < timeout && !task.stop_requested()) {
            const double cycle_started = task.seconds();
            bool heavy_success = false;
            while (time_elapsed_accounting_for_freeze(last_heavy) > 20 &&
                   find_feature_in_box("iuno_heavy", "box_extra_action", 0.6) &&
                   !task.stop_requested()) {
                sleep(0.05); heavy_attack(); sleep(0.05); heavy_success = true;
            }
            if (heavy_success) {
                last_heavy = task.seconds();
                if (!c6_performed && task.iuno_c6) {
                    c6_performed = true; start = task.seconds(); timeout = 5;
                } else return true;
            }
            if (!jumped && find_feature_in_box("iuno_jump", "box_extra_action", 0.6)) {
                while (find_feature_in_box("iuno_jump", "box_extra_action", 0.6) &&
                       !task.stop_requested()) { task.jump(0.1); }
                timeout += 3;
                jumped = true;
                if (state.has_intro) continue;
                return false;
            }
            if (time_elapsed_accounting_for_freeze(last_liberation) > 20 &&
                click_liberation(-1, false, 0)) {
                start = task.seconds(); timeout = 3;
            }
            if (last_action_click) send_resonance_key();
            else task.click();
            last_action_click = !last_action_click;
            sleep(std::max(0.0, 0.1-(task.seconds()-cycle_started)));
        }
        return false;
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override { wait_down(); do_everything(); switch_next_char(); }
};
