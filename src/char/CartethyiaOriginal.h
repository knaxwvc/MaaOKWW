#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Cartethyia.py
// Port source SHA256: 344b4b5ceb51b286ce9b782105d9c5c7954efe27c799693dbc57aef620910d2e
#include "OriginalBaseChar.h"
class CartethyiaOriginal final : public OriginalBaseChar {
    bool is_cartethyia=true;
    std::array<bool,3> buffs{};
    bool try_mid_air_attack_once=false,transform=false;
    double res_time=-1,n4_time=-1;
    bool first_engage(){return last_perform-task.combat_start>=0 && last_perform-task.combat_start<0.4;}
    bool is_small(){
        is_cartethyia=find_feature_in_box("forte_cartethyia_sword3_half","forte_cartethyia_sword3",0.5);
        state.alternate_form=!is_cartethyia;intro_motion_freeze_duration=is_cartethyia?0.6:0.78;
        return is_cartethyia;
    }
    void get_sword_buffs(){for(int i=0;i<3;++i)buffs[size_t(i)]=find_feature("forte_cartethyia_sword"+std::to_string(i+1),0.9);}
    bool is_mid_air_attack_available(){
        if(!is_cartethyia)return false;
        const auto f=task.frame();const auto box=original_hcenter_box(f,3840,2160,2298,1997,2361,2022);
        if(original_color_percent(f,box,original_forte_white)<=0.15)return false;
        double sum=0,squared=0;int count=0;
        for(int y=box.y;y<box.y+box.height;++y)for(int x=box.x;x<box.x+box.width;++x){
            if(x<0||y<0||x>=f.width||y>=f.height)continue;
            const auto* p=f.pixels.data()+(size_t(y)*f.width+x)*f.channels;
            const double gray=0.114*p[0]+0.587*p[1]+0.299*p[2];sum+=gray;squared+=gray*gray;++count;
        }
        if(!count)return false;const double mean=sum/count;
        return mean>190 && std::sqrt(std::max(0.0,squared/count-mean*mean))<45;
    }
    void try_mid_air_attack(double timeout=2){
        get_sword_buffs();if(!(liberation_available() || (buffs[0]&&buffs[1]&&buffs[2]) || try_mid_air_attack_once))return;
        if(is_mid_air_attack_available()){
            const double start=task.seconds();while(!task.stop_requested()){
                task.send_key(0x20);sleep(0.1);if(echo_available())click_echo(0,0,0);task.click();sleep(0.1);
                if(!is_mid_air_attack_available()){sleep(0.4);break;}if(task.seconds()-start>timeout)break;sleep(0.1);
            }
        }else if(try_mid_air_attack_once){const double start=task.seconds();while(task.seconds()-start<0.8 && !task.stop_requested()){task.send_key(0x20);sleep(0.1);if(echo_available())click_echo(0,0,0);task.click();sleep(0.1);}}
        try_mid_air_attack_once=false;
    }
    bool acquire_missing_buffs(){
        get_sword_buffs();if(buffs[0]&&buffs[1]&&buffs[2])return false;
        const bool performed=!(buffs[1]&&buffs[2]);
        if(!buffs[1]){
            const bool try_once=find_feature_in_box("forte_cartethyia_sword2_half","forte_cartethyia_sword2",0.85);
            double timeout=try_once?(first_engage()?2.5:2):3.5;double start=task.seconds();bool interrupted=false;
            while(task.seconds()-start<timeout && !task.stop_requested()){
                if(!try_once && find_feature_in_box("forte_cartethyia_sword2_half","forte_cartethyia_sword2",0.85))break;
                if(!interrupted && flying()){if(timeout==2)timeout=2.5;interrupted=true;wait_until([&]{return !flying();},3);start=task.seconds();}
                task.click(0.1,0.01);check_combat();task.next_frame();
            }
        }
        bool res=false;if(!buffs[2]){res=click_resonance().clicked;check_combat();}
        if(liberation_available()){if(res)sleep(0.2);}else if(performed)return true;
        if(!buffs[0]){
            task.mouse_down();try{wait_until([&]{return find_feature("forte_cartethyia_sword1",0.9);},1.5);}catch(...){task.mouse_up();throw;}
            task.mouse_up();check_combat();
        }
        if(!buffs[0]&&!buffs[1]&&!buffs[2])try_mid_air_attack_once=true;
        return !liberation_available();
    }
    bool try_lib_big(){if(find_feature("lib_cartethyia_big") && click_liberation()){is_cartethyia=true;state.alternate_form=false;click_resonance();return true;}return false;}
    bool click_resonance_with_lib_big(){
        if(has_cd('E'))return false;double last_click=0,clicked_at=0;bool clicked=false;
        while(!task.stop_requested()){
            if(clicked_at!=0 && task.seconds()-clicked_at>8){task.in_liberation=false;break;}
            check_combat();const double now=task.seconds(),white=task.frame().resonance_white;
            if(!resonance_available())break;
            if(now-last_click>0.1){
                if(white>0 && resonance_available()){
                    if(white<0.17 && now-clicked_at<2.5){task.click();continue;}
                    if(clicked_at==0){clicked=true;clicked_at=now;}send_resonance_key();
                }last_click=now;
            }
            if(try_lib_big())break;task.next_frame();
        }
        if(clicked){last_res=task.seconds();res_time=task.seconds();}return clicked;
    }
    double fleurdelys_n4_duration(){
        double duration;
        if(!transform && state.has_intro)duration=3.9-(task.seconds()-last_perform);
        else if(transform || first_engage() || time_elapsed_accounting_for_freeze(n4_time,true)<1.5)duration=3.25;
        else if(time_elapsed_accounting_for_freeze(res_time,true)<2.5)duration=2+std::max(0.0,1.6-time_elapsed_accounting_for_freeze(res_time,true));
        else duration=1.9-(task.seconds()-last_perform);
        n4_time=res_time=-1;return duration;
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(!is_cartethyia)return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void on_combat_end() override {
        if(!is_cartethyia && task.select_character)
            task.select_character((state.index+1)%task.team_size()+1);
    }
    using OriginalBaseChar::OriginalBaseChar;
    bool is_alternate_form() override{return !is_cartethyia;}
    double intro_freeze_seconds() const override{return is_cartethyia?0.6:0.78;}
    void do_perform() override {
        transform=false;
        if(state.has_intro)continues_normal_attack(1.2);else click_echo(0,0,0);
        if(is_small()){
            wait_down();if(acquire_missing_buffs())return switch_next_char();check_combat();try_mid_air_attack();check_combat();
            if(click_liberation()){is_cartethyia=false;state.alternate_form=true;last_res=-1;transform=true;}
            else if(!is_small())transform=true;
        }
        if(!click_resonance_with_lib_big()){
            const double timeout=is_small()?1.1:fleurdelys_n4_duration();const double start=task.seconds();
            while(task.seconds()-start<timeout && !task.stop_requested()){if(try_lib_big())return switch_next_char();task.click(0.1);check_combat();task.next_frame();}
            n4_time=task.seconds();
        }
        try_lib_big();switch_next_char();
    }
};
