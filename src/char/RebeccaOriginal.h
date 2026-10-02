#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Rebecca.py
// Port source SHA256: eecf6992571363f8d0f0fb1d90f0aeffd4450b18b030e37040275761344de7d4
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Rebecca.py
class RebeccaOriginal final : public OriginalBaseChar {
    double last_liberation_at = -999;
    bool in_reenter_window() const { return task.seconds()-last_liberation_at < 17; }
    void perform_hmg_mode() {
        const double enter_start = task.seconds();
        while (task.seconds()-enter_start < 0.8 && !task.stop_requested()) {
            if (!send_liberation_key()) throw std::runtime_error("Maa Rebecca R failed");
            sleep(0.1,false);
        }
        last_liberation = task.seconds();
        state.last_liberation = last_liberation;
        const double start = task.seconds();
        double last_liberation_press = task.seconds();
        while (task.seconds()-start < 5.2 && !task.stop_requested()) {
            task.click(0.08);
            if (task.seconds()-last_liberation_press > 0.9) {
                send_liberation_key(); last_liberation_press = task.seconds();
            }
            sleep(0.01,false);
        }
        last_liberation_at = task.seconds();
    }
    void build_forte_sequence() {
        continues_normal_attack(state.has_intro ? 1.3 : 1.8);
        wait_until([&]() { return resonance_available(); }, 2);
        const int count = state.has_intro ? 2 : 3;
        for (int i = 0; i < count; ++i) click_resonance(i == count-1 && count == 3 ? 1 : 1.5);
        send_resonance_key();
        const double start = task.seconds();
        while (!is_mouse_forte_full() && task.seconds()-start < 4 && !task.stop_requested()) {
            task.click(); sleep(0.1); task.next_frame();
        }
        if (is_mouse_forte_full()) heavy_attack(1.5);
        click_echo();
        perform_hmg_mode();
    }
public:
    RebeccaOriginal(OriginalCombatIO& io, OriginalSwitchCharacter& member)
        : OriginalBaseChar(io, member) { check_f_on_switch = false; }
    void do_perform() override {
        if (in_reenter_window()) {
            click_resonance();
            continues_normal_attack(0.5);
        } else build_forte_sequence();
        if (in_reenter_window()) {
            const double start = task.seconds();
            while (!is_con_full() && task.seconds()-start < 2.2 && !task.stop_requested()) {
                continues_normal_attack(1.0); raw_sleep(0.1);
            }
        }
        switch_next_char();
    }
};
