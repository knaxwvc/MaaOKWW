#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Changli.py
// Port source SHA256: 23e07be4e550221f1d74d28d4cfd82c421b820b5fe595f5bebd73880945fdd67
#include "OriginalBaseChar.h"
class ChangliOriginal final : public OriginalBaseChar {
    bool enhanced_normal=false;
    int judge_forte() {
        if(is_mouse_forte_full()) return 4;
        const auto f=task.frame();
        return original_frequency_forte(f,original_hcenter_box(f,3840,2160,1633,2004,2160,2016),
            {95,115,85,105,240,255},4,9,11,400);
    }
    bool flick_resonance(double timeout=0.2,bool send_click=true) {
        if(send_click && resonance_available()) wait_until([&]{return task.frame().resonance_white>0;},0.2,[&]{task.click(0.1);});
        if(task.frame().resonance_white>0 && resonance_available()) {
            wait_until([&]{return !resonance_available();},timeout,[&]{send_resonance_key();});return true;
        }return false;
    }
    bool liberation_and_heavy() {
        double start=task.seconds(),last_click=-10000;bool clicked=false;
        while(liberation_available() && task.active_slot()>0 && !task.stop_requested()) {
            const double now=task.seconds();
            if(now-last_click>0.1){send_liberation_key();if(!clicked){clicked=true;last_liberation=task.seconds();state.last_liberation=last_liberation;}last_click=now;}
            if(task.seconds()-start>5) throw OriginalNotInCombat("Changli liberation input timeout");
            task.next_frame();
        }
        if(clicked && !wait_until([&]{return task.active_slot()<0;},0.4)) return false;
        start=task.seconds();bool hold=false;task.in_liberation=clicked;
        try {
            while(task.active_slot()<0 && !task.stop_requested()) {task.in_liberation=true;
                if(!clicked){clicked=true;last_liberation=task.seconds();state.last_liberation=last_liberation;}
                if(task.seconds()-start>1.5 && !hold){task.mouse_down();hold=true;}
                if(task.seconds()-start>7){task.in_liberation=false;throw OriginalNotInCombat("Changli liberation animation timeout");}
                task.next_frame();
            }
            task.in_liberation=false;
            if(task.add_freeze_duration)task.add_freeze_duration(start,task.seconds()-start,0.1);
            if(clicked){wait_until([&]{return task.active_slot()>0 && is_mouse_forte_full();},0.6);wait_until([&]{return task.active_slot()>0 && !is_mouse_forte_full();},0.6);}
        }catch(...){task.mouse_up();throw;}
        task.mouse_up();check_combat();return clicked;
    }
    void do_perform_outro(int forte) {
        if(forte==3){
            const double start=task.seconds();double forte_time=start;bool res=true;
            while(task.seconds()-start<5 && !task.stop_requested()){
                if(res && flick_resonance(0.2,false)){res=false;continue;}
                task.click(0.1);
                if(is_mouse_forte_full()){if(task.seconds()-forte_time>0.2)break;}else forte_time=task.seconds();
                check_combat();task.next_frame();
            }
            if(is_mouse_forte_full()){heavy_click_forte([&]{return is_mouse_forte_full();});sleep(1);}
        }else if(forte>=4 || is_mouse_forte_full()){
            if(flying())heavy_attack();heavy_click_forte([&]{return is_mouse_forte_full();});forte=0;sleep(1);
        }
        if(liberation_available() && liberation_and_heavy()){sleep(0.6);forte=0;}
        if(forte<3 && flick_resonance(0.2,false)){enhanced_normal=true;return;}
        click_echo();
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && from=="Brant")return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();enhanced_normal=false;}
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        check_f_on_switch=true;
        if(state.has_intro){continues_normal_attack(0.3);enhanced_normal=true;}
        int forte=judge_forte();
        if(enhanced_normal){continues_normal_attack(0.2);sleep(0.2);
            if(check_outro()=="Brant"){sleep(0.2);do_perform_outro(judge_forte());return switch_next_char();}
            if(forte==3){sleep(0.2);forte=judge_forte();}
        }
        enhanced_normal=false;
        if(forte==4 || is_mouse_forte_full()){
            if(flying())heavy_attack();heavy_click_forte([&]{return is_mouse_forte_full();});check_f_on_switch=false;check_combat();return switch_next_char();
        }
        if(!(forte>=3 && resonance_available()) && liberation_available() && liberation_and_heavy()){check_f_on_switch=false;return switch_next_char();}
        if(flick_resonance(0.2,false)){enhanced_normal=true;return switch_next_char();}
        if(click_echo())return switch_next_char();
        continues_normal_attack(0.1);switch_next_char();
    }
};
