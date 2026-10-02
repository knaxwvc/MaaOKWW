#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Danjin.py
// Port source SHA256: 296bd3babc3b4304a3fea25854cb6e5856cacb53e22d6befb1ccd883e3f35cc9
#include "OriginalBaseChar.h"

class Danjin final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (click_liberation()) {
            sleep(1.2);
            click_echo(0, 0, 2);
            return switch_next_char();
        }
        if (is_forte_full() && state.has_intro) {
            heavy_attack(0.8);
            sleep(0.2);
            normal_attack();
            sleep(0.1);
            return switch_next_char();
        }
        if (state.has_intro) continues_normal_attack(1.1);
        else { wait_down(); continues_normal_attack(0.4, 0.1); }
        continues_click('E', 1.1, 0.2);
        switch_next_char();
    }
};
