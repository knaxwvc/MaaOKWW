#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Jiyan.py
// Port source SHA256: 13a5d3b4db73f91e856f72179e9794777c1e5021e04a8fb25e5133983d97f470
#include "OriginalBaseChar.h"

class Jiyan final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(2.0);
        if (click_liberation()) {
            const double start = task.seconds();
            while (task.seconds() - start < 12 && !task.stop_requested()) {
                if (click_resonance().clicked) task.middle_click();
                normal_attack();
            }
            return switch_next_char();
        }
        int i = 0;
        while (!is_forte_full() && !is_con_full() && !task.stop_requested()) {
            if (i % 4 == 0) {
                heavy_attack();
                if (resonance_available() || echo_available()) {
                    task.middle_click();
                    break;
                }
                i = 0;
            }
            normal_attack();
            ++i;
        }
        if (!is_forte_full() && resonance_available()) click_resonance(1.0);
        if (echo_available()) click_echo();
        switch_next_char();
    }
};
