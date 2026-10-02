#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\ShoreKeeper.py
// Port source SHA256: b6d5e5eb934dfe60559920d0f01afa46845cc43005e8a0e4ed12dc880556e2d7
#include "OriginalBaseChar.h"

class OriginalShoreKeeper final : public OriginalBaseChar {
    double outrotime = -1;
    int dodge_count = 0;
    int attribute=0;
    void decide_teammate(){if(attribute>0)return;attribute=task.find_character("Augusta")?2:1;}
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        decide_teammate();
        if(attribute==2 && has_intro && from=="Augusta")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    bool skip_combat_check() override {return state.has_intro || flying();}
    void do_perform() override {
        if (state.has_intro) {
            task.skip_combat_check=true;
            try {
                raw_sleep(0.1);
                if (task.active_slot() < 0) {
                    if(wait_until([&](){return task.active_slot()>0;},4))sleep(0.5);
                } else continues_normal_attack(1.2);
            }catch(...){task.skip_combat_check=false;throw;}
            task.skip_combat_check=false;
        }
        click_echo(0, 0, 0);
        click_liberation();
        click_resonance();
        // In OK-WW, `if not self.click_resonance():` tests a non-empty tuple;
        // it is always false, so the following heavy_click_forte is unreachable.
        switch_next_char();
    }
    void on_switch_out(bool full, double now) override {
        if (full) { outrotime = now; dodge_count = 5; }
    }
    void switch_out(bool con_full,double now) override {
        const bool full=con_full || state.current_con==1;
        state.switch_out(now,con_full);on_switch_out(full,now);
    }
    bool auto_dodge(const std::function<bool()>& condition) override {
        bool clicked = false;
        if (time_elapsed_accounting_for_freeze(outrotime) < 30 && dodge_count > 0) {
            const double start = task.seconds();
            while (task.seconds() - start < 1.5 && !task.stop_requested()) {
                if (!condition()) break;
                continues_right_click(0.05);
                sleep(0.05);
                clicked = true;
                task.next_frame();
            }
        }
        if (clicked) --dodge_count;
        return clicked;
    }
};
