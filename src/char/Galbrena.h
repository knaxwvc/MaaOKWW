#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Galbrena.py
// Port source SHA256: fc7aba89e26bd4550d155da6592bb4e99ee779ade1f95033630631ff5ae0949a
#include "OriginalBaseChar.h"

class Galbrena final : public OriginalBaseChar {
    bool check_res() {
        if (task.active_slot() < 0) return false;
        return task.feature_in_box("has_target", "box_target_enemy_long", 0.6) ||
               task.feature_in_box("no_target", "box_target_enemy_long", 0.6);
    }
    void shorekeeper_auto_dodge() {
        auto* shorekeeper = task.find_character("ShoreKeeper");
        if (shorekeeper) shorekeeper->auto_dodge([&]() { return flying(); });
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) {
            if (!task.mouse_down()) throw std::runtime_error("Maa Galbrena mouse down failed");
            try {
                sleep(1);
                if (need_fast_perform()) {
                    task.mouse_up();
                    return switch_next_char();
                }
                sleep(0.44);
            } catch (...) { task.mouse_up(); throw; }
            if (!task.mouse_up()) throw std::runtime_error("Maa Galbrena mouse up failed");
            continues_right_click(0.6);
        } else if (flying()) wait_down();
        click_echo(0, 0, 0);
        if (is_forte_full() && !need_fast_perform()) {
            click_resonance();
            if (click_liberation()) continues_normal_attack(1);
        }
        if (check_res() && !need_fast_perform()) {
            click_liberation();
            const double start = task.seconds();
            while (check_res() && task.seconds() - start < 10 && !task.stop_requested()) {
                if (flying()) shorekeeper_auto_dodge();
                if (!task.click()) throw std::runtime_error("Maa Galbrena click failed");
                sleep(0.1);
                check_combat();
            }
            return switch_next_char();
        }
        continues_normal_attack(1);
        click_resonance();
        switch_next_char();
    }
};
