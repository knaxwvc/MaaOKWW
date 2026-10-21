#pragma once
#include <algorithm>
#include <chrono>
#include <functional>
#include <stdexcept>
#include <string_view>
#include <thread>
#include "../combat/CombatCheck.h"
#include "../combat/OriginalVision.h"
#include "../task/OriginalSwitch.h"
#include "../task/OriginalTiming.h"
#include "../task/HudObservation.h"

class OriginalBaseChar;
class OriginalNotInCombat : public std::runtime_error {
public:
    explicit OriginalNotInCombat(const char* reason):std::runtime_error(reason){}
};
class OriginalHudRetry : public OriginalNotInCombat {
public:
    explicit OriginalHudRetry(const char* reason):OriginalNotInCombat(reason){}
};
class OriginalCombatStopped : public std::runtime_error {
public:
    OriginalCombatStopped():std::runtime_error("Combat stopped"){}
};
class OriginalHudUnavailable : public std::runtime_error {
public:
    OriginalHudUnavailable():std::runtime_error("Combat HUD is unreadable; input suspended"){}
};
class OriginalSoloSuspended : public std::runtime_error {
public:
    OriginalSoloSuspended():std::runtime_error("Selected solo character HUD is not active"){}
};

struct OriginalFeatureObservation {
    bool found=false;
    ScreenBox box{};
    double confidence=-1;
    std::string name;
};

struct OriginalCombatIO {
    std::function<FrameState()> frame;
    std::function<bool(int,double,double,double)> send_key_action;
    std::function<bool(int)> key_down_action;
    std::function<bool(int)> key_up_action;
    std::function<bool(int,double,double)> click_action;
    std::function<bool()> mouse_down;
    std::function<bool()> mouse_up;
    std::function<bool()> target_present;
    std::function<bool()> has_target;
    std::function<bool()> is_open_world_auto_combat;
    std::function<bool()> check_f_break_action;
    std::function<int()> team_size;
    std::function<bool(int)> select_character;
    std::function<OriginalBaseChar*(std::string_view)> find_character;
    std::function<OriginalSwitchCharacter*(int)> member_at;
    std::function<bool(std::string_view,std::string_view,double)> feature_in_box;
    std::function<bool(std::string_view,double)> feature;
    std::function<bool(std::string_view,ScreenBox,double)> feature_at;
    std::function<bool()> need_fast_perform;
    std::function<int()> active_slot;
    std::function<double(char)> cooldown_remaining;
    std::function<double(char,int)> cooldown_for_slot;
    std::function<bool()> find_mouse_forte;
    std::function<bool()> find_e_forte;
    std::function<bool(bool,bool)> switch_next_char;
    std::function<bool()> last_switch_had_intro;
    std::function<bool()> stop_requested;
    std::function<double()> seconds;
    std::function<void(double,double,double)> add_freeze_duration;
    std::function<double(double,bool)> elapsed_accounting_for_freeze;
    std::function<void(double,bool)> pause;
    std::function<void()> next_frame;
    std::function<double()> frame_captured_at;
    std::function<double()> frame_capture_ms;
    std::function<void()> guard_solo_input;
    std::function<bool()> hud_readable,capture_valid;
    std::function<void()> require_combat_hud;
    std::function<std::uint64_t()> frame_sequence;
    std::function<void(std::string_view)> observation_diagnostic;
    std::function<OriginalFeatureObservation(std::string_view,const ScreenBox*,double,const FrameState*)> recognize_feature;
    std::function<FrameState(std::string_view)> template_frame;
    std::function<bool()> reload_characters;
    std::function<bool(int,double,double,double)> send_physical_key;
    std::function<bool(int)> physical_key_down,physical_key_up;
    std::function<int(char)> configured_key;
    std::function<int()> observed_team_count;
    std::function<void(int)> confirm_current_character;
    std::function<void(double)> raw_sleep;
    bool solo_mode = false;
    bool in_liberation = false;
    bool skip_combat_check = false;
    bool can_break = false;
    double last_break_check_time = 0;
    bool send_key(int key,double down_time=0.02,double interval=-1,double after_sleep=0) {
        if(solo_mode && key>='1' && key<='3')return false;
        if(guard_solo_input)guard_solo_input();
        return send_key_action(key,down_time,interval,after_sleep);
    }
    bool click(double interval=-1,double after_sleep=0) {if(guard_solo_input)guard_solo_input();return click_action(0,interval,after_sleep);}
    bool right_click(double interval=-1,double after_sleep=0) {if(guard_solo_input)guard_solo_input();return click_action(1,interval,after_sleep);}
    bool middle_click(double interval=-1,double after_sleep=0) {if(guard_solo_input)guard_solo_input();return click_action(2,interval,after_sleep);}
    bool key_down(int key,double after_sleep=0) {
        if(solo_mode && key>='1' && key<='3')return false;
        if(guard_solo_input)guard_solo_input();
        const bool result=key_down_action(key);if(after_sleep>0)pause(after_sleep,true);return result;
    }
    bool key_up(int key,double after_sleep=0) {
        const bool result=key_up_action(key);if(after_sleep>0)pause(after_sleep,true);return result;
    }
    bool jump(double after_sleep=0.01){return send_key(VK_SPACE,0.02,-1,after_sleep);}
    double combat_start=0;
    bool use_liberation = true;
    bool has_levitator = false;
    bool chisa_dps = false;
    bool iuno_c6 = false;
    bool hsin_unison = false;
    bool aemeath_mech_intro = false;
    bool aemeath_s1 = false;
    bool cartethyia_low_erosion = false;
    bool hiyuki_extended = false;
    bool auto_combat_task = false;
};

struct OriginalResonanceResult {
    bool clicked = false;
    double duration = 0;
    bool animated = false;
};

// Typed boundary for Maa device IO. All character decisions are generated from
// the pinned official sources in src/official/generated.
class OriginalBaseChar {
protected:
    OriginalCombatIO& task;
    OriginalSwitchCharacter& state;
public:
    OriginalBaseChar(OriginalCombatIO& io,OriginalSwitchCharacter& member):task(io),state(member){}
    virtual ~OriginalBaseChar()=default;
    virtual void perform()=0;
    virtual void do_perform()=0;
    virtual void reset_state()=0;
    virtual void on_combat_end()=0;
    virtual void switch_out(bool,double)=0;
    virtual int get_switch_priority(OriginalBaseChar*,bool,bool)=0;
    virtual bool skip_combat_check()=0;
    virtual bool wait_switch()=0;
    virtual double intro_freeze_seconds()const=0;
    virtual double current_con_for_switch()=0;
    virtual bool con_full_for_switch()=0;
    virtual void break_on_switch()=0;
    virtual void attack_without_switch(double)=0;
    virtual bool liberation_available()=0;
    virtual void sync_metadata()=0;
    OriginalSwitchCharacter& member_state(){return state;}
};
