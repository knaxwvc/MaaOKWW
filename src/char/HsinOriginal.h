#pragma once
// Port source: https://github.com/ok-oldking/ok-wuthering-waves/blob/36c557437de745cdef506bcfa148569d3e09cfcf/src/char/Hsin.py
// Port source SHA256: 4bef74d4e4d5ecdcac77e1ec3ff14eaa690aba217e9e316c5badfdc71530a26f
#include "OriginalBaseChar.h"

// Source: https://github.com/ok-oldking/ok-wuthering-waves/blob/36c557437de745cdef506bcfa148569d3e09cfcf/src/char/Hsin.py
class HsinOriginal final : public OriginalBaseChar {
    bool lib2_cast_this_turn=false;
    bool lib() {
        const bool is_lib2=find_feature("hsin_lib2",0.7);
        const bool has_feature=is_lib2 || find_feature("hsin_lib1",0.7);
        const bool available=liberation_available();
        if(!has_feature || !available)return false;
        const bool liberated=click_liberation(-1,false,0);
        if(liberated && is_lib2)lib2_cast_this_turn=true;
        return liberated;
    }
    bool heavy_available() {return find_feature("hsin_h1",0.7) || find_feature("hsin_h2",0.7);}
    bool heavy_wait_highlight_down(double timeout) {
        check_combat();
        if(!task.mouse_down())throw std::runtime_error("Maa Hsin heavy down failed");
        bool result=false;
        try{result=wait_until([&]{return !heavy_available();},timeout);}
        catch(...){task.mouse_up();throw;}
        if(!task.mouse_up())throw std::runtime_error("Maa Hsin heavy up failed");
        sleep(0.01);return result;
    }
    bool handle_heavy(double start,double duration) {
        if(!heavy_available())return false;
        const double remaining=duration-time_elapsed_accounting_for_freeze(start);
        if(remaining<=0)return false;
        heavy_wait_highlight_down(std::min(1.2,remaining));return true;
    }
    void perform_everything() {
        const double duration=state.has_intro?12:6,start=task.seconds();
        while(time_elapsed_accounting_for_freeze(start)<duration && !task.stop_requested()){
            cycle_start();
            OriginalResonanceResult resonance;
            if(resonance_available())resonance=click_resonance(0,false,true,0.5,false,0);
            if(resonance.clicked){}
            else if(lib()){if(lib2_cast_this_turn)return;}
            else if(handle_heavy(start,duration)){}
            else if(!click_echo(0))task.click();
            cycle_sleep();
        }
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {lib2_cast_this_turn=false;perform_everything();switch_next_char();}
};
