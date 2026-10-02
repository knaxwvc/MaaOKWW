#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Sanhua.py
// Port source SHA256: 162b40dede895c2e586498ecf8f21ca07ad453b4626f82db520f3b8fea41c75f
#include "OriginalBaseChar.h"

class Sanhua final : public OriginalBaseChar {
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        bool liber_clicked = false;
        double sleep_time = 0.85;
        sleep(0.02);
        double start = task.seconds();
        if (!task.mouse_down()) throw std::runtime_error("Maa Sanhua mouse down failed");
        try {
            wait_down(false);
            if (click_liberation()) {
                liber_clicked = true;
                sleep_time += 0.1;
                sleep(0.15,false);
            } else if (resonance_available()) {
                task.mouse_up();
                click_resonance(0, false, false);
                start = task.seconds();
                task.mouse_down();
                sleep(0.1,false);
            }
            sleep_time -= time_elapsed_accounting_for_freeze(start);
            if (sleep_time > 0) sleep(sleep_time,false);
        } catch (...) {
            task.mouse_up();
            throw;
        }
        if (!task.mouse_up()) throw std::runtime_error("Maa Sanhua mouse up failed");
        sleep(0.8);
        if (liber_clicked) { click_resonance(0, false, false); sleep(0.3); }
        if (is_con_full()) click_echo();
        switch_next_char();
    }
};
