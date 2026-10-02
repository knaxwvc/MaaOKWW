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

class OriginalBaseChar;
class OriginalNotInCombat : public std::runtime_error {
public:
    explicit OriginalNotInCombat(const char* reason):std::runtime_error(reason){}
};
class OriginalHudRetry : public OriginalNotInCombat {
public:
    explicit OriginalHudRetry(const char* reason):OriginalNotInCombat(reason){}
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
    bool in_liberation = false;
    bool skip_combat_check = false;
    bool can_break = false;
    double last_break_check_time = 0;
    bool send_key(int key,double down_time=0.02,double interval=-1,double after_sleep=0) {
        return send_key_action(key,down_time,interval,after_sleep);
    }
    bool click(double interval=-1,double after_sleep=0) {return click_action(0,interval,after_sleep);}
    bool right_click(double interval=-1,double after_sleep=0) {return click_action(1,interval,after_sleep);}
    bool middle_click(double interval=-1,double after_sleep=0) {return click_action(2,interval,after_sleep);}
    bool key_down(int key,double after_sleep=0) {
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
};

struct OriginalResonanceResult {
    bool clicked = false;
    double duration = 0;
    bool animated = false;
};

// BaseChar helper methods keep the original sequence and public names so each
// src/char/*.h can be compared line by line with the corresponding OK-WW file.
// All screen reads and input go through MaaFramework callbacks above.
class OriginalBaseChar {
protected:
    OriginalCombatIO& task;
    OriginalSwitchCharacter& state;
    double last_perform = 0;
    double last_res = -1;
    double last_echo = -1;
    double last_liberation = -1;
    double intro_motion_freeze_duration = 0.9;
    double cycle_start_time = 0;
    bool check_f_on_switch = true;
    static constexpr double skill_timeout = 15.0;
    void sleep(double seconds,bool check_combat=true) {
        if(!check_combat)task.skip_combat_check=true;
        task.pause(seconds,true);task.skip_combat_check=false;
    }
    void raw_sleep(double seconds){original_sleep_for(seconds);}
    void check_combat() {
        if (task.stop_requested()) throw std::runtime_error("Combat stopped");
        if (!task.skip_combat_check && !task.in_liberation && !task.target_present()) throw OriginalNotInCombat("Target no longer in combat");
    }
    double time_elapsed_accounting_for_freeze(double start, bool intro_motion_freeze = false) {
        return task.elapsed_accounting_for_freeze ?
            task.elapsed_accounting_for_freeze(start, intro_motion_freeze) : task.seconds() - start;
    }
    bool has_cd(char key) {
        return (state.is_current_char || !task.cooldown_for_slot ? task.cooldown_remaining(key) :
                task.cooldown_for_slot(key,state.index+1)) > 0.2;
    }
    bool available(char key, bool check_color, bool check_cd = true) {
        if(!state.is_current_char) return !has_cd(key);
        const FrameState frame = task.frame();
        const double white = key == 'E' ? frame.resonance_white :
                             key == 'Q' ? frame.echo_white : frame.liberation_white;
        return (!check_color || white > 0) && (!check_cd || !has_cd(key));
    }
    virtual bool resonance_available() { return available('E', false); }
    virtual bool echo_available() { return available('Q', false); }
    virtual bool liberation_available() { return available('R', true); }
    virtual bool is_forte_full() { return task.frame().forte_white > 0.08; }
    bool is_mouse_forte_full() { return task.find_mouse_forte(); }
    bool is_e_forte_full() { return task.find_e_forte && task.find_e_forte(); }
    void force_switch_to(OriginalBaseChar* target) {
        if(!target)return OriginalBaseChar::switch_next_char();
        auto clear=[&](){for(int slot=1;slot<=3;++slot)if(auto* member=task.member_at(slot))member->force_switch_me=false;};
        for(int slot=1;slot<=3;++slot)if(auto* member=task.member_at(slot))member->force_switch_me=member==&target->state;
        try { OriginalBaseChar::switch_next_char(); }
        catch(...) { clear(); throw; }
        clear();
    }
    bool flying() { return task.has_levitator && task.frame().levitator_white < 0.1; }
    bool has_buff() const { return state.has_buff(task.seconds()); }
    bool has_all_buff() const {
        if (!state.has_intro || !task.member_at) return false;
        int others = 0;
        for (int slot = 1; slot <= 3; ++slot) {
            auto* member = task.member_at(slot);
            if (!member || member == &state) continue;
            ++others;
            if (member->buff_time() <= 0 || !member->has_buff(task.seconds())) return false;
        }
        return others == 2;
    }
    bool find_feature(std::string_view name, double threshold = 0.8) {
        return task.feature && task.feature(name,threshold);
    }
    bool find_feature_in_box(std::string_view name, std::string_view box, double threshold = 0.8) {
        return task.feature_in_box && task.feature_in_box(name, box, threshold);
    }
    bool has_long_action() { return find_feature_in_box("has_target", "box_target_enemy_long", 0.6); }
    bool has_long_action2() { return find_feature_in_box("has_target", "target_box_long2", 0.6); }
    bool has_short_action() { return find_feature_in_box("has_target", "target_box_short", 0.6); }
    bool wait_until(const std::function<bool()>& condition, double timeout,
                    const std::function<void()>& post_action = {}) {
        const double start = task.seconds();
        if(timeout==0)timeout=10; // TaskExecutor.wait_until_timeout.
        while (!task.stop_requested()) {
            task.next_frame();
            if (condition()) return true;
            if (post_action) post_action();
            if(task.seconds()-start>timeout)break;
        }
        return false;
    }
    bool check_f_break() {
        if(task.check_f_break_action)return task.check_f_break_action();
        if(task.can_break)return true;
        if(find_feature("f_break_full",0.92))task.can_break=true;
        if(!task.can_break && !task.in_liberation && task.seconds()-task.last_break_check_time>1) {
            task.last_break_check_time=task.seconds();
            task.can_break=find_feature("f_break",0.6);
        }
        return task.can_break;
    }
    virtual bool f_break(bool check_on_switch = false, bool force = false) {
        if (force && !task.send_key('F',0.02,-1,0.05)) throw std::runtime_error("Maa F failed");
        if (check_on_switch && !check_f_on_switch) return false;
        if (!check_f_break()) return false;
        const double start = task.seconds();
        do {
            if (!task.send_key('F',0.02,-1,0.1) || !task.click(-1,0.1))
                throw std::runtime_error("Maa F break failed");
            task.can_break=false;
        } while (!task.stop_requested() && task.seconds()-start < 5 &&
                 (task.seconds()-start < 0.5 || check_f_break()));
        return true;
    }
    void cycle_start() { cycle_start_time = task.seconds(); }
    void cycle_sleep(double duration = 0.1) {
        const double to_sleep=duration-(task.seconds()-cycle_start_time);
        check_f_break();
        sleep(to_sleep);
    }
    bool need_fast_perform() { return task.need_fast_perform && task.need_fast_perform(); }
    void continues_right_click(double duration, double interval = 0.1,int direction_key=0) {
        if(direction_key){task.key_down(direction_key);task.next_frame();}
        const double start = task.seconds();
        while (task.seconds() - start < duration && !task.stop_requested()) {
            task.right_click(interval);
        }
        if(direction_key)task.key_up(direction_key);
    }
    void normal_attack_until_can_switch() {
        if (!task.click()) throw std::runtime_error("Maa normal attack failed");
        while (time_elapsed_accounting_for_freeze(last_perform) < 1.1 &&
               !task.stop_requested()) {
            task.click(0.1);
        }
    }
    bool is_con_full() {
        if (state.current_con == 1) return true;
        return task.frame().concerto_full;
    }
    std::string_view check_outro() const {
        if (!state.has_intro || !task.member_at) return {};
        double latest = 0;
        std::string_view source;
        for (int slot = 1; slot <= 3; ++slot) {
            const auto* member = task.member_at(slot);
            if (member && member != &state && member->last_switch_time > latest) {
                latest = member->last_switch_time;
                source = member->definition->class_name;
            }
        }
        return source;
    }
    double get_current_con() {
        if (state.current_con == 1) return 1;
        state.current_con = task.frame().concerto_coverage;
        return state.current_con;
    }
    void normal_attack() { check_combat(); if (!task.click()) throw std::runtime_error("Maa attack failed"); }
    void heavy_attack(double duration = 0.6) {
        check_combat();
        if (!task.mouse_down()) throw std::runtime_error("Maa heavy down failed");
        try { sleep(duration); }
        catch (...) { task.mouse_up(); throw; }
        if (!task.mouse_up()) throw std::runtime_error("Maa heavy up failed");
        sleep(0.01);
    }
    void continues_normal_attack(double duration, double interval = 0.1,
                                 double after_sleep = 0,
                                 bool click_resonance_if_ready_and_return = false,
                                 bool until_con_full = false) {
        const double start = task.seconds();
        while (task.seconds() - start < duration && !task.stop_requested()) {
            if (click_resonance_if_ready_and_return && resonance_available()) {
                click_resonance(); return;
            }
            if (until_con_full && is_con_full()) return;
            if (!task.click()) throw std::runtime_error("Maa normal attack failed");
            sleep(interval);
        }
        sleep(after_sleep);
    }
    void continues_click(int key, double duration, double interval = 0.1) {
        const double start = task.seconds();
        while (task.seconds() - start < duration && !task.stop_requested()) {
            task.send_key(key,0.02,interval);
        }
    }
    void wait_intro(double timeout = 1.2, bool click = true) {
        if (!state.has_intro) return;
        wait_until([&]() {
            const auto frame = task.frame();
            return (frame.resonance_white>0 && !has_cd('E')) ||
                   (frame.liberation_white>0 && !has_cd('R'));
        },timeout,click?std::function<void()>([&](){task.click(0.1);}):std::function<void()>{});
    }
    void wait_down(bool click = true) {
        // OK-WW's default AutoCombatTask only enters this branch when an
        // intro was observed and levitator detection is disabled.
        if (!task.has_levitator && state.has_intro) {
            if (click) continues_normal_attack(intro_motion_freeze_duration);
            else sleep(intro_motion_freeze_duration);
        } else {
            const double start = task.seconds();
            while (flying() && task.seconds() - start < 2.5 && !task.stop_requested()) {
                if (click) task.click(0.2);
                else sleep(0.2);
                task.next_frame();
            }
        }
    }
    virtual OriginalResonanceResult click_resonance(double post_sleep = 0,
                                            bool has_animation = false,
                                            bool send_click = true,
                                            double animation_min_duration = 0,
                                            bool /*check_cd*/ = false,
                                            double time_out = 0,
                                            bool click_f = true) {
        OriginalResonanceResult result;
        const double start = task.seconds();
        double last_press = 0, pressed_at = 0, animation_start = 0, last_f = 0;
        bool last_op_resonance = false;
        double limit = time_out == 0 ? skill_timeout : time_out;
        while (!task.stop_requested()) {
            if(task.seconds()-start>limit || (task.in_liberation && task.seconds()-start>6)) {
                task.in_liberation=false;break;
            }
            if(has_animation) {
                if(task.active_slot()<1) {
                    task.in_liberation=true;
                    const double now=task.seconds();
                    if(animation_start==0)animation_start=now;
                    result.animated=true;limit=skill_timeout;
                    if(now-pressed_at>6)task.in_liberation=false;
                    if(click_f && now-animation_start>=animation_min_duration && now-last_f>=0.1) {
                        task.send_key('F');last_f=now;
                    }
                    task.next_frame();check_combat();continue;
                }else if(task.in_liberation){task.in_liberation=false;break;}
            }
            check_combat();
            const double now=task.seconds();
            if (!resonance_available() &&
                (!has_animation || now - start > animation_min_duration)) break;
            if (now - last_press > 0.1) {
                if (send_click && last_op_resonance) {
                    if (!task.click()) throw std::runtime_error("Maa attack before E failed");
                    last_op_resonance = false;
                    continue;
                }
                if (resonance_available()) {
                    if (pressed_at == 0) { pressed_at = now; last_res = task.seconds(); result.clicked = true; }
                    last_op_resonance = true;
                    send_resonance_key();
                    if (has_animation) sleep(0.2,false);
                }
                last_press = now;
            }
            task.next_frame();
        }
        task.in_liberation=false;
        if (result.clicked) sleep(post_sleep);
        if (animation_start > 0 && task.add_freeze_duration)
            task.add_freeze_duration(pressed_at, task.seconds()-animation_start, 0.1);
        result.duration = pressed_at != 0 ? task.seconds() - pressed_at : 0;
        return result;
    }
    bool send_resonance_key(double post_sleep=0,double interval=-1,double down_time=0.01) {
        return task.send_key('E',down_time,interval,post_sleep);
    }
    bool send_echo_key(double after_sleep=0,double interval=-1,double down_time=0.01) {
        return task.send_key('Q',down_time,interval,after_sleep);
    }
    bool send_liberation_key(double after_sleep=0,double interval=-1,double down_time=0.01) {
        return task.send_key('R',down_time,interval,after_sleep);
    }
    virtual bool click_echo(double duration = 0, double /*sleep_time*/ = 0, double time_out = 1) {
        if (time_out == 0 && echo_available()) {
            send_echo_key();
            last_echo = task.seconds();
            return true;
        }
        if (task.is_open_world_auto_combat() && state.ring_index == 2) return false;
        if (has_cd('Q')) return false;
        bool clicked = false;
        const double start = task.seconds();
        double last_press = 0;
        while (!task.stop_requested()) {
            if (task.seconds() - start > time_out + duration) return false;
            if (!echo_available() && (duration == 0 || !clicked)) break;
            if (duration > 0 && task.seconds() - start > duration) break;
            const double now=task.seconds();
            if (now - last_press > 0.1) {
                if (!clicked) { clicked = true; last_echo = task.seconds(); }
                send_echo_key();
                last_press = now;
            }
            if(now-start>skill_timeout)break;
            task.next_frame();
        }
        return clicked;
    }
    virtual bool click_liberation(double con_less_than = -1, bool send_click = false,
                          double wait_if_cd_ready = 0.1,
                          double animation_min_duration = 0, bool click_f = true) {
        if (!task.use_liberation) return false;
        if (con_less_than > 0 && get_current_con() > con_less_than) return false;
        const double start = task.seconds();
        double last_press = 0;
        bool clicked = false;
        if(!task.in_liberation) {
          while (liberation_available() && !task.stop_requested()) {
            if (send_click) task.click(0.1);
            const double now=task.seconds();
            if (now - last_press > 0.1) {
                send_liberation_key();
                clicked = true; last_press = now;
            }
            if(task.seconds()-start>skill_timeout)throw OriginalNotInCombat("Too long clicking a liberation");
            task.next_frame();
          }
          if (clicked) {
            task.in_liberation=wait_until([&](){return task.active_slot()<1;},0.4,
                send_click?std::function<void()>([&](){task.click(0.1);}):std::function<void()>{});
            if(!task.in_liberation)return false;
          } else {
            const double wait_start = task.seconds();
            while (!has_cd('R') && task.seconds() - wait_start < wait_if_cd_ready &&
                   !task.stop_requested()) {
                send_liberation_key(0.05);
                if(wait_until([&](){return task.active_slot()<1;},0.1))task.in_liberation=true;
            }
            if(!task.in_liberation)return false;
          }
        }
        const double animation_start = task.seconds();
        double last_f = 0;
        while (task.active_slot() < 1 && !task.stop_requested()) {
            task.in_liberation=true;clicked=true;
            if (send_click) task.click(0.1);
            const double now=task.seconds();
            if (click_f && now - animation_start >= animation_min_duration &&
                now - last_f >= 0.1) {
                task.send_key('F'); last_f = now;
            }
            if(now-animation_start>7){task.in_liberation=false;throw OriginalNotInCombat("Liberation animation exceeded 7 seconds");}
            task.next_frame();
        }
        if (task.add_freeze_duration)
            task.add_freeze_duration(animation_start, task.seconds()-animation_start, 0.1);
        last_liberation = task.seconds();
        state.last_liberation = last_liberation;
        task.in_liberation=false;
        state.cached_liberation_available=false;
        return clicked;
    }
    bool heavy_click_forte(const std::function<bool()>& check_fun) {
        if (!check_fun()) return false;
        if (!task.mouse_down()) throw std::runtime_error("Maa forte heavy down failed");
        bool success = false;
        try {success=wait_until([&](){return !check_fun();},2);}
        catch(...){task.mouse_up();throw;}
        if (!task.mouse_up()) throw std::runtime_error("Maa forte heavy up failed");
        sleep(0.05);
        return success;
    }
    bool heavy_click_forte() {
        return heavy_click_forte([&]() { return is_forte_full(); });
    }
    virtual void switch_next_char(bool free_intro = false, bool target_low_con = false) {
        (void)is_forte_full();
        state.cached_liberation_available = liberation_available();
        if (state.has_tool_box) {
            if (!task.send_key('T')) throw std::runtime_error("Maa toolbox key failed");
            state.has_tool_box = false;
        }
        if (!task.switch_next_char(free_intro, target_low_con))
            throw OriginalHudRetry("Maa character switch was not confirmed; re-read HUD");
    }
public:
    OriginalBaseChar(OriginalCombatIO& io, OriginalSwitchCharacter& member) : task(io), state(member) {
        check_f_on_switch=!state.is_healer();
    }
    virtual ~OriginalBaseChar() = default;
    virtual int get_switch_priority(OriginalBaseChar* =nullptr,bool=false,bool=false) {
        return state.healer_full_con_switch_locked(task.seconds())?0:200;
    }
    double current_con_for_switch(){return get_current_con();}
    bool con_full_for_switch(){return is_con_full();}
    virtual void bind_carlotta(OriginalBaseChar*) {}
    virtual bool skip_combat_check() {return false;}
    virtual void reset_state() {
        state.has_intro=false;state.has_sub_dps_intro=false;state.current_con=0;
        state.last_full_con_switch_time=-1;state.has_tool_box=false;
        state.cached_liberation_available=false;
    }
    virtual void on_combat_end() {}
    virtual void switch_out(bool con_full,double now) {
        state.switch_out(now,con_full);on_switch_out(con_full,now);
    }
    virtual void on_switch_out(bool, double) {}
    virtual bool ready_for_linkage() { return false; }
    virtual bool is_alternate_form() { return false; }
    virtual int forte_stacks() { return 0; }
    virtual void set_forte_stacks(int) {}
    virtual bool in_outro() { return false; }
    virtual bool consume_insert_handoff() { return false; }
    virtual void discard_insert_handoff() {}
    virtual bool use_rover_linkage() { return false; }
    virtual int known_form() const { return -1; }
    virtual int get_state() { return 0; }
    virtual double liberation_time_left() { return 0; }
    virtual double get_blazes() const { return -1; }
    virtual int outro_count() const { return 0; }
    virtual void reset_action(bool = true) {}
    virtual bool wait_switch() { return false; }
    OriginalSwitchCharacter& member_state() { return state; }
    virtual double intro_freeze_seconds() const {return intro_motion_freeze_duration;}
    void break_on_switch() {f_break(true);}
    void attack_without_switch(double duration) {continues_normal_attack(duration);}
    virtual bool auto_dodge(const std::function<bool()>&) { return false; }
    virtual void do_perform() {
        wait_intro(1.2);
        click_echo(0, 0, 0);
        click_liberation();
        if (!click_resonance().clicked)
            heavy_click_forte([&]() { return is_mouse_forte_full(); });
        switch_next_char();
    }
    void perform() { last_perform = task.seconds(); state.last_perform = last_perform; do_perform(); }
};
