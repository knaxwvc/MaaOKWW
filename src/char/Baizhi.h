#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Baizhi.py
// Port source SHA256: 80d7c23797087f0684c7cf7079aa9c24dd9f58a1a5ddb27da4b88a91fc56ecbf
#include "OriginalBaseChar.h"

class Baizhi final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(1.2, 0.1, 0, true);
        click_liberation(1);
        click_resonance();
        click_echo();
        switch_next_char();
    }
};
