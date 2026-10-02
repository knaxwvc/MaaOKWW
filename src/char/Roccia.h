#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Roccia.py
// Port source SHA256: 04ebe3bc301fbf4733ba3e7317ac480ad095d7bbb72724476090506a855b9bd1
#include "OriginalBaseChar.h"

class Roccia final : public OriginalBaseChar {
    int plunge_count = 0;
    double last_e = 0;
    double last_intro = 0;
    bool can_plunge = false;
    void switch_with_toolbox() {
        switch_next_char();
        if (task.last_switch_had_intro()) {
            auto* next = task.member_at(task.active_slot());
            if (next) next->has_tool_box = true;
        }
    }
    bool plunge() {
        if (need_fast_perform()) { normal_attack_until_can_switch(); return false; }
        double start = task.seconds();
        if (!task.key_down('W')) throw std::runtime_error("Maa Roccia W down failed");
        try {
            while (is_mouse_forte_full() && task.seconds() - start < 6 && !task.stop_requested()) {
                if (task.seconds() - start > 2 && !has_cd('E') && !has_cd('R')) {
                    if (click_liberation()) {
                        click_resonance();
                        start = task.seconds();
                        continue;
                    }
                }
                task.click(0.1);
            }
        } catch (...) { task.key_up('W'); throw; }
        if (!task.key_up('W')) throw std::runtime_error("Maa Roccia W up failed");
        return true;
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) {
            heavy_attack(1.6);
            sleep(0.1);
            last_intro = task.seconds();
            plunge();
            if (!liberation_available() && !resonance_available()) return switch_with_toolbox();
        }
        const bool liberated = click_liberation();
        if (click_resonance().clicked || !liberated) {
            plunge();
            return switch_with_toolbox();
        }
        click_echo();
        switch_with_toolbox();
    }
};
