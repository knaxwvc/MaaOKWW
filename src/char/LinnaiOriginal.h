#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Linnai.py
// Port source SHA256: b73576f00e90bf1044f7febb9be7458422cc0f9f1da96a257f42a771b721b67a
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Linnai.py
class LinnaiOriginal final : public OriginalBaseChar {
    static constexpr double res_check_threshold = 0.6;
    static constexpr double intro_res_wait = 1.0;
    static constexpr double aemeath_intro_res_wait = 1.6;
    static constexpr double aemeath_outro_recovery = 3.0;
    bool target_status_in_box(std::string_view box) {
        return find_feature_in_box("has_target", box, res_check_threshold) ||
               find_feature_in_box("no_target", box, res_check_threshold);
    }
    bool check_res() {
        if (task.active_slot() <= 0) return false;
        return target_status_in_box("target_box_long2") ||
               target_status_in_box("box_target_enemy_long") ||
               find_feature("target_box_short", res_check_threshold);
    }
    bool is_color_full() { return task.frame().linnai_color_white > 0.06; }
    bool wait_for_accelerate_ready() {
        if (check_res()) return true;
        const double timeout = state.has_intro && check_outro() == "Aemeath" ?
                               aemeath_intro_res_wait : intro_res_wait;
        return wait_until([&]() { return check_res(); }, timeout,
                          [&]() { task.click(0.1); });
    }
    void wait_after_resonance_kick() { sleep(0.3); wait_down(); }
    bool perform_under_intro() {
        if (!wait_for_accelerate_ready()) return false;
        wait_until([&]() { return is_color_full() || is_con_full(); }, 1,
                   [&]() { task.click(); });
        if (wait_until([&]() { return !is_forte_full(); }, 3,
                       [&]() { task.jump(); })) {
            if (wait_until([&]() { return click_resonance().clicked; }, 2,
                           [&]() { task.click(); })) {
                wait_after_resonance_kick();
                bool second_kick = false;
                wait_until([&]() {
                    if (is_con_full()) return true;
                    second_kick = click_resonance().clicked;
                    return second_kick;
                }, 3, [&]() { task.click(); });
                if (second_kick) wait_after_resonance_kick();
            }
        }
        if (!is_con_full() && click_liberation())
            wait_until([&]() { return is_con_full(); }, 1.2,
                       [&]() { task.click(0.1); });
        return true;
    }
    bool charge_heavy() {
        continues_normal_attack(1);
        click_echo(0, 0, 0);
        if (!is_con_full()) click_liberation();
        if (!is_mouse_forte_full()) click_resonance();
        if (!wait_until([&]() { return is_mouse_forte_full(); }, 2,
                        [&]() { task.click(); })) return false;
        if (!task.mouse_down()) throw std::runtime_error("Maa Linnai heavy down failed");
        bool consumed = false;
        try { consumed = wait_until([&]() { return !is_mouse_forte_full(); }, 5); }
        catch (...) { task.mouse_up(); throw; }
        if (!task.mouse_up()) throw std::runtime_error("Maa Linnai heavy up failed");
        if (!consumed) return false;
        sleep(0.4);
        return perform_under_intro();
    }
    void finish_aemeath_handoff() {
        if (!task.find_character("Aemeath")) return;
        bool buffed_healer = false;
        for (int slot = 1; slot <= 3; ++slot) {
            const auto* member = task.member_at(slot);
            if (member && member != &state && member->is_healer() &&
                member->has_buff(task.seconds())) buffed_healer = true;
        }
        if (buffed_healer && !is_con_full())
            continues_normal_attack(aemeath_outro_recovery, 0.1, 0, false, true);
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(from=="Mornye")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro && check_res()) continues_normal_attack(1.33);
        else charge_heavy();
        if (liberation_available()) click_liberation();
        finish_aemeath_handoff();
        switch_next_char();
    }
};
