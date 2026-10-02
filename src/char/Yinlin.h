#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Yinlin.py
// Port source SHA256: dfc01544b6da492763e9ce2ff854d5806c2f9ab3ef1bf2961468c876ad019396
#include "OriginalBaseChar.h"

class Yinlin final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) sleep(0.4);
        const bool liberation = click_liberation();
        if (is_mouse_forte_full()) {
            if (!state.has_intro && !liberation) normal_attack();
            heavy_attack();
            sleep(0.4);
        } else if (click_resonance(0, false, false).clicked) sleep(0.1);
        else if (echo_available()) click_echo();
        else heavy_attack();
        switch_next_char();
    }
};
