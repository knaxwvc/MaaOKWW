#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Ciaccona.py
// Port source SHA256: 5d5be8237c7c63350aa4dddc964431be7c2a20ecf976bde44789c3572f2a2c6b
#include "OriginalBaseChar.h"
class CiacconaOriginal final : public OriginalBaseChar {
    int attribute=0;
    bool in_liberation=false;
    double outro_time=-1;
    OriginalBaseChar* cartethyia=nullptr;
    void decide_teammate() {
        attribute=1;
        for(int slot=1;slot<=3;++slot)if(auto* member=task.member_at(slot)){
            const auto name=member->definition->class_name;
            if(name=="Cartethyia"){cartethyia=task.find_character(name);attribute=3;break;}
            if(name=="Phoebe" || name=="Zani"){attribute=2;break;}
        }
        state.linkage_attribute=attribute;
    }
    int judge_forte() {
        if(is_mouse_forte_full()) return 3;
        const auto f=task.frame();
        return original_frequency_forte(f,original_hcenter_box(f,3840,2160,1612,1987,2188,2008),
            {180,210,240,255,70,100},3,12,14,100);
    }
    void click_jump_with_click(double delay) {
        const double start=task.seconds(); bool click=true;
        while(task.seconds()-start<=delay && !task.stop_requested()) {
            if(click) task.click(); else {task.send_key(0x20);sleep(0.01);}
            click=!click;check_combat();task.next_frame();
        }
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(attribute==2 && in_liberation && time_elapsed_accounting_for_freeze(last_liberation)<20)return 0;
        if(attribute==3 && in_liberation && (time_elapsed_accounting_for_freeze(last_liberation)<8 ||
           (cartethyia && cartethyia->is_alternate_form())))return 0;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    CiacconaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& s):OriginalBaseChar(io,s){intro_motion_freeze_duration=0.73;}
    bool skip_combat_check() override {return time_elapsed_accounting_for_freeze(last_liberation)<2;}
    void reset_state() override {OriginalBaseChar::reset_state();attribute=0;cartethyia=nullptr;state.linkage_attribute=0;}
    bool in_outro() override {return time_elapsed_accounting_for_freeze(outro_time)<30;}
    void on_switch_out(bool full,double now) override {if(full) outro_time=now;}
    void switch_out(bool con_full,double now) override {
        const bool full=con_full || state.current_con==1;
        state.switch_out(now,con_full);on_switch_out(full,now);
    }
    void do_perform() override {
        in_liberation=false; state.linkage_in_liberation=false;
        bool wait=false,jump=true;
        if(attribute==0) decide_teammate();
        // The source override returns false unless Cartethyia exposes a class attribute.
        const bool fast=false;
        if(state.has_intro) {continues_normal_attack(0.8);if(!fast) continues_normal_attack(0.7);}
        if(task.frame().echo_white<0.22) click_echo(0,0,0);
        if(!state.has_intro && !fast && !is_mouse_forte_full()) {
            click_jump_with_click(0.4);
            wait_until([&]{return !flying();},1.2,[&]{task.click(0.1);});
            continues_normal_attack(0.2);
        }
        if(click_resonance().clicked) {jump=false;wait=true;}
        if(judge_forte()>=3) {
            if(jump) {const double start=task.seconds();while(!flying() && task.seconds()-start<=0.3 && !task.stop_requested()){task.send_key(0x20);sleep(0.01);}}
            heavy_click_forte([&]{return is_mouse_forte_full();}); wait=true;
        }
        if(liberation_available()) {
            if(wait) sleep(0.4);
            if(click_liberation()) {in_liberation=true;state.linkage_in_liberation=true;if(attribute==2) {const double start=task.seconds();while(task.seconds()-start<0.6 && !task.stop_requested())task.send_key('A');}}
        }
        if(!in_liberation && task.frame().echo_white>0.25) click_echo();
        switch_next_char();
    }
};
