#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Phrolova.py
// Port source SHA256: a3e584d03a0a845903edc4cf5031471e3bdbb6e1427668a62ddd3ed128a7b92a
#include "OriginalBaseChar.h"

class Phrolova final : public OriginalBaseChar {
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(time_elapsed_accounting_for_freeze(last_liberation)>14 && has_intro && from=="Cantarella")return 400;
        if(time_elapsed_accounting_for_freeze(last_liberation)<24)return 0;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    bool skip_combat_check() override {return time_elapsed_accounting_for_freeze(last_liberation)<2;}
private:
    bool sp = false;
    bool res_ready = false;
    bool resonance_available() override {
        if (sp) return !(flying() || has_cd('E'));
        return OriginalBaseChar::resonance_available();
    }
    bool heavy_and_liber() {
        if (!heavy_click_forte([&]() { return is_mouse_forte_full(); })) return false;
        const double start = task.seconds();
        while (task.seconds() - start < 3 && !task.stop_requested()) {
            if (click_liberation(-1, false, 0)) break;
            task.next_frame();
        }
        return true;
    }
    void shorekeeper_auto_dodge() {
        auto* shorekeeper = task.find_character("ShoreKeeper");
        if (shorekeeper) shorekeeper->auto_dodge([&]() { return flying(); });
    }
    void wait_resonance_off() {
        const double start = task.seconds();
        while (resonance_available() && task.seconds() - start < 0.3 && !task.stop_requested()) {
            task.click();
            task.next_frame();
        }
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        last_liberation = -1;
        state.last_liberation = -1;
        bool perform_under_outro = false;
        sp = false;
        if (state.has_intro) {
            res_ready = false;
            if (check_outro() == "Cantarella") perform_under_outro = true;
            continues_normal_attack(1.7);
            continues_right_click(0.1);
        }
        if (flying()) wait_down();
        if (liberation_available() && click_liberation(-1, false, 0)) return switch_next_char();
        if (heavy_and_liber()) return switch_next_char();
        if (resonance_available() || res_ready) {
            continues_normal_attack(0.1);
            click_resonance();
            continues_normal_attack(0.1);
            wait_resonance_off();
            if (!click_echo()) continues_right_click(0.1);
        }
        res_ready = false;
        const double start = task.seconds();
        if (perform_under_outro) sp = true;
        while ((perform_under_outro ?
                time_elapsed_accounting_for_freeze(last_perform) < 16 : task.seconds()-start < 4) &&
               !task.stop_requested()) {
            if (liberation_available() && click_liberation(-1, false, 0)) return switch_next_char();
            if (flying()) shorekeeper_auto_dodge();
            if (heavy_and_liber()) return switch_next_char();
            if (resonance_available() && task.seconds()-start > 1) {
                if (perform_under_outro) {
                    continues_normal_attack(0.3);
                    if (click_resonance().clicked) {
                        continues_normal_attack(0.1);
                        wait_resonance_off();
                        if (!click_echo()) continues_right_click(0.1);
                    }
                } else { res_ready = true; break; }
            }
            if (!task.click()) throw std::runtime_error("Maa Phrolova click failed");
            check_combat();
            task.next_frame();
        }
        switch_next_char();
    }
};
