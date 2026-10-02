#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Zani.py
// Port source SHA256: fab21a467c00a7ad2d259add9e51a3ef097d653f4b42b06ed88e92f0976c82e7
#include "OriginalBaseChar.h"

// OK-WW Zani.py: crisis protocol, Nightfall phases and Phoebe/Rover insert axis.
class ZaniOriginal final : public OriginalBaseChar {
    OriginalBaseChar* phoebe = nullptr;
    OriginalBaseChar* rover = nullptr;
    bool rover_form_pending = false;
    int no_target_streak = 0;
    double blazes_threshold = -1, chair_time = -1, blazes = -1;
    double crisis_time = -1, nightfall_time = -1, liberation_time = -1;
    bool zanfei_guang = false, in_liberation = false;
    int liber_phase = 0, liber_handoff_token = 0, zani_state = 0;
    enum Result { TIMEOUT=0, FORTE_FULL=1, DONE=3, FAILED=4, INTERRUPTED=5 };

    double current_resonance() { return task.frame().resonance_white; }
    bool feature_scaled(std::string_view name,int sw,int sh,int l,int t,int r,int b,double threshold) {
        auto frame=task.frame();
        return task.feature_at && task.feature_at(name,original_hcenter_box(frame,sw,sh,l,t,r,b),threshold);
    }
    int zani_wait(const std::function<bool()>& condition,double timeout,double settle=0,
                  const std::function<bool()>& interrupt={},const std::function<void()>& post={}) {
        if(timeout<=0)return TIMEOUT;
        const double start=task.seconds(); double stable=-1; bool once=true;
        while(task.seconds()-start<timeout && !task.stop_requested()) {
            if(condition()) {
                if(settle==0)return FORTE_FULL;
                if(stable<0)stable=task.seconds();
                else if(task.seconds()-stable>=settle)return FORTE_FULL;
            } else stable=-1;
            if(interrupt && interrupt())return INTERRUPTED;
            if(once){check_combat();once=false;}
            if(post)post();
            task.next_frame();
        }
        return TIMEOUT;
    }
    void decide_teammate() {
        phoebe=task.find_character("Phoebe"); rover=task.find_character("Rover");
        blazes_threshold=phoebe?0.6:0.4;
        rover_form_pending=rover && rover->known_form()<0;
        zanfei_guang=phoebe && rover;
        state.linked_phoebe=phoebe!=nullptr; state.linked_rover=zanfei_guang;
        if(zanfei_guang){rover->member_state().role_override=int(CharacterRole::SUB_DPS);rover->member_state().buff_override=14;}
    }
    void update_blazes() {
        auto f=task.frame(); auto box=original_hcenter_box(f,3840,2160,1627,2014,2176,2017);
        blazes=std::ceil(original_color_percent(f,box,{171,201,239,255,231,257})*100.0)/100.0;
    }
    bool check_liber() {
        if(task.active_slot()>0) {
            if(feature_scaled("box_target_enemy_inner",2560,1440,1909,1274,1957,1322,0.75))in_liberation=false;
            else if(feature_scaled("box_target_enemy_inner",2560,1440,1779,1273,1830,1322,0.75))in_liberation=true;
        }
        state.linkage_in_liberation=in_liberation;
        return in_liberation;
    }
    bool nightfall_ready(double threshold=0.15) {
        auto f=task.frame(); auto box=original_hcenter_box(f,2560,1440,1853,1233,1964,1344);
        return original_masked_percent(f,box,{205,225,245,255,245,255},0.425,0.490)>threshold;
    }
    double nightfall_time_left() {
        if(nightfall_time<=0)return 0;
        double left=2.2-time_elapsed_accounting_for_freeze(nightfall_time,true);
        if(left<=0)nightfall_time=-1;
        return left;
    }
    double crisis_time_left() {
        return crisis_time<=0?0:1.6-time_elapsed_accounting_for_freeze(crisis_time,true);
    }
    void wait_resonance_not_gray(bool send_click=false,bool liber_check=false,double timeout=2.5) {
        zani_wait([&]{return current_resonance()!=0;},timeout,0.1,
            liber_check?std::function<bool()>([&]{return liberation_time_left()<1;}):std::function<bool()>(),
            send_click?std::function<void()>([&]{task.click(0.1);}):std::function<void()>());
    }
    int wait_forte_full(double timeout=1,bool send_click=false) {
        if(timeout<=0)return DONE;
        int result=zani_wait([&]{return is_e_forte_full();},timeout,0,[&]{return flying();},
            send_click?std::function<void()>([&]{task.click(0.1);}):std::function<void()>());
        return result==INTERRUPTED?INTERRUPTED:result?FORTE_FULL:DONE;
    }
    int standard_defense_protocol_combo() {
        if(is_e_forte_full())return FORTE_FULL;
        if(resonance_available()) {
            click_resonance(0,false,false);sleep(0.2);
            const double end=task.seconds()+5;
            while(!is_e_forte_full() && task.seconds()<end && !task.stop_requested()){task.click();sleep(0.1);}
            return DONE;
        }
        return FAILED;
    }
    int basic_attack_breakthrough() {
        double wait_chair=1.2; int result=DONE;
        if(chair_time==-1) {
            result=standard_defense_protocol_combo();
            if(result==FAILED) {
                continues_normal_attack(0.6);wait_chair=1.15;
                result=wait_forte_full(0.85,true);if(result!=DONE)return result;
            } else if(result==FORTE_FULL)return result;
        } else {wait_chair-=task.seconds()-chair_time;chair_time=-1;}
        result=wait_forte_full(wait_chair);if(result!=DONE)return result;
        continues_normal_attack(0.2);return result;
    }
    bool crisis_response_protocol_combo() {
        check_combat();
        if(!is_e_forte_full())for(int attempt=0;attempt<2;++attempt) {
            if(is_e_forte_full() || basic_attack_breakthrough()==FORTE_FULL)break;
        }
        zani_wait([&]{return is_e_forte_full();},2,0.15);
        if(!send_resonance_key())throw std::runtime_error("Zani enhanced E failed");
        crisis_time=task.seconds();state.crisis_time=crisis_time;return true;
    }
    void wait_crisis_protocol_end() {
        if(crisis_time_left()<=0)return;
        if(last_res>0 && time_elapsed_accounting_for_freeze(last_res)<5)
            zani_wait([&]{return crisis_time_left()<=0;},2);
        else wait_resonance_not_gray();
    }
    bool wait_enhanced_e_commit(double before_blazes) {
        double elapsed=crisis_time<=0?-1:time_elapsed_accounting_for_freeze(crisis_time,true);
        if(elapsed>=0 && elapsed<2) {
            zani_wait([&]{return time_elapsed_accounting_for_freeze(crisis_time,true)>=2;},3);
            elapsed=time_elapsed_accounting_for_freeze(crisis_time,true);
        }
        while(blazes<=before_blazes && elapsed>=2 && elapsed<4.5 && !task.stop_requested()) {
            sleep(0.4);update_blazes();elapsed=time_elapsed_accounting_for_freeze(crisis_time,true);
        }
        return elapsed>=2 && blazes>before_blazes;
    }
    bool click_liber2() {
        const double start=task.seconds();double cast_started=-1;bool send=true;task.in_liberation=true;
        while(!task.stop_requested()) {
            const double now=task.seconds();
            if(now>=start+6){
                task.in_liberation=false;in_liberation=false;check_liber();if(!in_liberation)update_blazes();return false;
            }
            if(feature_scaled("box_target_enemy_inner",2560,1440,1909,1274,1957,1322,0.75))break;
            if(current_resonance()==0)send=true;
            else if(cast_started>=0 && task.seconds()-cast_started>1.5)send=false;
            if(send){send_liberation_key();if(cast_started<0)cast_started=now;}
            task.next_frame();
        }
        if(task.stop_requested()) {
            task.in_liberation=false;in_liberation=false;check_liber();if(!in_liberation)update_blazes();return false;
        }
        task.in_liberation=false;
        const bool confirmed=cast_started>=0 && task.seconds()-cast_started>=2.25;
        if(confirmed && task.add_freeze_duration)task.add_freeze_duration(task.seconds()-2.25,2.25,0);
        in_liberation=false;state.linkage_in_liberation=false;blazes=-1;liberation_time=-1;zani_state=0;
        return confirmed;
    }
    bool should_end_liberation(bool time_only=false,bool force_finish=false) {
        const double left=liberation_time_left(); double smash_left=0;
        if(!time_only && liber_phase==3 && nightfall_time>0 && task.seconds()-nightfall_time<5.2)
            smash_left=nightfall_time_left();
        if(force_finish) {
            if(smash_left>0.12){sleep(smash_left-0.12,false);check_liber();if(!in_liberation)return false;}
            return true;
        }
        if(left<1)return true;
        if(time_only)return false;
        if(zanfei_guang && liber_phase==3) {
            if(smash_left>0.12){sleep(smash_left-0.12,false);check_liber();if(!in_liberation)return false;}
            return false;
        }
        if(nightfall_ready())return false;
        if(!is_mouse_forte_full()) {
            if(liber_phase!=3)return false;
            if(smash_left>0.12){sleep(1.4,false);check_liber();if(!in_liberation)return false;}
            return true;
        }
        return false;
    }
    bool nightfall_combo(bool cancel=false,double acquire_timeout=7,bool dodge_cancel=true) {
        const double start=task.seconds();
        if(!nightfall_ready()) {
            while((!nightfall_ready() || task.seconds()-start<1.6) && !task.stop_requested()) {
                task.click();
                if(task.seconds()-start>acquire_timeout || !in_liberation)return false;
                if(should_end_liberation(true))return click_liber2();
                check_combat();task.next_frame();
            }
        }
        continues_normal_attack(0.5);
        if(cancel) {
            const double start=task.seconds();
            while(nightfall_ready(0.035) && task.seconds()-start<=2.5 && !task.stop_requested()){task.click();task.next_frame();}
            sleep(0.25,false);if(dodge_cancel)continues_right_click(0.1);
        } else nightfall_time=task.seconds();
        return false;
    }
    void start_liberation() {
        liber_handoff_token=0;crisis_time=-1;state.crisis_time=-1;zani_state=1;in_liberation=true;
        liberation_time=task.seconds();check_liber();continues_right_click(0.05);continues_normal_attack(0.15);
    }
    void handoff_insert(int next_phase) {liber_phase=next_phase;++liber_handoff_token;switch_next_char();}
    void liberation_followup(bool zanfei) {
        start_liberation();
        if(zanfei){nightfall_combo(true,3.5,false);handoff_insert(2);return;}
        nightfall_combo(true);sleep(0.1);if(is_mouse_forte_full())nightfall_combo();
    }
    bool try_liberation(bool wait_crisis=false,bool zanfei=false) {
        if(wait_crisis) {
            const double before=blazes;wait_crisis_protocol_end();
            if(zanfei)update_blazes();
            if(!wait_enhanced_e_commit(before))return false;
        }
        if(echo_available())click_echo(0,0,0);
        if(click_liberation(-1,true)){liberation_followup(zanfei);return true;}
        return false;
    }
    void switch_to_phoebe_full() {
        if(!phoebe)phoebe=task.find_character("Phoebe");
        if(!phoebe){switch_next_char();return;}
        phoebe->reset_action();liber_handoff_token=0;liber_phase=0;force_switch_to(phoebe);
    }
    void complete_liberation_to_phoebe(int next_phase=0) {
        if(!click_liber2()){switch_next_char();return;}
        liber_phase=next_phase;switch_to_phoebe_full();
    }
    void run_phase3(bool zanfei) {
        if(should_end_liberation()){complete_liberation_to_phoebe();return;}
        nightfall_combo();
        if(zanfei) {
            check_liber();
            if(!in_liberation){liber_phase=0;switch_to_phoebe_full();return;}
            if(should_end_liberation(false,true)){complete_liberation_to_phoebe();return;}
            liber_phase=0;switch_next_char();return;
        }
        while(in_liberation && liber_phase==3 && !task.stop_requested()) {
            if(should_end_liberation()){complete_liberation_to_phoebe();return;}
            if(!is_mouse_forte_full() && !nightfall_ready()) {
                if(should_end_liberation(false,false)){complete_liberation_to_phoebe();return;}
                continues_normal_attack(0.3);check_liber();
                if(!in_liberation){liber_phase=0;switch_next_char();return;}
                continue;
            }
            nightfall_combo();check_liber();
            if(!in_liberation){liber_phase=0;switch_to_phoebe_full();return;}
        }
        switch_next_char();
    }
    void do_liberation(bool zanfei) {
        if(liber_phase==3){run_phase3(zanfei);return;}
        if(should_end_liberation()){complete_liberation_to_phoebe();return;}
        const bool finished=nightfall_combo();
        if(zanfei) {
            if(liber_phase==2)handoff_insert(3);else switch_next_char();
        } else {
            if(finished){switch_to_phoebe_full();return;}
            liber_phase=liber_phase==2?3:2;switch_next_char();
        }
    }
    void do_non_liberation(bool zanfei) {
        zani_state=0;crisis_time=-1;state.crisis_time=-1;
        if(zanfei)liber_phase=0;
        update_blazes();bool forte=is_e_forte_full(),res=current_resonance()>0.05,lib=liberation_available();
        if(state.has_intro && blazes>=1 && !lib){sleep(0.2,false);lib=liberation_available();res=current_resonance()>0.05;}
        const double predicted=blazes+0.1;
        if((zanfei || blazes>=1) && lib) {
            bool success=try_liberation(false,zanfei);
            if(!success){sleep(0.1);success=try_liberation(false,zanfei);}
            if(zanfei)return;
            if(success)liber_phase=2;
            switch_next_char();return;
        }
        if(zanfei) {
            if(forte || res){crisis_response_protocol_combo();try_liberation(true,true);return;}
            normal_attack_until_can_switch();switch_next_char();return;
        }
        if(forte) {
            const bool should_liberate=predicted>=blazes_threshold;
            crisis_response_protocol_combo();
            if(should_liberate && liberation_available() && try_liberation(true))liber_phase=2;
            switch_next_char();return;
        }
        if(res) {
            crisis_response_protocol_combo();
            if(blazes>=blazes_threshold && liberation_available() && try_liberation(true))liber_phase=2;
            switch_next_char();return;
        }
        normal_attack_until_can_switch();switch_next_char();
    }
    void switch_next_char(bool free_intro=false,bool low_con=false) override {
        if(!zanfei_guang && is_con_full() && phoebe){force_switch_to(phoebe);return;}
        OriginalBaseChar::switch_next_char(free_intro,low_con);
    }
    bool f_break(bool=false,bool=false) override {return false;}
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(state.force_switch_me)return 401;
        for(int slot=1;slot<=3;++slot)if(auto* member=task.member_at(slot))
            if(member!=&state && member->force_switch_me)return 0;
        if(in_liberation)return 400;
        if(!zanfei_guang && phoebe && has_intro && from!="Phoebe")return 0;
        if(has_intro && crisis_time_left()>0)return 0;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();phoebe=nullptr;rover=nullptr;rover_form_pending=false;no_target_streak=0;blazes_threshold=-1;chair_time=-1;zanfei_guang=false;state.force_switch_me=false;in_liberation=false;liber_phase=0;liber_handoff_token=0;state.linkage_in_liberation=false;state.linked_phoebe=false;state.linked_rover=false;}
    ZaniOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OriginalBaseChar(io,member){intro_motion_freeze_duration=1.42;}
    bool use_rover_linkage() override {return zanfei_guang;}
    bool consume_insert_handoff() override {
        if(!in_liberation || (liber_phase!=2 && liber_phase!=3) || liber_handoff_token<=0)return false;
        liber_handoff_token=0;return true;
    }
    void discard_insert_handoff() override {liber_handoff_token=0;}
    double get_blazes() const override {return blazes;}
    double liberation_time_left() override {
        return !in_liberation || liberation_time<=0?0:20-time_elapsed_accounting_for_freeze(liberation_time);
    }
    int get_state() override {
        if(zani_state==1 && liberation_time_left()<=0){blazes=-1;zani_state=0;}
        return zani_state;
    }
    bool wait_switch() override {return state.has_intro && nightfall_time_left()>0 && liberation_time_left()>=2;}
    bool ready_for_linkage() override {
        if(blazes_threshold<0 || rover_form_pending)decide_teammate();
        if(state.is_current_char)update_blazes();
        state.linkage_in_liberation=in_liberation;
        return blazes>=blazes_threshold || (phoebe && phoebe->outro_count()>=1 && blazes>=0.4);
    }
    void do_perform() override {
        if(blazes_threshold<0 || rover_form_pending)decide_teammate();
        if(!in_liberation && !task.has_target()) {
            if(++no_target_streak>=3){no_target_streak=0;throw OriginalNotInCombat("Zani: no combat target");}
            return;
        }
        no_target_streak=0;
        if(!task.has_levitator && state.has_intro)continues_normal_attack(std::max(0.0,intro_motion_freeze_duration-(state.last_switch_in_time>0?task.seconds()-state.last_switch_in_time:0)));
        else wait_down();
        check_liber();
        if(in_liberation){zani_state=1;do_liberation(zanfei_guang);}
        else do_non_liberation(zanfei_guang);
    }
};
