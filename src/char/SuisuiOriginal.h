#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Suisui.py
// Port source SHA256: 130b0fa724186c911f6376b16e1912e0234dabe0839169bd58019044d3434f86
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Suisui.py
class SuisuiOriginal final : public OriginalBaseChar {
    bool should_heavy = false;
    bool forte3_available() { return find_feature("suisui_forte3", 0.75); }
    bool forte2_available() { return find_feature("suisui_forte2", 0.75); }
    bool try_e() {
        if (!find_feature("suisui_e1")) return false;
        const double start = task.seconds();
        while (find_feature("suisui_e1") && time_elapsed_accounting_for_freeze(start) < 2 &&
               !task.stop_requested()) {
            if (!send_resonance_key()) throw std::runtime_error("Maa Suisui E failed");
            sleep(0.05);
        }
        return true;
    }
    void perform_forte3_rotation() {
        double start = task.seconds();
        if (should_heavy) {
            if (state.has_intro) heavy_attack(1.5);
            click_resonance();
            should_heavy = false;
        }
        bool forte_reached = false;
        while (time_elapsed_accounting_for_freeze(start) < 26 && !task.stop_requested()) {
            if (forte3_available()) { forte_reached = true; break; }
            if (forte2_available() || forte3_available()) {
                for (int i=0; i<7; ++i) {
                    if (forte3_available()) break;
                    task.click(-1,0.1);
                }
                forte_reached = true;
                break;
            }
            cycle_start();
            if (!state.has_intro && try_e()) return switch_next_char();
            task.click();
            cycle_sleep(0.1);
        }
        if (!forte_reached) return;
        bool liberation_clicked = false;
        start = task.seconds();
        while (time_elapsed_accounting_for_freeze(start) < 12 && !task.stop_requested()) {
            if (!liberation_clicked) {
                liberation_clicked = click_liberation(-1, false, 0);
                if (liberation_clicked) { task.next_frame(); continue; }
            }
            if (is_con_full() && forte3_available()) return;
            task.click(-1,0.1);
        }
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        const double elapsed=time_elapsed_accounting_for_freeze(state.last_forte3_switch);
        if(elapsed>40)return 400;
        if(elapsed<16)return 0;
        bool has_main=false;
        for(int slot=1;slot<=3;++slot)if(auto* member=task.member_at(slot))
            if(member!=&state && member->is_main_dps())has_main=true;
        if(has_main && current && current->member_state().is_main_dps() && has_intro)return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();state.last_forte3_switch=-1;should_heavy=false;}
    using OriginalBaseChar::OriginalBaseChar;
    void on_switch_out(bool con_full, double) override {
        if (con_full) state.last_forte3_switch = task.seconds();
    }
    void do_perform() override {
        if (!should_heavy) should_heavy = state.has_intro;
        perform_forte3_rotation();
        switch_next_char();
    }
};
