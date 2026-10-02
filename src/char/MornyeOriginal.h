#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Mornye.py
// Port source SHA256: af8ccf62850004d51a8e8f4b0ca1dcc640b8e86597c3013585de055aeddd2de4
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Mornye.py
class MornyeOriginal final : public OriginalBaseChar {
    double last_heavy = -10000;
    bool on_air() { return has_long_action2(); }
    bool detect_elbow_strike(bool ready) { return ready && !available('Q', true); }
    bool combo_limit() { return time_elapsed_accounting_for_freeze(last_heavy) < 23; }
    void not_on_air_actions() {
        const double start = task.seconds();
        bool try_dodge = true;
        while (task.seconds()-start < 10 && !on_air() && !task.stop_requested()) {
            task.click();
            click_resonance();
            check_combat();
            sleep(0.1);
            if (is_mouse_forte_full()) {
                if (try_dodge) { task.right_click(); try_dodge = false; }
                heavy_attack();
                sleep(0.3);
            }
        }
    }
    void on_air_actions() {
        const bool detect_ready = echo_available();
        const double start = task.seconds();
        while (task.seconds()-start < 10 && on_air() && !task.stop_requested()) {
            if (detect_elbow_strike(detect_ready))
                wait_until([&]() { return !detect_elbow_strike(detect_ready); }, 1.5,
                           [&]() { continues_right_click(0.05); });
            click_liberation();
            if (on_air() && is_mouse_forte_full()) {
                if (heavy_click_forte([&]() {
                    return is_mouse_forte_full() && !detect_elbow_strike(detect_ready);
                })) {
                    if (detect_elbow_strike(detect_ready)) continue;
                    if (!wait_until([&]() { return is_con_full(); }, 1.5)) {
                        const double fill_start = task.seconds();
                        while (!is_con_full() && task.seconds()-fill_start < 2 &&
                               on_air() && !task.stop_requested()) {
                            continues_normal_attack(0.5);
                            if (detect_elbow_strike(detect_ready)) break;
                        }
                        if (!is_con_full()) click_echo(0.2);
                    }
                    last_heavy = task.seconds();
                    check_f_on_switch = false;
                    break;
                }
            }
            click_resonance();
            task.click();
            sleep(0.01);
        }
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && (from=="Aemeath" || from=="Qingxiao"))return 400;
        if(has_intro && current && task.find_character("Linnai") && from!="Linnai")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(1.33);
        check_f_on_switch = true;
        if (!on_air()) {
            if (combo_limit()) {
                if (click_echo() || click_resonance().clicked) return switch_next_char();
                continues_normal_attack(0.1);
                return switch_next_char();
            }
            not_on_air_actions();
        }
        if (on_air()) on_air_actions();
        switch_next_char();
    }
};
