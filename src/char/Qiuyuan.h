#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Qiuyuan.py
// Port source SHA256: 34b5f8e2899e4dfeba3fdd1b16ee2d6fe4a66ac55cbafae861dd4fb9d946e014
#include "OriginalBaseChar.h"

class Qiuyuan final : public OriginalBaseChar {
    void shorekeeper_auto_dodge() {
        auto* shorekeeper = task.find_character("ShoreKeeper");
        if (shorekeeper) shorekeeper->auto_dodge([&]() { return flying(); });
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(1.17);
        if (flying()) wait_down();
        double start = task.seconds();
        const double timeout = state.has_sub_dps_intro ? 4.0 : 1.2;
        while (task.seconds() - start < timeout && !task.stop_requested()) {
            click_echo(0, 0, 0);
            if (task.seconds() - start < 0.5 && click_liberation()) start = task.seconds();
            if (heavy_click_forte([&]() { return is_mouse_forte_full(); })) return switch_next_char();
            if (flying() && !is_mouse_forte_full()) shorekeeper_auto_dodge();
            if (!task.click()) throw std::runtime_error("Maa Qiuyuan click failed");
            check_combat();
            task.next_frame();
        }
        click_resonance();
        switch_next_char();
    }
};
