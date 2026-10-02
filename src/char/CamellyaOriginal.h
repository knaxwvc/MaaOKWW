#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Camellya.py
// Port source SHA256: c05fb2a0724f0f3b7f6b5f5e8c6cbaf814cfc7572f0f1d0ec27be91c3e3f682b
#include "OriginalBaseChar.h"
class CamellyaOriginal final : public OriginalBaseChar {
    bool waiting_for_forte_drop=false;double forte_drop_timestamp=0,last_forte=0;
    std::vector<double> forte_diff_buffer;
    bool ephemeral_ready(){const auto f=task.frame();return original_masked_nonblack_percent(f,original_hcenter_box(f,2560,1440,2110,1236,2217,1343),{168,179,71,82,234,245},0.395,0.496)>0.1;}
    void ephemeral_cast(){check_combat();while(ephemeral_ready()&&!task.stop_requested()){send_resonance_key();sleep(0.1);}sleep(1.1);}
    double get_forte(bool budding=false){
        const auto f=task.frame();const auto box=original_hcenter_box(f,3840,2160,1630,2002,2176,2004);
        const double percent=original_stripe_percent(f,box,budding?OriginalColor{168,225,161,213,220,255}:OriginalColor{127,163,46,93,193,255});
        return percent>=0?std::floor(percent*1000+0.5)/1000:percent;
    }
    int should_retry_heavy_attack(bool budding=false){
        const double current=get_forte(budding);if(current<0)return -1;
        const double diff=last_forte-current;
        if(!waiting_for_forte_drop && diff>=0&&diff<=0.01){waiting_for_forte_drop=true;forte_drop_timestamp=task.seconds();forte_diff_buffer.clear();}
        if(waiting_for_forte_drop){forte_diff_buffer.push_back(diff);if(std::accumulate(forte_diff_buffer.begin(),forte_diff_buffer.end(),0.0)>0.01)waiting_for_forte_drop=false;}
        if(waiting_for_forte_drop && time_elapsed_accounting_for_freeze(forte_drop_timestamp)>0.6){waiting_for_forte_drop=false;task.mouse_up();sleep(0.1,false);task.mouse_down();sleep(0.1,false);}
        last_forte=current;return 0;
    }
    void check_target(bool heavy=false){if(!task.has_target()){if(heavy)task.mouse_up();check_combat();task.next_frame();if(heavy)task.mouse_down();}}
    void camellya_heavy(double duration,bool until_con_full=false){
        last_forte=0;bool freeze=false;double freeze_time=0;task.mouse_down();const double start=task.seconds();
        try {while(task.seconds()-start<duration&&!task.stop_requested()){
            const double forte=get_forte();if((until_con_full&&is_con_full())||(forte>=0&&forte<=0.01))break;
            check_target(true);task.next_frame();if(freeze&&task.seconds()-freeze_time>=0.2)freeze=false;
            if(!freeze&&should_retry_heavy_attack()<0){freeze=true;freeze_time=task.seconds();}
        }sleep(0.1,false);}catch(...){task.mouse_up();throw;}task.mouse_up();waiting_for_forte_drop=false;
    }
    bool click_echo(double=0,double=0,double=1) override {if(!echo_available())return false;send_echo_key();return true;}
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro)return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    void reset_state() override {OriginalBaseChar::reset_state();waiting_for_forte_drop=false;}
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        if(state.has_intro){continues_normal_attack(1.2);sleep(0.1);camellya_heavy(4.6,true);}
        if(liberation_available())click_liberation(0.82);
        const double con=get_current_con();double loop_time=con<0.82?1.1:4.6;
        if(con<0.82&&resonance_available())click_resonance();
        double budding_start=task.seconds(),freeze_time=0;bool budding=false,heavy=false,freeze=false;last_forte=0;
        try {while((task.seconds()-budding_start<loop_time || find_feature("camellya_budding",0.7))&&!task.stop_requested()){
            if(!budding){
                if(ephemeral_ready()&&is_con_full()){ephemeral_cast();budding=true;}
                else {task.click(0.1);const double current_con=get_current_con();
                    if(current_con<0.82){if(!is_con_full()){click_echo();return switch_next_char();}if(loop_time<3.1)loop_time+=1;}}
                if(budding){check_target();budding_start=task.seconds();loop_time=5.1;}
            }
            if(budding){if(!heavy){heavy=true;task.mouse_down();}
                if(task.seconds()-budding_start<1.5&&liberation_available()&&click_liberation()&&heavy){task.mouse_up();sleep(0.2,false);task.mouse_down();}}
            check_target(heavy);task.next_frame();if(freeze&&task.seconds()-freeze_time>=0.2)freeze=false;
            if(!freeze&&heavy&&should_retry_heavy_attack(budding)<0){freeze=true;freeze_time=task.seconds();}
        }}catch(...){if(heavy)task.mouse_up();throw;}
        waiting_for_forte_drop=false;if(heavy){task.mouse_up();sleep(0.1);}if(budding){click_resonance();sleep(0.1);}click_echo();switch_next_char();
    }
};
