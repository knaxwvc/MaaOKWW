#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Lupa.py
// Port source SHA256: df66950099eaf2ca055beb7bbeefaa2805f4903fd9e355f3410d4d63d01976a0
#include "OriginalBaseChar.h"
class LupaOriginal final : public OriginalBaseChar {
    bool wolf=false;
    bool still_in_liberation() { return time_elapsed_accounting_for_freeze(last_liberation)<12; }
    int judge_forte() {
        if(!is_forte_full()) return 0;
        const auto f=task.frame();
        return original_frequency_forte(f,original_hcenter_box(f,3840,2160,1633,2004,2160,2016),
            {75,105,75,105,235,255},2,19,21,400);
    }
    bool res_wolf(double timeout=1) {
        const double start=task.seconds(); bool clicked=false;
        while(!task.stop_requested()) {
            if(!(wolf && task.seconds()-start<0.2) && !find_feature("lupa_wolf_icon2",0.85)) break;
            send_resonance_key(); clicked=true;
            if(task.seconds()-start>timeout) break;
            check_combat(); task.next_frame();
        }
        if(clicked) { last_liberation=-10000; state.last_liberation=-10000; wolf=false; sleep(1.2); }
        return clicked;
    }
    void click_jump_with_click(double delay) {
        const double start=task.seconds(); bool jump=true;
        while(task.seconds()-start<=delay && !task.stop_requested()) {
            if(jump) { task.send_key(0x20); sleep(0.01); } else task.click();
            jump=!jump;
            if(judge_forte()==2) return;
            check_combat(); task.next_frame();
        }
    }
    void consume_forte(bool in_outro) {
        if(flying()) wait_until([&]{return !is_forte_full();},2,[&]{task.click(0.1);});
        else { heavy_attack(); wait_until([&]{return !is_forte_full();},1.4,[&]{task.click(0.1);}); }
        if(!is_forte_full()) wolf=true;
        if(in_outro) { wait_until([&]{return find_feature("lupa_wolf_icon2",0.85);},0.5); res_wolf(); }
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(still_in_liberation() || (has_intro && from=="Changli"))return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();wolf=false;}
    LupaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& s):OriginalBaseChar(io,s){check_f_on_switch=false;}
    void do_perform() override {
        bool in_outro=false;
        if(state.has_intro) { continues_normal_attack(1); in_outro=check_outro()=="Changli"; }
        click_echo(0,0,0);
        if(res_wolf() && !in_outro) return switch_next_char();
        if(judge_forte()==2 && !find_feature("lupa_wolf_icon2",0.85)) {
            consume_forte(in_outro); if(!in_outro) return switch_next_char();
        }
        if(task.frame().resonance_white>0.05 && click_resonance().clicked) {
            last_liberation=-10000; state.last_liberation=-10000;
            if(liberation_available()) wait_down(); else return switch_next_char();
        }
        f_break();
        if((in_outro || !need_fast_perform()) && click_liberation()) {
            continues_normal_attack(0.3);
            if(in_outro) continues_normal_attack(1); else return switch_next_char();
        }
        if(still_in_liberation()) { click_jump_with_click(4); consume_forte(in_outro); return switch_next_char(); }
        continues_normal_attack(0.1); switch_next_char();
    }
};
