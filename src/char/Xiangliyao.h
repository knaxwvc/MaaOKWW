#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Xiangliyao.py
// Port source SHA256: 13c25587cc5541306ac8e048bb4bf09731a7f43cee28878702c0b3f07c75ef28
#include "OriginalBaseChar.h"

class Xiangliyao final : public OriginalBaseChar {
    double liberation_time = -10000;
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        wait_down();
        if (click_liberation()) liberation_time = task.seconds();
        if (time_elapsed_accounting_for_freeze(liberation_time) < 25) {
            while (!click_resonance().clicked && !task.stop_requested())
                continues_normal_attack(1);
        } else if (echo_available()) click_echo();
        else click_resonance();
        switch_next_char();
    }
};
