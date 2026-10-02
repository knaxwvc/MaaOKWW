#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Phoebe.py
// Port source SHA256: d01a622879724feebf4ed6d6fcb3762120e4aa9b4c04d6e0db4aba9f94f0eb1c
#include "OriginalBaseChar.h"

// OK-WW Phoebe.py: form charges, Starflash and the Zani insert/handoff axis.
class PhoebeOriginal final : public OriginalBaseChar {
    int attribute=0,team=0,remaining_charges=0,charge_attribute=-1;
    int enter_status=0,starflash_count=0,liberation_count=0,outros=0,priority_liberation_cast=0;
    bool star_available=false,first_rotation_done=false,rover_form_pending=false;
    OriginalBaseChar* zani=nullptr;
    OriginalBaseChar* rover=nullptr;
    double liber_no_effect_at=-1;

    void invalidate_form_charges(){remaining_charges=0;charge_attribute=-1;}
    int known_form_charges(){if(remaining_charges>0 && charge_attribute!=attribute)invalidate_form_charges();return remaining_charges;}
    void refill_form_charges(){remaining_charges=attribute==1?4:attribute==2?2:0;charge_attribute=remaining_charges>0?attribute:-1;}
    void consume_form_charge(){int charges=known_form_charges();if(charges>0)remaining_charges=charges-1;if(!remaining_charges)charge_attribute=-1;}
    int zani_state(){return zani?zani->get_state():0;}
    bool down(){const auto f=task.frame();return (f.resonance_white>0 && !has_cd('E')) || (f.liberation_white>0 && !has_cd('R'));}
    void decide_teammate() {
        rover=task.find_character("Rover");zani=task.find_character("Zani");
        rover_form_pending=rover && rover->known_form()<0;
        team=zani?(rover?1:2):(task.find_character("Cartethyia") && rover?3:0);
        attribute=team?2:1;
        if(team==1){rover->member_state().role_override=int(CharacterRole::SUB_DPS);rover->member_state().buff_override=14;}
    }
    void ensure_grounded() {
        if(flying())wait_down();
        if(flying()){wait_until([&]{return !flying();},2,[&]{task.click(0.1,0.05);});wait_down();}
    }
    void hold_resonance_key(double duration) {
        if(!task.key_down('E'))throw std::runtime_error("Phoebe E hold failed");
        try {const double start=task.seconds();while(task.seconds()-start<duration && !task.stop_requested()){task.next_frame();}}
        catch(...){task.key_up('E');throw;}
        if(!task.key_up('E'))throw std::runtime_error("Phoebe E release failed");
    }
    bool check_middle_star() {
        if(star_available)return true;
        auto f=task.frame();auto box=original_hcenter_box(f,3840,2160,1890,2010,1915,2030);
        OriginalColor color=attribute==1?OriginalColor{160,190,220,250,235,255}:OriginalColor{240,255,240,255,240,255};
        if((attribute==1 || attribute==2) && original_color_percent(f,box,color)>0.25)star_available=true;
        return star_available;
    }
    int judge_forte() {
        auto f=task.frame();auto box=original_hcenter_box(f,3840,2160,1633,2004,2160,2014);
        const int count=attribute==1?4:2,step=box.width/count;const double min_amp=attribute==1?25:50;
        if(step<64 || box.height<=0)return 0;
        const OriginalColor color=attribute==1?OriginalColor{165,195,240,255,240,255}:OriginalColor{190,225,225,255,225,255};
        int forte=0,fail_count=0;
        for(int left=0;left+step<box.width;left+=step) {
            std::vector<double> profile(size_t(step),0);int white=0;
            for(int y=0;y<box.height;++y)for(int x=0;x<step;++x)
                if(original_color_hit(f,box.x+left+x,box.y+y,color)){++white;++profile[size_t(x)];}
            bool score=false;
            if(white && white!=step*box.height) {
                const double mean=double(white)/step;double amplitude=0;
                for(int k=1;k<step;++k) {
                    std::complex<double> value{};
                    for(int x=0;x<step;++x){const double a=-2*3.14159265358979323846*k*x/step;value+=(profile[size_t(x)]-mean)*std::complex<double>(std::cos(a),std::sin(a));}
                    amplitude=std::max(amplitude,std::abs(value));
                }
                score=amplitude>=min_amp;
            }
            if(fail_count==0){if(score)++forte;else ++fail_count;}else if(!score)++fail_count;
        }
        return forte;
    }
    bool confession_ready() {
        auto f=task.frame();
        ScreenBox box=scale_original_box({"phoebe_resonance",2560,1440,2110,1236,107,107},f.width,f.height);
        return original_masked_percent(f,box,{250,255,176,186,124,134},0.425,0.490)>0.15;
    }
    bool starflash_recover_with_e(bool finish_right=true) {
        if(!resonance_available())return false;
        hold_resonance_key(0.55);sleep(0.05);ensure_grounded();
        if(flying()){invalidate_form_charges();return false;}
        refill_form_charges();if(finish_right)continues_right_click(0.1);return true;
    }
    bool charge_starflash_until_full(bool finish_right=true,bool interval_click=false) {
        const double start=task.seconds();check_middle_star();bool recovered=false,tried=false;
        while(!is_forte_full() && !task.stop_requested()) {
            if(flying()) {
                auto* shore=task.find_character("ShoreKeeper");if(shore)shore->auto_dodge([&]{return flying();});
            }
            task.click(interval_click?0.1:-1);
            const double elapsed=task.seconds()-start;
            if(elapsed>5)return recovered;
            if(!tried && team==1 && elapsed>2) {
                tried=true;if(starflash_recover_with_e(finish_right)){recovered=true;task.next_frame();continue;}
            }
            check_combat();task.next_frame();
        }
        if(finish_right)task.right_click();return recovered;
    }
    bool starflash_combo() {
        bool recovered=false;if(!is_forte_full())recovered=charge_starflash_until_full();
        if(star_available && is_forte_full()) {
            bool cast=false,airborne=false;double outer_start=task.seconds();
            while(is_forte_full() && !task.stop_requested()) {
                if(task.seconds()-outer_start>2)break;
                if(!task.mouse_down())throw std::runtime_error("Phoebe heavy down failed");
                const double hold_start=task.seconds();
                try {
                    while(task.seconds()-hold_start<0.5 && !task.stop_requested()) {
                        if(!is_forte_full()){cast=true;break;}
                        if((airborne=flying()))break;
                        task.next_frame();
                    }
                }catch(...){task.mouse_up();throw;}
                task.mouse_up();
                if(airborne){ensure_grounded();outer_start=task.seconds();}
                check_combat();task.next_frame();
            }
            if(!is_forte_full())cast=true;
            if(cast){++starflash_count;consume_form_charge();}
        }
        return recovered;
    }
    bool absolution_or_confession(bool dodge_cancel=true,bool wait_team=true) {
        if(wait_team)wait_until([&]{return task.active_slot()>0;},3);
        if(known_form_charges()>0){star_available=true;return true;}
        if(attribute==2)hold_resonance_key(1.2);else {task.mouse_down();try{sleep(1.2);}catch(...){task.mouse_up();throw;}task.mouse_up();}
        if(flying())wait_until([&]{return !flying();},2,[&]{task.click(0.1,0.1);});
        if(flying()){invalidate_form_charges();return false;}
        if(dodge_cancel)continues_right_click(0.05);
        star_available=true;reset_action(false);refill_form_charges();++enter_status;return true;
    }
    bool liberation_confirmation_extended() {
        if(!wait_until([&]{return task.active_slot()<0;},1,[&]{task.click(0.1);}))return false;
        liber_no_effect_at=-1;
        task.in_liberation=true;
        return true;
    }
    bool click_liberation_reliable(bool require_forte_retry=false) {
        if(click_liberation(-1,true,0.1,0,false)){liber_no_effect_at=-1;return true;}
        if(liberation_confirmation_extended())return true;
        if(liberation_available()) {
            if(require_forte_retry){charge_starflash_until_full(false,true);if(!is_forte_full()){liber_no_effect_at=task.seconds();return false;}}
            if(click_liberation(-1,true,0.1,0,false) || liberation_confirmation_extended()){liber_no_effect_at=-1;return true;}
        }
        liber_no_effect_at=task.seconds();return false;
    }
    void record_liberation_cast(){++liberation_count;priority_liberation_cast=1;check_combat();}
    bool liberation_pending(){return star_available && !priority_liberation_cast;}
    bool recent_liberation_no_effect(){return liber_no_effect_at>=0 && task.seconds()-liber_no_effect_at<2;}
    int attack_until_con(double timeout,bool check_lib=true,double interval=0.1,bool require_forte=false) {
        const double deadline=task.seconds()+timeout;double con_since=-1;bool exit_seen=false;
        while(task.seconds()<deadline && !task.stop_requested()) {
            if(!task.target_present())return -1;
            if(get_current_con()>=1 && (!require_forte || is_forte_full())) {
                exit_seen=true;if(con_since<0)con_since=task.seconds();
                if(!(check_lib && liberation_pending()) || task.seconds()-con_since>=3 ||
                   !(liberation_available() || recent_liberation_no_effect()))break;
            }else con_since=-1;
            if(check_lib && !priority_liberation_cast && star_available && !flying() &&
               (liberation_available() || recent_liberation_no_effect())) {
                if(liberation_available() && click_liberation_reliable()){record_liberation_cast();continue;}
            }
            task.click();sleep(interval);
        }
        if(!task.target_present())return -1;
        return exit_seen?1:0;
    }
    int ensure_first_rotation_con() {
        first_rotation_done=true;if(team!=1 && zani_state()==1)return 0;
        return attack_until_con(10,star_available,0.1,team==1);
    }
    void try_liberation_after_starflash(int before) {
        if(starflash_count>before && !priority_liberation_cast && star_available && !flying() &&
           liberation_available() && click_liberation_reliable())record_liberation_cast();
    }
    void run_starflash_budget(bool entered) {
        if(!(entered || judge_forte()>0 || (star_available && is_forte_full()) ||
             (star_available && priority_liberation_cast) || (team==1 && attribute==2 && star_available)))return;
        const int before=starflash_count;starflash_combo();try_liberation_after_starflash(before);
    }
    void run_zani_linkage_handoff() {
        const int zs=zani_state();
        if(star_available && (judge_forte()>0 || is_forte_full()))starflash_combo();
        if(!resonance_available() && (zs==0 || (zani && zani->liberation_time_left()>3)))continues_normal_attack(1,0.15);
        else if(resonance_available() && team!=1 && first_rotation_done && !confession_ready())click_resonance(0,false,false,0,false,0,false);
    }
    void short_control_e() {
        if(!click_resonance(0,false,false,0,false,0.5,false).clicked)send_resonance_key();sleep(0.3);
    }
    void do_liber_insert() {
        wait_until([&]{return down();},2);sleep(0.3);
        if(team==2) {
            if(state.last_switch_in_time>0)sleep(std::max(0.0,intro_motion_freeze_duration-(task.seconds()-state.last_switch_in_time)),false);
            short_control_e();
        }else{starflash_combo();ensure_grounded();short_control_e();}
        ensure_grounded();if(state.buff_time()>0)state.last_buff_time=task.seconds();
        OriginalBaseChar::switch_next_char();
    }
    void finish_regular_rotation() {
        if(attribute==2) {
            if(team!=1 && starflash_count<2 && zani_state()!=1){const int before=starflash_count;starflash_combo();try_liberation_after_starflash(before);}
        }else click_resonance(0,false,true,0,false,0,false);
        const int con=ensure_first_rotation_con();if(con<0)return;
        if((team==1 || team==2) && (con==1 || is_con_full() || get_current_con()>=1)) {
            click_echo();force_switch_to(zani);return;
        }
        switch_next_char();
    }
    void do_regular_rotation() {
        state.last_outro_time=-1;const double start=task.seconds();sleep(0.01);
        if(star_available){wait_until([&]{return down();},2);sleep(0.3);}
        if(flying()){continues_normal_attack(0.1);switch_next_char();return;}
        if(attribute==2 && zani && zani->get_blazes()>=0.9){run_zani_linkage_handoff();switch_next_char();return;}
        if(!state.has_intro && star_available && !flying() && liberation_available() && click_liberation_reliable())record_liberation_cast();
        const double ui_wait=0.35-(task.seconds()-start);
        if(ui_wait>0 && star_available && judge_forte()==0)continues_normal_attack(ui_wait);
        const bool entered=absolution_or_confession(true,false);check_combat();
        if(entered && attribute==2)click_echo(0,0,0);
        if(star_available) {
            const bool blue_required=team==1 || team==2;bool blue_ready=!blue_required;
            if(!(blue_required && priority_liberation_cast)) {
                if(blue_required){charge_starflash_until_full(false,true);blue_ready=is_forte_full();}
                if(blue_ready) {
                    if(click_liberation_reliable(blue_required))record_liberation_cast();
                    else if(!priority_liberation_cast && liberation_available() && !flying()) {
                        if(blue_required){charge_starflash_until_full(false,true);blue_ready=is_forte_full();}
                        if(blue_ready && click_liberation_reliable(blue_required))record_liberation_cast();
                    }
                }
            }
        }
        if(attribute==2 && !first_rotation_done){click_resonance(0,false,false,0,false,0.5,false);sleep(0.3);}
        run_starflash_budget(entered);finish_regular_rotation();
    }
    void switch_next_char(bool free_intro=false,bool low_con=false) override {
        if((team==1 || team==2) && (is_con_full() || get_current_con()>=1)){click_echo();force_switch_to(zani);return;}
        OriginalBaseChar::switch_next_char(free_intro,low_con);
    }
    bool f_break(bool=false,bool=false) override {return false;}
    bool is_forte_full() override {return star_available?is_mouse_forte_full():OriginalBaseChar::is_forte_full();}
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(state.force_switch_me)return 400;
        for(int slot=1;slot<=3;++slot)if(auto* member=task.member_at(slot))
            if(member!=&state && member->force_switch_me)return 0;
        if(!has_intro && state.last_outro_time>0 && time_elapsed_accounting_for_freeze(state.last_outro_time,true)<4.5)return 0;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();attribute=0;team=0;star_available=false;zani=nullptr;rover=nullptr;first_rotation_done=false;rover_form_pending=false;invalidate_form_charges();enter_status=0;starflash_count=0;liberation_count=0;outros=0;priority_liberation_cast=0;state.force_switch_me=false;}
    using OriginalBaseChar::OriginalBaseChar;
    int outro_count() const override {return outros;}
    void reset_action(bool new_rotation=true) override {
        if(attribute==2 && new_rotation){enter_status=0;starflash_count=0;liberation_count=0;outros=0;priority_liberation_cast=0;}
    }
    void on_switch_out(bool con_full,double) override {if((team==1 || team==2) && con_full)++outros;}
    bool ready_for_linkage() override {if(team==0 || rover_form_pending)decide_teammate();return false;}
    void do_perform() override {
        if(team==0 || rover_form_pending)decide_teammate();
        if(!zani)zani=task.find_character("Zani");
        const bool insert=zani && (team==1?zani->consume_insert_handoff():team==2 && zani_state()==1);
        if(insert){do_liber_insert();return;}
        if(zani && zani_state()==1){force_switch_to(zani);return;}
        do_regular_rotation();
    }
};
