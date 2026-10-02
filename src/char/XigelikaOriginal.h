#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Xigelika.py
// Port source SHA256: 41e04be60c4561156634404f0158566d6be0ac84fa01aea5107ec02ea28b231a
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Xigelika.py
class XigelikaOriginal final : public OriginalBaseChar {
    bool is_forte_full() override { return task.frame().xigelika_forte_white > 0.1; }
    bool lib() {
        if (!click_liberation(-1, false, 0)) return false;
        f_break();
        return true;
    }
    bool heavy_wait_highlight_down() {
        const bool use_mouse = has_long_action();
        if (use_mouse) {
            if (!task.mouse_down()) throw std::runtime_error("Maa Xigelika heavy down failed");
        } else {
            if (has_cd('E')) { task.click(0.1); sleep(0.05); return false; }
            if (!task.key_down('E')) throw std::runtime_error("Maa Xigelika E down failed");
        }
        bool result = false;
        try {
            result = wait_until([&]() { return use_mouse ? !has_long_action() : !is_forte_full(); }, 1.2);
        } catch (...) {
            if (use_mouse) task.mouse_up(); else task.key_up('E');
            throw;
        }
        if (use_mouse) task.mouse_up(); else task.key_up('E');
        sleep(0.01);
        return result;
    }
    bool handle_heavy() {
        bool handled = false;
        const double start = task.seconds();
        while (is_forte_full() && time_elapsed_accounting_for_freeze(start) < 3 &&
               !task.stop_requested()) {
            heavy_wait_highlight_down();
            handled = true;
        }
        return handled;
    }
    void shorekeeper_auto_dodge() {
        auto* shorekeeper = task.find_character("ShoreKeeper");
        if (shorekeeper) shorekeeper->auto_dodge([&]() { return flying(); });
    }
    void perform_everything() {
        double start = task.seconds();
        double timeout = state.has_sub_dps_intro ? 15 : 0.5;
        while (time_elapsed_accounting_for_freeze(start) < timeout && !task.stop_requested()) {
            click_echo(0, 0, 0);
            if (flying()) shorekeeper_auto_dodge();
            if (handle_heavy()) return;
            if (!state.has_intro && lib()) { timeout = 15; start = task.seconds(); }
            else if (click_resonance(0, false, false, 0, false, 2).clicked) {
            } else task.click(0.1);
            sleep(0.05);
        }
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(0.77);
        else wait_down();
        perform_everything();
        switch_next_char();
    }
};
