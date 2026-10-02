#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Augusta.py
// Port source SHA256: b7bcd3d51a63fe062ca77f187a3d34e5dbb5d29aa6d353dafd865527edef4948
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Augusta.py
class AugustaOriginal final : public OriginalBaseChar {
    bool liberation_available() override {
        return task.frame().liberation_white > 0 && find_feature("Augusta_lib1", 0.5);
    }
    bool check_majesty() {
        return task.frame().liberation_white > 0 && find_feature("Augusta_lib2", 0.5);
    }
    bool check_prowess() { return find_feature("target_enemy_long_inner", 0.8); }
    bool resonance_available() override { return !has_cd('E'); }
    void shorekeeper_auto_dodge() {
        auto* shorekeeper = task.find_character("ShoreKeeper");
        if (shorekeeper) shorekeeper->auto_dodge([&]() { return flying(); });
    }
    bool perform_prowess() {
        if (!heavy_click_forte([&]() { return check_prowess(); })) return false;
        continues_normal_attack(0.3);
        return true;
    }
    bool perform_majesty(double timeout = 0.6, bool wait_down_first = false) {
        if (!task.key_down('R')) throw std::runtime_error("Maa Augusta R down failed");
        task.in_liberation=true;
        if (wait_down_first) {
            timeout = 0.2;
            wait_until([&]() { return task.active_slot() < 0 || !flying(); }, 2);
        }
        bool animation = false;
        try { animation = wait_until([&]() { return task.active_slot() < 0; }, timeout); }
        catch (...) { task.key_up('R'); throw; }
        const double start = task.seconds();
        if (!task.key_up('R')) throw std::runtime_error("Maa Augusta R up failed");
        if (task.active_slot() > 0) {task.in_liberation=false;return false;}
        wait_until([&]() { return task.active_slot() > 0; }, 10,
                   [&]() { task.click(); });
        if (task.add_freeze_duration)
            task.add_freeze_duration(start, task.seconds()-start, 0.1);
        return true;
    }
public:
    void on_combat_end() override {task.send_key('0'+(state.index+1)%task.team_size()+1);}
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        double time_out = 3;
        if (state.has_intro) {
            continues_normal_attack(1.13);
            if (state.has_sub_dps_intro && check_outro() == "Iuno") time_out = 14;
        }
        if (flying()) wait_down();
        const double start = task.seconds();
        while (task.seconds()-start < time_out+3 && !task.stop_requested()) {
            cycle_start();
            if (check_majesty() && perform_majesty()) {
                send_echo_key();
                return switch_next_char();
            }
            if (flying()) shorekeeper_auto_dodge();
            if (check_prowess() && perform_prowess() && task.seconds()-start > time_out)
                return switch_next_char();
            if (resonance_available()) {
                const double now = task.seconds();
                click_resonance();
                if (task.seconds()-now < 1.4) {
                    if (flying()) continue;
                    if (wait_until([&]() { return check_prowess(); }, 1) && perform_prowess() &&
                        task.seconds()-start > time_out && !flying()) return switch_next_char();
                } else if (check_majesty()) {
                    wait_down();
                    if (perform_majesty()) send_echo_key();
                    return switch_next_char();
                }
            }
            if (liberation_available()) {
                if (wait_until([&]() { return !liberation_available(); }, 2,
                               [&]() { send_liberation_key(); })) {
                    last_liberation = task.seconds();
                    state.last_liberation = last_liberation;
                    if (time_out < 14) return switch_next_char();
                }
            }
            task.click();
            cycle_sleep();
        }
        send_echo_key();
        switch_next_char();
    }
};
