#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Jianxin.py
// Port source SHA256: 9078752d79b735f71ff43a0681a3b85e1d871b670262d46b398c35ff8603b45a
#include "OriginalBaseChar.h"

class Jianxin final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(1);
        click_liberation();
        if (resonance_available()) click_resonance();
        if (echo_available()) click_echo();
        switch_next_char();
    }
};
