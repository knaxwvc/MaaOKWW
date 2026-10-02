#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Taoqi.py
// Port source SHA256: ec447aa3b4eef65fcc304f9f9f296eb5134cb9d496cf932037fd22a38c3e3ca9
#include "OriginalBaseChar.h"

class Taoqi final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) { wait_down(); continues_normal_attack(2.5); }
        else { click_liberation(); click_resonance(); click_echo(0, 0.1); }
        switch_next_char();
    }
};
