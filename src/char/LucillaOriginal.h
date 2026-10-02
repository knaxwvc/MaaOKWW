#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Lucilla.py
// Port source SHA256: 81aab1deac4e03db9e97d7eaa52f0bc9adf93c59f43e74651d6725f524f8b9ab
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Lucilla.py
class LucillaOriginal final : public OriginalBaseChar {
    static constexpr double hold_time = 1.4;
    static constexpr double liberation_animation_time = 3.0;
    static constexpr double liberation_heavy_time = 15.0;
    static constexpr double heavy_pulse_time = 0.6;
    static constexpr double charge_time_out = 7.2;
    static constexpr double liberation_cd_skip = 1.5;
    static constexpr double switch_in_settle = 0.5;
    bool energy_full() { return available('R', true, false); }
    void hold_resonance(double duration) {
        if (!task.key_down('E')) throw std::runtime_error("Maa Lucilla E down failed");
        try { sleep(duration,false); }
        catch (...) { task.key_up('E'); throw; }
        if (!task.key_up('E')) throw std::runtime_error("Maa Lucilla E up failed");
        last_res = task.seconds();
    }
    void charge_once() {
        if (resonance_available()) hold_resonance(hold_time);
        else heavy_attack(hold_time);
        task.next_frame();
    }
    void pulse_heavy_attack(double total_time) {
        const double end = task.seconds()+total_time;
        bool seen_active = false;
        while (task.seconds() < end && !task.stop_requested()) {
            if (!task.mouse_down()) throw std::runtime_error("Maa Lucilla heavy down failed");
            try { sleep(std::min(heavy_pulse_time, end-task.seconds()),false); }
            catch (...) { task.mouse_up(); throw; }
            if (!task.mouse_up()) throw std::runtime_error("Maa Lucilla heavy up failed");
            const double con = task.frame().concerto_coverage;
            if (con > 0.1) seen_active = true;
            else if (seen_active && con < 0.05) break;
            sleep(0.02,false);
        }
    }
    void perform_liberation() {
        if (!task.use_liberation) return;
        const double start = task.seconds();
        while (liberation_available() && task.seconds()-start < 1.5 && !task.stop_requested()) {
            if (!send_liberation_key()) throw std::runtime_error("Maa Lucilla R failed");
            sleep(0.1,false);
        }
        last_liberation = task.seconds();
        state.last_liberation = last_liberation;
        sleep(liberation_animation_time,false);
        pulse_heavy_attack(liberation_heavy_time);
    }
    bool try_liberation() {
        if (!liberation_available()) return false;
        if (echo_available()) click_echo(0, 0, 0);
        perform_liberation();
        switch_next_char();
        return true;
    }
    bool perform_combat() {
        const double start = task.seconds();
        wait_until([&]() { return task.active_slot() > 0; }, 0.8);
        sleep(switch_in_settle,false);
        task.next_frame();
        if (try_liberation()) return true;
        while (task.seconds()-start < charge_time_out && !task.stop_requested()) {
            if (energy_full() && !liberation_available()) break;
            if (!liberation_available() && task.cooldown_remaining('R') > liberation_cd_skip) break;
            if (try_liberation()) return true;
            charge_once();
        }
        return false;
    }
public:
    int get_switch_priority(OriginalBaseChar* current=nullptr,bool has_intro=false,bool target_low_con=false) override {
        const std::string_view from=current?current->member_state().definition->class_name:std::string_view{};
        if(has_intro && (from=="Verina" || from=="ShoreKeeper"))return 400;
        return OriginalBaseChar::get_switch_priority(current,has_intro,target_low_con);
    }

    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override { if (!perform_combat()) switch_next_char(); }
};
