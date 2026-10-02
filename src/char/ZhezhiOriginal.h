#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Zhezhi.py
// Port source SHA256: e5ed714c305a40632201153236cd74a5c2a4eb29b9d35a1a4290d4e842cd5629
#include "OriginalBaseChar.h"
class ZhezhiOriginal final : public OriginalBaseChar {
    bool resonance_blue_cached=false;int forte=0;
    OriginalBaseChar* char_carlotta=nullptr;
    OriginalBaseChar* carlotta(){return char_carlotta;}
    bool resonance_blue(){const auto f=task.frame();return original_color_percent(f,original_hcenter_box(f,5120,2880,2242,2664,2300,2690),original_text_white)>0.3;}
    bool resonance_available() override {return state.is_current_char && resonance_blue()?true:OriginalBaseChar::resonance_available();}
    int judge_forte(){const auto f=task.frame();forte=original_frequency_forte(f,original_hcenter_box(f,5120,2880,2164,2675,2900,2685),{235,255,240,255,185,215},3,12,14,100);return forte;}
    bool con_lock(){auto* peer=carlotta();if(!peer)return true;const bool ready=peer->ready_for_linkage();return ready || get_current_con()<0.6 || (is_con_full()&&!ready);}
    void resonance_until_not_blue(){
        const double start=task.seconds();
        while(!resonance_blue() && !task.stop_requested()){
            if(task.seconds()-start>0.3)break;check_combat();task.next_frame();
        }
        double jump_at=task.seconds()+0.4;task.mouse_down();
        try {while(resonance_available() && resonance_blue() && !task.stop_requested()){
            send_resonance_key();if(need_fast_perform() && task.seconds()-start>1.1)break;
            if(is_con_full() && (!carlotta() || con_lock()))break;if(task.seconds()-start>4)break;
            if(task.seconds()>jump_at){task.send_key(0x20);sleep(0.01);jump_at+=0.4;}
            check_combat();task.next_frame();
        }}catch(...){task.mouse_up();throw;}task.mouse_up();
    }
    void do_perform_interlock(){
        auto* peer=carlotta();if(state.has_intro)continues_normal_attack(1.3);
        if(flying()){wait_until([&]{return !flying();},1.2,[&]{task.click(0.1);});continues_right_click(0.05);}
        if(!resonance_blue() && judge_forte()<3 && !(is_con_full()&&peer->ready_for_linkage())){
            continues_normal_attack(1.4);if(!peer->ready_for_linkage())return switch_next_char();
        }
        if(!resonance_blue() && resonance_available() && judge_forte()>1 && !(is_con_full()&&peer->ready_for_linkage())){
            if(con_lock()&&click_liberation())sleep(0.2);click_resonance();continues_normal_attack(0.8);
        }
        if(con_lock() && resonance_blue() && resonance_available()){
            resonance_until_not_blue();if(con_lock()&&click_liberation(-1,false,0.5))sleep(0.2);else if(echo_available())continues_right_click(0.05);
        }
        click_echo(0,0,2);switch_next_char();
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(char_carlotta && char_carlotta->ready_for_linkage())return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();resonance_blue_cached=false;char_carlotta=nullptr;forte=0;}
    void bind_carlotta(OriginalBaseChar* peer) override {char_carlotta=peer;}
    using OriginalBaseChar::OriginalBaseChar;
    int forte_stacks() override{return forte;}void set_forte_stacks(int value) override{forte=value;}
    void do_perform() override {
        if(carlotta())return do_perform_interlock();
        if(state.has_intro)continues_normal_attack(1.5);click_liberation();
        if((resonance_blue_cached || resonance_blue()) && resonance_available()){
            resonance_blue_cached=false;resonance_until_not_blue();return switch_next_char();
        }
        if(resonance_available() && is_forte_full()){
            click_resonance();continues_normal_attack(0.8);resonance_blue_cached=true;return switch_next_char();
        }
        if(!click_echo())continues_normal_attack(0.1);switch_next_char();
    }
};
