#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Mortefi.py
// Port source SHA256: ae95f94ab840573912f9fbf9712fa141d845c499a8b369154ee0a999c0f6de9f
#include "OriginalBaseChar.h"

class Mortefi final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        wait_down();
        const bool liberated = click_liberation();
        click_resonance();
        click_echo();
        if (!liberated) click_liberation(-1, false, 1);
        switch_next_char();
    }
};
