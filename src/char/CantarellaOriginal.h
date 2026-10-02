#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Cantarella.py
// Port source SHA256: 268196b005e3c969690b3e2bf509e28eaede1bc0c8e514ab3d9f4cb8c8a0cc44
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Cantarella.py
class CantarellaOriginal final : public OriginalBaseChar {
    double last_heavy = -1;
    bool is_forte_full() override { return task.frame().cantarella_forte_white > 0.06; }
    bool resonance_available() override {
        if(!is_mouse_forte_full() && is_forte_full())return !has_cd('E');
        return OriginalBaseChar::resonance_available();
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && (from=="Roccia" || from=="Sanhua"))return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void on_combat_end() override {task.send_key('0'+(state.index+1)%task.team_size()+1);}
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        bool perform_under_outro = false;
        if (state.has_intro) {
            continues_normal_attack(1.2);
            const auto outro = check_outro();
            if (state.has_sub_dps_intro && (outro == "Roccia" || outro == "Sanhua"))
                perform_under_outro = true;
        }
        click_liberation();
        if (is_mouse_forte_full() || !is_forte_full()) {
            click_resonance();
            if (perform_under_outro && flying()) wait_down();
            if (!flying() && is_mouse_forte_full()) {
                if (heavy_click_forte([&]() { return is_mouse_forte_full(); }))
                    last_heavy = task.seconds();
            } else if (click_echo()) return switch_next_char();
            else { continues_normal_attack(0.1); return switch_next_char(); }
        }
        double forte_delay = task.seconds();
        double count = -0.1;
        while (time_elapsed_accounting_for_freeze(last_heavy) < 8 &&
               !is_mouse_forte_full() && !task.stop_requested()) {
            const double now = task.seconds();
            if (resonance_available()) {
                // Original condition tests the non-empty result tuple.
                click_resonance(0,false,false);
                if (!perform_under_outro) {
                    task.mouse_up();
                    return switch_next_char();
                }
            }
            if (!perform_under_outro && need_fast_perform() &&
                time_elapsed_accounting_for_freeze(last_perform) > 1.1) break;
            if (now-forte_delay > count) {
                task.mouse_up(); sleep(0.2);
                task.mouse_down(); count += 1;
            }
            if (is_forte_full()) forte_delay = now;
            else if (now-forte_delay > 0.5) break;
            check_combat();
            task.next_frame();
        }
        task.mouse_up();
        click_echo();
        switch_next_char();
    }
};
