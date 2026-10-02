#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Brant.py
// Port source SHA256: 41e1ac2dd797be7352dfe864cc63defe0c83bf18157c83e7d243be8b2eb3d1b3
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Brant.py
class BrantOriginal final : public OriginalBaseChar {
    int attribute=0;
    OriginalBaseChar* char_lupa=nullptr;
    void decide_teammate(){if(attribute>0)return;char_lupa=task.find_character("Lupa");attribute=1;}
    bool still_in_liberation() { return time_elapsed_accounting_for_freeze(last_liberation) < 12; }
    bool flick_resonance(double timeout = 0.2, bool send_click = true) {
        if (send_click && resonance_available())
            wait_until([&]() { return task.frame().resonance_white > 0; }, 0.2,
                       [&]() { task.click(0.1); });
        if (task.frame().resonance_white > 0 && resonance_available()) {
            wait_until([&]() { return !resonance_available(); }, timeout,
                       [&]() { send_resonance_key(); });
            return true;
        }
        return false;
    }
    void wait_down_for(double timeout, bool click = true) {
        wait_until([&]() { return !flying(); }, timeout,
                   click ? std::function<void()>([&]() { task.click(0.1); }) :
                           std::function<void()>{});
    }
    void resonance_forte_full() {
        const double start = task.seconds();
        while (resonance_available() && is_forte_full() &&
               task.seconds()-start <= 1 && !task.stop_requested()) {
            send_resonance_key(); check_combat(); task.next_frame();
        }
    }
    void click_jump_with_click(double delay = 0.1) {
        int click = 0;
        if (task.has_levitator && !flying()) { flick_resonance(); sleep(0.2); click = 1; }
        const double start = task.seconds();
        while (task.seconds()-start <= delay && !task.stop_requested()) {
            if (click == 0) task.send_key(0x20); else task.click();
            click = 1-click;
            task.next_frame();
        }
    }
    bool perform_in_outro() {
        double start = task.seconds();
        double timeout = 1.5;
        bool liber = false;
        if (still_in_liberation()) { timeout = 10; liber = true; }
        while (!task.stop_requested()) {
            if (is_forte_full() && resonance_available()) {
                resonance_forte_full();
                last_liberation = -10000;
                state.last_liberation = -10000;
                wait_down_for(4);
                if (liber) break;
            }
            if (liberation_available() && click_liberation()) {
                start = task.seconds(); timeout = 10; liber = true;
            }
            if (task.seconds()-start > timeout) break;
            if (task.has_levitator && !flying()) { flick_resonance(); sleep(0.2); }
            else if (!task.has_levitator) task.send_key(0x20);
            task.click(); check_combat(); task.next_frame();
        }
        click_echo();
        return true;
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        decide_teammate();
        if(time_elapsed_accounting_for_freeze(state.perform_anchor,true)<4)return 0;
        if(still_in_liberation() || (has_intro && from=="Lupa"))return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    BrantOriginal(OriginalCombatIO& io, OriginalSwitchCharacter& member)
        : OriginalBaseChar(io, member) { check_f_on_switch = false;state.perform_anchor=0; }
    void reset_state() override {OriginalBaseChar::reset_state();attribute=0;char_lupa=nullptr;}
    void do_perform() override {
        decide_teammate();
        if (state.has_intro) {
            continues_normal_attack(1.3);
            if (state.has_sub_dps_intro && check_outro() == "Lupa" && perform_in_outro())
                return switch_next_char();
        }
        f_break();
        if (is_forte_full() && resonance_available()) {
            resonance_forte_full();
            last_liberation = -10000;
            state.last_liberation = -10000;
            state.perform_anchor = task.seconds();
            if (echo_available()) click_echo();
        }
        if (!need_fast_perform() && !is_forte_full() && click_liberation())
            continues_normal_attack(0.8);
        click_jump_with_click(1.3);
        if (is_forte_full() && resonance_available()) {
            resonance_forte_full();
            state.perform_anchor = task.seconds();
            return switch_next_char();
        }
        if (!still_in_liberation() && echo_available()) click_echo();
        switch_next_char();
    }
};
