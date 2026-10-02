#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Chisa.py
// Port source SHA256: b292bb1a6ada69bc29df61ce8f75306d068c5b8358b21cd424552720bb74091d
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Chisa.py
class ChisaOriginal final : public OriginalBaseChar {
    static constexpr double support_action_duration = 1.2;
    static constexpr double support_long_action_duration = 10.0;
    static constexpr double intro_normal_attack_duration = 2.0;
    bool perform_forte() {
        if (flying()) wait_down();
        task.send_key('E',1.2);
        if (is_forte_full()) return false;
        heavy_attack(3.5);
        return true;
    }
    void do_support_perform() {
        const bool needs_long_actions = state.has_intro && !has_buff();
        if (state.has_intro) continues_normal_attack(intro_normal_attack_duration);
        const double duration = needs_long_actions ? support_long_action_duration :
                               support_action_duration;
        if (flying() && !liberation_available() && !resonance_available()) wait_down();
        click_echo(0, 0, 0);
        const double start = task.seconds();
        while (time_elapsed_accounting_for_freeze(start) < duration && !task.stop_requested()) {
            cycle_start();
            if (is_con_full()) return switch_next_char();
            if (liberation_available()) click_liberation(-1, false, 0);
            else if (is_forte_full()) {
                if (perform_forte()) break;
            } else if (click_resonance(0, false, true, 0, false, 0).clicked) {
            } else task.click();
            cycle_sleep();
        }
        switch_next_char();
    }
    void do_dps_perform() {
        double timeout = 2.5;
        check_f_on_switch = true;
        if (state.has_intro) { continues_normal_attack(0.8); timeout = 2.3; }
        if (flying() && !liberation_available() && !resonance_available()) wait_down();
        click_echo();
        double start = task.seconds();
        bool under_liber = false;
        while (task.seconds()-start < timeout && !task.stop_requested()) {
            if (task.seconds()-start < 0.5 && click_liberation()) {
                start = task.seconds(); under_liber = true; timeout = 10; sleep(0.2);
            }
            if (task.seconds()-start < 0.5 && !is_forte_full() && click_resonance().clicked) {
                start = task.seconds();
                if (timeout != 10) timeout = 1.7;
            }
            if ((under_liber || task.chisa_dps) && is_forte_full() && perform_forte()) {
                check_f_on_switch = false;
                return switch_next_char();
            }
            task.click();
            check_combat();
            task.next_frame();
        }
        switch_next_char();
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (task.chisa_dps) do_dps_perform();
        else do_support_perform();
    }
};
