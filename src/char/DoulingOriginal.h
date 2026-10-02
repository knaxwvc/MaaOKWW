#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Douling.py
// Port source SHA256: d95db938cd5de4f578c8db8263feaf332e858d679e4c19300b20e85454d0de94
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Douling.py
class DoulingOriginal final : public OriginalBaseChar {
    int segment = 1;
    void normal_attack_cycle(double duration) {
        const double start = task.seconds();
        while (task.seconds()-start < duration && !task.stop_requested()) {
            cycle_start();
            if (flying()) { wait_down(); break; }
            task.click();
            cycle_sleep();
        }
    }
    void heavy_attack_hold(double duration) {
        for (int retry = 0; retry < 3 && !task.stop_requested(); ++retry) {
            check_combat();
            if (!task.mouse_down()) throw std::runtime_error("Maa Douling heavy down failed");
            bool interrupted = false;
            const double start = task.seconds();
            try {
                while (task.seconds()-start < duration && !task.stop_requested()) {
                    if (flying()) { interrupted = true; break; }
                    sleep(0.1);
                }
            } catch (...) { task.mouse_up(); throw; }
            if (!task.mouse_up()) throw std::runtime_error("Maa Douling heavy up failed");
            sleep(0.01);
            if (!interrupted) return;
            wait_down();
        }
    }
    void finish_and_reset() {
        click_echo(0, 0, 0); click_liberation();
        segment = 1; switch_next_char();
    }
    void segment1() {
        normal_attack_cycle(1.2);
        if (flying()) wait_down();
        check_combat();
        if (!click_resonance(0, false, true, 0, false, 0.5).clicked)
            return finish_and_reset();
        sleep(0.2);
        if (flying()) wait_down();
        check_combat();
        normal_attack_cycle(1.0);
        segment = 2; switch_next_char();
    }
    void segment2() {
        check_combat();
        task.send_key(0x20); sleep(0.01); sleep(0.05);
        check_combat();
        if (flying()) { task.click(); sleep(0.05); }
        else wait_down();
        check_combat();
        heavy_attack_hold(2.5);
        click_echo(0, 0, 0); click_liberation();
        segment = 1; switch_next_char();
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        return time_elapsed_accounting_for_freeze(last_perform)<8?0:200;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override { if (segment == 1) segment1(); else segment2(); }
};
