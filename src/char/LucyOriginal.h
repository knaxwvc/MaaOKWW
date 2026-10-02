#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Lucy.py
// Port source SHA256: cb4bc26a2c72b77feaeb945ea17b1fad908e76e2cb081f65f581978d2ec4e4e2
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Lucy.py
class LucyOriginal final : public OriginalBaseChar {
    void perform_standard() {
        if (is_forte_full()) return;
        const double start = task.seconds();
        while (!is_forte_full() && task.seconds()-start <= 8.5 && !task.stop_requested()) {
            if (resonance_available()) click_resonance();
            heavy_attack(0.4);
            if (resonance_available()) click_resonance();
        }
        continues_normal_attack(0.1);
    }
    void perform_enhanced_heavy() {
        if (!is_mouse_forte_full()) return;
        heavy_attack(0.4);
        sleep(0.2,false);
        heavy_attack(0.4);
    }
    void perform_liberation() {
        if (resonance_available()) click_resonance();
        f_break();
        perform_enhanced_heavy();
        if (!is_mouse_forte_full()) {
            const double start = task.seconds();
            while (!is_mouse_forte_full() && task.seconds()-start < 6 && !task.stop_requested()) {
                task.click(); sleep(0.1); task.next_frame();
            }
        }
        if (is_mouse_forte_full()) {
            if (!task.mouse_down()) throw std::runtime_error("Maa Lucy heavy down failed");
            try {
                const double press_start = task.seconds();
                while (task.seconds()-press_start < 2.5 && !task.stop_requested()) {
                    raw_sleep(0.05); task.next_frame();
                }
            } catch (...) { task.mouse_up(); throw; }
            if (!task.mouse_up()) throw std::runtime_error("Maa Lucy heavy up failed");
            sleep(0.1);
            const double wait_start=task.seconds();
            bool liber_after=liberation_available();
            while(task.seconds()-wait_start<2 && !liber_after && !task.stop_requested()){
                raw_sleep(0.1);liber_after=liberation_available();task.next_frame();
            }
            if (echo_available()) click_echo(0, 0, 0);
        } else if (echo_available()) click_echo(0, 0, 0);
        if (liberation_available()) {
            click_liberation(-1, true, 1.5);
            last_liberation = task.seconds();
            state.last_liberation = last_liberation;
            for (int i=0; i<11 && !task.stop_requested(); ++i) {
                task.click(); sleep(0.1,false);
            }
        }
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && from=="Rebecca")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        try { f_break(); } catch (...) {}
        if (!is_forte_full()) perform_standard();
        perform_liberation();
        switch_next_char();
    }
};
