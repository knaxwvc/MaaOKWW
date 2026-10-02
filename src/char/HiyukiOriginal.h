#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Hiyuki.py
// Port source SHA256: 66fbe3804e12d37902546bacad4581b0283fd952b6c9d8605d9ca87a363e788e
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Hiyuki.py
class HiyukiOriginal final : public OriginalBaseChar {
    static constexpr double field_time_out = 16;
    static constexpr double linnai_field_time_out = 18;
    static constexpr double hold_lib_time_out = 8;
    static constexpr double standard_lib_cd_max = 3.5;
    static constexpr double intro_normal_attack_time = 1;
    static constexpr double post_res_normal_attack_time = 0.3;
    static constexpr double post_lib_settle = 0.5;
    static constexpr int lib2_kendo_count = 4;
    static constexpr double hold_lib_cd_wait = 1.5;
    static constexpr double wait_lock_time_out = 2;
    bool lib_permission = true;
    int lib2_count = 0;
    double field_timeout() const {
        return state.has_intro && check_outro() == "Linnai" ?
               linnai_field_time_out : field_time_out;
    }
    bool lib_heavy_available() { return find_feature("hiyuki_lib_forte", 0.7); }
    bool wait_locked(double timeout) {
        return wait_until([&]() { return has_long_action2(); }, timeout,
                          [&]() { task.click(); });
    }
    bool hold_liberation() {
        if (!task.use_liberation) return false;
        const double start = task.seconds();
        double last_click = 0;
        bool pressed = false;
        try {
            while (task.active_slot() > 0 &&
                   (liberation_available() || task.cooldown_remaining('R') <= hold_lib_cd_wait) &&
                   task.seconds()-start < hold_lib_time_out && !task.stop_requested()) {
                if (task.seconds()-start > last_click) {
                    if (!task.key_down('R')) throw std::runtime_error("Maa Hiyuki R down failed");
                    pressed = true;
                    last_click += 0.2;
                }
                sleep(0.05);
            }
        } catch (...) { if (pressed) task.key_up('R'); throw; }
        task.in_liberation=true;
        if (!task.key_up('R')) throw std::runtime_error("Maa Hiyuki R up failed");
        wait_until([&]() { return task.active_slot() > 0; }, 3);
        task.in_liberation=false;
        if (task.add_freeze_duration)
            task.add_freeze_duration(start, task.seconds()-start, 0.1);
        return true;
    }
    void perform_standard() {
        const double timeout = field_timeout();
        while (has_long_action() &&
               time_elapsed_accounting_for_freeze(last_perform) < timeout &&
               !task.stop_requested()) {
            click_echo(0, 0, 0);
            click_resonance(0, false, false, 0, false, 0);
            if (liberation_available() && click_liberation()) return;
            if (is_mouse_forte_full()) {
                task.right_click();
                heavy_click_forte([&]() { return is_mouse_forte_full(); });
                wait_until([&]() { return liberation_available(); }, field_time_out,
                           [&]() { task.click(0.1); });
                if (click_liberation()) return;
            } else task.click(0.1);
            sleep(0.05);
        }
    }
    bool perform_lib() {
        const double start = task.seconds();
        const double timeout = field_timeout();
        bool is_timeout = false;
        while (has_long_action2() && time_elapsed_accounting_for_freeze(start) < timeout &&
               !task.stop_requested()) {
            f_break();
            click_echo(0, 0, 0);
            (void)lib_heavy_available();
            is_timeout = time_elapsed_accounting_for_freeze(start) >= timeout-0.5;
            if (lib_permission && liberation_available() &&
                (lib2_count >= lib2_kendo_count || is_timeout)) {
                if (hold_liberation()) { lib2_count = 0; return true; }
            }
            const auto resonance = click_resonance(0, false, false, 0, false, 0);
            if (resonance.clicked) {
                if (is_timeout) break;
                continues_normal_attack(post_res_normal_attack_time);
            } else if (lib_heavy_available()) {
                if (is_timeout) break;
                if (wait_locked(wait_lock_time_out))
                    heavy_click_forte([&]() { return lib_heavy_available(); });
                if (wait_until([&]() { return liberation_available(); }, 0.5,
                               [&]() { task.click(); })) {
                    if (wait_locked(wait_lock_time_out) && hold_liberation()) {
                        lib2_count = 0; return true;
                    }
                }
                ++lib2_count;
                sleep(0.1);
            } else if (find_feature("hiyuki_left", 0.5)) {
                wait_until([&]() { return !find_feature("hiyuki_left", 0.5); }, 3,
                           [&]() { task.click(); });
                if (is_timeout) break;
                sleep(0.1);
            } else if (find_feature("hiyuki_right", 0.5)) {
                task.right_click(1.0);
                sleep(0.1);
            } else task.click();
            sleep(0.05);
        }
        if (lib_permission && liberation_available() && hold_liberation()) {
            lib2_count = 0; return true;
        }
        return false;
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && (from=="Linnai" || from=="Lucilla"))return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void on_switch_out(bool, double) override { lib2_count = 0; }
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(intro_normal_attack_time);
        if (has_long_action() && task.cooldown_remaining('R') <= standard_lib_cd_max)
            perform_standard();
        if (has_long_action2()) {
            if (perform_lib() || (lib_permission && liberation_available() && hold_liberation())) {
                sleep(post_lib_settle);
                return switch_next_char();
            }
        }
        switch_next_char();
    }
};
