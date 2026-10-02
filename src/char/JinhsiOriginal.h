#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Jinhsi.py
// Port source SHA256: 6986997fdbc2a8eecf02594e7667374afeb042fa183cdfe625b9fb63565bd5fb
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Jinhsi.py
class JinhsiOriginal final : public OriginalBaseChar {
    bool has_free_intro = false;
    double last_fly_e_time = -10000;
    void switch_jinhsi() { switch_next_char(has_free_intro, true); }
    void handle_incarnation() {
        state.incarnation = false;
        const double start = task.seconds();
        double animation_start = -1;
        bool last_op_resonance = true;
        task.in_liberation=true;
        while (task.seconds()-start <= 6 && !task.stop_requested()) {
            if (task.active_slot() > 0) {
                if (last_op_resonance) task.click(0.1);
                else send_resonance_key();
                last_op_resonance = !last_op_resonance;
                if (animation_start >= 0) break;
            } else {task.in_liberation=true;if(animation_start<0)animation_start=task.seconds();}
            check_combat();
            task.next_frame();
        }
        task.in_liberation=false;
        if (!click_echo()) task.click();
        if (animation_start >= 0 && task.add_freeze_duration)
            task.add_freeze_duration(animation_start, -1, 0.1);
    }
    void handle_intro() {
        const double start = task.seconds();
        while (!task.stop_requested()) {
            const double elapsed = task.seconds()-start;
            if (has_cd('E')) {
                if (0.3 < elapsed && elapsed < 1.5) {
                    state.incarnation_cd = true;
                    if (!click_echo()) task.click();
                    return;
                }
                if (elapsed > 1.5) break;
            } else send_resonance_key(0,0.1);
            task.next_frame();
            check_combat();
        }
        last_fly_e_time = start;
        if (click_liberation(-1, true)) continues_normal_attack(0.3);
        else continues_normal_attack(1.4);
        state.incarnation = true;
        state.incarnation_cd = false;
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        return has_intro || state.incarnation || state.incarnation_cd?400:0;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();state.incarnation=false;has_free_intro=false;state.incarnation_cd=false;}
    using OriginalBaseChar::OriginalBaseChar;
    void on_switch_out(bool, double) override { has_free_intro = false; }
    void do_perform() override {
        if (state.incarnation) handle_incarnation();
        else if (state.has_intro || state.incarnation_cd) handle_intro();
        else click_echo();
        switch_jinhsi();
    }
};
