#pragma once
// Port source: C:\ok-ww222\data\apps\ok-ww\working\src\char\Aemeath.py
// Port source SHA256: 32416a70a583ac9245f0a08951b33eafe50910cd37e0bf3a53b663c09927f1a6
#include "OriginalBaseChar.h"

// C:\ok-ww222\data\apps\ok-ww\working\src\char\Aemeath.py
class AemeathOriginal final : public OriginalBaseChar {
    static constexpr double liberation_force_duration = 30;
    static constexpr double heavy_prepare_timeout = 3;
    bool enhance_e_cast_this_turn = false;
    bool lib2_cast_this_turn = false;
    bool must_cast_lib2_this_turn = false;
    bool lib2_available() { return find_feature("aemeath_lib2", 0.7); }
    bool lib() {
        const bool is_lib2 = lib2_available();
        const bool liberated = click_liberation(-1, false, 0);
        if (liberated && is_lib2) lib2_cast_this_turn = true;
        return liberated;
    }
    bool required_action_pending() const {
        return (state.has_intro && !enhance_e_cast_this_turn) ||
               (must_cast_lib2_this_turn && !lib2_cast_this_turn);
    }
    bool enhance_e_available() {
        return find_feature("aemeath_e1", 0.7) || find_feature("aemeath_e2", 0.7);
    }
    bool heavy_wait_highlight_down(double timeout) {
        if (!task.mouse_down()) throw std::runtime_error("Maa Aemeath heavy down failed");
        bool consumed = false;
        try { consumed = wait_until([&]() { return !has_long_action(); }, timeout); }
        catch (...) { task.mouse_up(); throw; }
        if (!task.mouse_up()) throw std::runtime_error("Maa Aemeath heavy up failed");
        sleep(0.01);
        return consumed;
    }
    bool handle_heavy(double timeout = 1.2) {
        return has_long_action() && heavy_wait_highlight_down(timeout);
    }
    void perform_everything() {
        double start = task.seconds();
        const auto deadline = std::chrono::steady_clock::now()+std::chrono::duration<double>(liberation_force_duration);
        while (time_elapsed_accounting_for_freeze(start) < 12 && !task.stop_requested()) {
            const double remaining = std::chrono::duration<double>(deadline-std::chrono::steady_clock::now()).count();
            if (remaining <= 0) return;
            cycle_start();
            if (handle_heavy(std::min(1.2, remaining))) {
                start = task.seconds();
                if (!f_break()) sleep(0.1);
                check_combat();
                continue;
            }
            bool action_performed = false;
            if (lib()) {
                if (lib2_cast_this_turn) return;
                action_performed = true;
            } else if (enhance_e_available()) {
                const bool resonance_cast = click_resonance(0, true, true, 0.5, false, 1.5).clicked;
                if (resonance_cast) {
                    enhance_e_cast_this_turn = true;
                    click_echo(0, 0, 0);
                    task.next_frame();
                }
                const bool liberated = lib();
                if (lib2_cast_this_turn) return;
                action_performed = resonance_cast || liberated;
            } else {
                task.click();
            }
            if (action_performed) {
                if (has_long_action()) start = task.seconds();
                else if (!required_action_pending()) return;
            }
            cycle_sleep();
        }
    }
public:
    using OriginalBaseChar::OriginalBaseChar;
    void do_perform() override {
        enhance_e_cast_this_turn = false;
        lib2_cast_this_turn = false;
        must_cast_lib2_this_turn = has_all_buff() && state.has_intro;
        if (!must_cast_lib2_this_turn) {
            const auto deadline = std::chrono::steady_clock::now()+std::chrono::duration<double>(heavy_prepare_timeout);
            while (has_long_action() && !task.stop_requested()) {
                const double remaining = std::chrono::duration<double>(deadline-std::chrono::steady_clock::now()).count();
                if (remaining <= 0) break;
                const bool completed = handle_heavy(std::min(1.2, remaining));
                check_combat();
                sleep(std::min(completed ? 0.3 : 0.05, std::max(0.0,
                    std::chrono::duration<double>(deadline-std::chrono::steady_clock::now()).count())));
            }
            return switch_next_char();
        }
        if (state.has_intro) continues_normal_attack(2.1);
        perform_everything();
        switch_next_char();
    }
};
