#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Yuanwu.py
// Port source SHA256: d1c417b082a854e186bdfe7c63ebe3eb21643730b2eb85817d0d068a1fe0fa56
#include "OriginalBaseChar.h"

class Yuanwu final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (click_liberation(1)) { click_resonance(); return switch_next_char(); }
        if (state.has_intro) { continues_normal_attack(1.2); return switch_next_char(); }
        click_resonance();
        click_echo();
        switch_next_char();
    }
};
