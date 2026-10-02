#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Denia.py
// Port source SHA256: 9aa04c01c32ea2d8a4f23336f0a8d87a14f85130b76a9a406db501af7f8ec9fb
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Denia.py
class DeniaOriginal final : public OriginalBaseChar {
    double lib_2 = -1;
    bool lib_1_casted = false;
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro)return (from=="Aemeath" || from=="Qingxiao") && !has_buff()?200:1;
        if(has_buff())return 100;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();lib_2=-1;lib_1_casted=false;}
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if (state.has_intro) continues_normal_attack(2);
        else if (lib_1_casted) continues_normal_attack(1.3);
        const double duration = lib_1_casted ? 4.4 : 1.2;
        const double start = task.seconds();
        while (time_elapsed_accounting_for_freeze(start) < duration && !task.stop_requested()) {
            cycle_start();
            if (lib_2 >= 0 && time_elapsed_accounting_for_freeze(lib_2) < 10 && is_con_full())
                return switch_next_char();
            if (click_resonance().clicked) {
            } else if (liberation_available()) {
                const bool is_lib2 = find_feature("denia_end_lib");
                if (click_liberation(-1, false, 0)) {
                    if (is_lib2) {
                        lib_2 = task.seconds();
                        lib_1_casted = false;
                        click_echo(0, 0, 0);
                    } else {
                        lib_1_casted = true;
                        continues_normal_attack(1.9);
                    }
                    return switch_next_char();
                }
            } else {
                task.click();
            }
            cycle_sleep();
        }
        switch_next_char();
    }
};
