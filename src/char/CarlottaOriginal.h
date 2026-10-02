#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Carlotta.py
// Port source SHA256: 087becb3cff20a2d9180efb6cf22b0168f39356c8dd02cd370acf691ecec4a6d
#include "OriginalBaseChar.h"
class CarlottaOriginal final : public OriginalBaseChar {
    double switch_lock=-1;int forte=0,press_w=-1;bool continue_liberation=false,liberation_ready=false;
    OriginalBaseChar* char_zhezhi=nullptr;
    OriginalBaseChar* zhezhi(){return char_zhezhi;}
    void decide_teammate(){press_w=0;if(auto* peer=task.find_character("Zhezhi")){char_zhezhi=peer;peer->bind_carlotta(this);}}
    void shorekeeper_auto_dodge(){auto* peer=task.find_character("ShoreKeeper");if(peer)peer->auto_dodge([&]{return flying();});}
    int get_forte(){if(is_mouse_forte_full())return 4;const auto f=task.frame();forte=original_frequency_forte(f,original_hcenter_box(f,5120,2880,2164,2670,2900,2680),{235,255,195,225,70,100},4,9,11,100);return forte;}
    bool click_liberation(double=-1,bool=false,double=0.1,double animation_min=0,bool click_f=true) override {
        const double begin=task.seconds();double last_click=-10000;bool clicked=false;
        while(liberation_available() && !task.stop_requested()){
            const double now=task.seconds();
            if(now-last_click>0.1){send_liberation_key();clicked=true;last_click=now;}
            if(task.seconds()-begin>0.4)return false;task.next_frame();
        }
        if(!clicked || !wait_until([&]{return task.active_slot()<0;},0.4,[&]{task.click(0.1);}))return false;
        const double start=task.seconds();double last_f=0;task.in_liberation=true;
        while(task.active_slot()<0 && !task.stop_requested()){
            if(click_f && task.seconds()-start>=animation_min && task.seconds()-last_f>=0.1){task.send_key('F');last_f=task.seconds();}
            if(task.seconds()-start>7){task.in_liberation=false;throw OriginalNotInCombat("Carlotta liberation animation timeout");}task.next_frame();
        }
        if(task.add_freeze_duration)task.add_freeze_duration(start,task.seconds()-start,0.1);
        last_liberation=task.seconds();state.last_liberation=last_liberation;task.in_liberation=false;state.cached_liberation_available=false;return clicked;
    }
    OriginalResonanceResult click_resonance(double post_sleep=0,bool has_animation=false,bool send_click=true,double=0,bool=false,double timeout=0,bool=true) override {
        OriginalResonanceResult result;double clicked_at=-1,last_click=-10000;bool last_op_res=false;const double start=task.seconds();
        while(task.seconds()-start<(timeout?timeout:10) && !task.stop_requested()){
            check_combat();const double now=task.seconds(),white=task.frame().resonance_white;if(has_cd('E'))break;
            if(now-last_click>0.1){
                if(send_click && (white==0 || last_op_res)){task.click();last_op_res=false;continue;}
                if(white>0 && resonance_available()){
                    if(clicked_at<0){result.clicked=true;clicked_at=now;last_res=now;}
                    last_op_res=true;send_resonance_key();if(has_animation)sleep(0.2,false);
                }last_click=now;
            }task.next_frame();
        }
        if(result.clicked)sleep(post_sleep);result.duration=clicked_at>=0?task.seconds()-clicked_at:0;return result;
    }
    void run_liberation(bool clear_ready){
        double dodge_at=-1;
        while(liberation_available() && !task.stop_requested()){
            if(dodge_at>=0 && task.seconds()-dodge_at>0.5 && flying())shorekeeper_auto_dodge();
            if(click_liberation()){dodge_at=task.seconds();if(clear_ready){continue_liberation=false;liberation_ready=false;}}
            check_combat();
        }
    }
    void do_perform_outro(){
        zhezhi()->set_forte_stacks(0);get_forte();
        if(!liberation_ready){while(!is_mouse_forte_full() && !task.stop_requested()){
            if(resonance_available())click_resonance();else {task.click(0.1);}
            if(time_elapsed_accounting_for_freeze(last_perform)>6)break;check_combat();
        }}
        if(heavy_click_forte([&]{return is_mouse_forte_full();})){liberation_ready=true;forte=0;}
        check_combat();bool clicked=false,liber=false;
        if(liberation_ready){while(time_elapsed_accounting_for_freeze(last_perform)<14 && !task.stop_requested()){
            if(liberation_available()&&!liber){double dodge_at=-1;
                while(liberation_available() && !task.stop_requested()){
                    if(dodge_at>=0 && task.seconds()-dodge_at>0.5 && flying())shorekeeper_auto_dodge();
                    if(click_liberation()){liberation_ready=false;liber=true;forte=0;dodge_at=task.seconds();}check_combat();
                }if(liber)sleep(0.2);
            }
            if(click_resonance().clicked){continues_normal_attack(0.8);++forte;clicked=true;}
            task.click(0.1);if(!liberation_available()&&!resonance_available()&&clicked)break;check_combat();
        }}
        if(click_echo(0,0,2))switch_lock=task.seconds();continue_liberation=!liber;
    }
    void do_perform_interlock(){
        const int bullet=state.has_intro?1:0;
        if(state.has_intro){continues_normal_attack(1.3);if(check_outro()=="Zhezhi"){do_perform_outro();return switch_next_char();}}
        if(get_forte()<4 && resonance_available() && !liberation_ready){
            if(!bullet)heavy_attack();if(click_resonance().clicked){forte+=2;switch_lock=task.seconds();return switch_next_char();}
        }
        if(ready_for_linkage())continue_liberation=false;
        if(heavy_click_forte([&]{return is_mouse_forte_full();})){liberation_ready=true;return switch_next_char();}
        if(liberation_available() && continue_liberation)run_liberation(true);
        if(echo_available())click_echo();continues_normal_attack(0.31);switch_next_char();
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(press_w==-1)decide_teammate();
        if(has_intro && from=="Zhezhi")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();switch_lock=-1;press_w=-1;char_zhezhi=nullptr;forte=0;continue_liberation=false;liberation_ready=false;state.linkage_ready=false;}
    using OriginalBaseChar::OriginalBaseChar;
    bool ready_for_linkage() override {state.linkage_ready=forte>2 || (resonance_available()&&forte>0) || liberation_ready;return state.linkage_ready;}
    int forte_stacks() override{return forte;}void set_forte_stacks(int value) override{forte=value;}
    bool wait_switch() override{return state.has_intro && time_elapsed_accounting_for_freeze(switch_lock,true)<2.5;}
    void do_perform() override {
        if(press_w==-1)decide_teammate();
        if(zhezhi())return do_perform_interlock();const int bullet=state.has_intro?1:0;
        if(state.has_intro)continues_normal_attack(1.3);
        if(heavy_click_forte([&]{return is_mouse_forte_full();}))return switch_next_char();
        if(liberation_available()&&!need_fast_perform()){run_liberation(false);click_echo();switch_lock=task.seconds();return switch_next_char();}
        if(resonance_available()){if(!bullet)heavy_attack();if(click_resonance().clicked)return switch_next_char();}
        if(click_echo())return switch_next_char();continues_normal_attack(0.31);switch_next_char();
    }
};
