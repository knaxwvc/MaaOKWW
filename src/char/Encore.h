#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Encore.py
// Port source SHA256: 7367d9d89c888782472491913b799a465eb6ca448fe1d327c79d0b47bcd11a7a
#include "OriginalBaseChar.h"

class Encore final : public OriginalBaseChar {
    bool still_in_liberation() {
        return time_elapsed_accounting_for_freeze(state.liberation_time) < 9.5;
    }
    bool can_resonance_step2(double delay = 2) {
        return time_elapsed_accounting_for_freeze(state.last_resonance, true) < delay;
    }
    void n4() {
        const double duration = click_resonance().clicked ? 2.7 : 2.4;
        if (time_elapsed_accounting_for_freeze(state.liberation_time) < 6)
            continues_normal_attack(duration);
        else if (is_mouse_forte_full()) {
            heavy_attack();
            state.last_heavy = task.seconds();
        } else click_resonance();
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(time_elapsed_accounting_for_freeze(state.last_heavy,true)<4.6)return 0;
        if(still_in_liberation() || can_resonance_step2())return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    Encore(OriginalCombatIO& io,OriginalSwitchCharacter& member):OriginalBaseChar(io,member){
        state.liberation_time=0;state.last_heavy=0;state.last_resonance=0;
    }
    void on_switch_out(bool, double) override { state.last_resonance = 0; }
    void do_perform() override {
        if (state.has_intro) {
            const double elapsed = time_elapsed_accounting_for_freeze(state.liberation_time);
            if (6 < elapsed && elapsed < 10 && is_mouse_forte_full()) {
                heavy_attack(1.2);
                sleep(0.1);
                state.last_heavy = task.seconds();
                return switch_next_char();
            }
            wait_down();
        }
        if (still_in_liberation()) { n4(); return switch_next_char(); }
        if (click_resonance().clicked) {
            if (!can_resonance_step2(4)) {
                state.last_resonance = task.seconds();
                return switch_next_char();
            }
        }
        if (!need_fast_perform() && !task.is_open_world_auto_combat() &&
            click_liberation(-1, false, 0.4)) {
            state.liberation_time = task.seconds();
            n4();
            return switch_next_char();
        }
        if (echo_available()) { click_echo(); return switch_next_char(); }
        switch_next_char();
    }
};
