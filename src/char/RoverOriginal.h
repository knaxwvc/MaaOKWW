#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Rover.py
// Port source SHA256: 1feeaea5bdc308713f3fc19e41417ac49476af0ce9b7e0975944c742877189c7
#include "OriginalBaseChar.h"
class RoverOriginal final : public OriginalBaseChar {
    int form=-1;
    bool use_skyfall_severance=false;
    bool wind_flying(){return task.has_levitator?flying():task.frame().resonance_white>0.15;}
    bool wind_click_flying(double duration){const double start=task.seconds();while(task.seconds()-start<duration && !task.stop_requested()){if(!wind_flying())return false;task.click(0.1);sleep(0.1);}return true;}
    void wind_wait_down(bool check_forte=true){
        if(wind_flying()){
            if(task.has_levitator)wait_down();
            else wait_until([&]{return task.frame().resonance_white<0.15;},2.5,[&]{task.click(0.1,0.01);});
        }
        if(check_forte){sleep(0.03);if(is_forte_full())send_resonance_key();}else sleep(0.01);
    }
    void zani_insert(){
        if(state.has_intro)continues_normal_attack(0.2);wait_down();
        if(resonance_available()){click_resonance();sleep(0.05);}
        if(task.use_liberation){
            bool succeeded=click_liberation(-1,true);
            if(!succeeded){const double start=task.seconds();while(task.seconds()-start<2 && !task.stop_requested()){
                continues_normal_attack(std::min(0.25,2-(task.seconds()-start)));
                if(task.seconds()-start>=2)break;
                if(click_liberation(-1,true,0)){succeeded=true;break;}
            }}
            if(succeeded)sleep(0.6);
        }
        if(echo_available())click_echo(0,0,0);
        if(state.buff_time()>0)state.last_buff_time=task.seconds();
        switch_next_char();
    }
    bool spectro(){
        auto* zani=task.find_character("Zani");
        if(zani && zani->use_rover_linkage() && zani->consume_insert_handoff()){zani_insert();return true;}
        if(state.has_intro)continues_normal_attack(1);wait_down();heavy_attack();sleep(0.4);continues_normal_attack(0.7);click_echo(0,0,0);
        if(is_forte_full()){check_combat();if(resonance_available() && click_resonance().clicked){continues_normal_attack(1.4);sleep(0.1);}}
        check_combat();if(!click_liberation(-1,true))click_resonance();return false;
    }
    void havoc(){wait_down();heavy_click_forte([&]{return is_mouse_forte_full();});click_liberation(-1,true);if(click_resonance().clicked)return;if(!click_echo())task.click();continues_normal_attack(std::max(0.0,1.1-time_elapsed_accounting_for_freeze(state.last_switch_time)));}
    void wind(){
        if(!(state.has_intro && wind_click_flying(2))){
            wind_wait_down(false);
            if(resonance_available() && !is_forte_full()){
                click_echo(0,0,0);const double start=task.seconds();bool fly=false;
                while(task.seconds()-start<1 && !task.stop_requested()){send_resonance_key(0,0.1);task.next_frame();task.click(0.1);if((fly=wind_flying()))break;}
                if(fly)wind_click_flying(use_skyfall_severance?1.6:1.74);
                if(use_skyfall_severance && click_resonance(0,false,false).clicked)wind_click_flying(1);
            }
        }
        click_liberation(-1,true);wind_wait_down();
    }
public:
    void reset_state() override {state.ring_index=-1;OriginalBaseChar::reset_state();form=-1;}
    using OriginalBaseChar::OriginalBaseChar;
    int known_form() const override { return state.ring_index; }
    void do_perform() override {
        const int detected=task.frame().concerto_color_index;if(detected>=0)form=detected;
        if(!state.has_intro)sleep(0.01);
        auto* zani=task.find_character("Zani");
        if(form!=0 && zani)zani->discard_insert_handoff();
        if(form==5){intro_motion_freeze_duration=0.64;havoc();}
        else if(form==0){intro_motion_freeze_duration=0.92;if(spectro())return;}
        else if(form==4){intro_motion_freeze_duration=0.52;use_skyfall_severance=task.find_character("Cartethyia") && task.find_character("Phoebe");wind();}
        else {if(state.has_intro)continues_normal_attack(intro_motion_freeze_duration+0.2);wait_down();click_echo();const bool lib=click_liberation(-1,true);const bool res=click_resonance().clicked;if(!lib && !res)continues_normal_attack(1);}
        switch_next_char();
    }
};
