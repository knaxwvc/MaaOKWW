#pragma once

inline bool perform_hiyuki(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (c.phase_elapsed_ms == 0) {
        state.hiyuki_kendo_count = 0;
        state.hiyuki_mode = 0;
        state.hiyuki_post_res_until = -1;
    }
    if (state.has_intro && c.phase_elapsed_ms < 1000) {
        if (!c.click()) throw std::runtime_error("Hiyuki intro attack failed");
        return true;
    }

    const bool long_action = c.feature("NativeHasTarget", 880, 620, 45, 50, 0.6);
    const bool long_action2 = c.feature("NativeHasTarget", 817, 624, 45, 45, 0.6);
    if (state.hiyuki_mode == 0) {
        const double liberation_cd = c.cooldown_remaining('R');
        const bool close_to_liberation = liberation_cd >= 0
            ? liberation_cd <= 3.5 : s.liberation_white > 0.08;
        if (long_action && close_to_liberation) state.hiyuki_mode = 1;
        else if (long_action2) state.hiyuki_mode = 2;
        else return false;
        std::cout << "hiyuki mode=" << state.hiyuki_mode
                  << " liberation_cd=" << liberation_cd << '\n';
    }

    if (c.phase_elapsed_ms >= 16000) return false;

    if (state.hiyuki_mode == 1) {
        if (s.echo_white > 0.08 && c.now - state.last_q > 8.0 &&
            c.cast('Q', s.echo_white, "hiyuki_standard_echo")) state.last_q = c.now;
        if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0 &&
            c.cast('E', s.resonance_white, "hiyuki_standard_resonance")) state.last_e = c.now;
        if (s.liberation_white > 0.08 && c.cooldown_remaining('R') <= 0.2 &&
            c.cast('R', s.liberation_white, "hiyuki_standard_liberation")) {
            state.last_r = c.seconds();
            return false;
        }
        const bool forte = c.feature("OKWW_mouse_forte", 340, 290, 85, 80, 0.6);
        if (forte && c.now - state.last_heavy > 0.8) {
            if (!c.right_click()) throw std::runtime_error("Hiyuki forte dodge failed");
            if (!c.heavy(0, 700)) throw std::runtime_error("Hiyuki standard heavy failed");
            state.last_heavy = c.seconds();
            return true;
        }
        if (!c.click()) throw std::runtime_error("Hiyuki standard attack failed");
        return true;
    }

    if (state.hiyuki_post_res_until > c.now) {
        if (!c.click()) throw std::runtime_error("Hiyuki post-resonance attack failed");
        return true;
    }
    state.hiyuki_post_res_until = -1;

    const bool is_timeout = c.phase_elapsed_ms >= 15500;
    const bool lib_heavy = c.feature("OKWW_hiyuki_lib_forte", 740, 625, 85, 80, 0.7);
    if (s.liberation_white > 0.08 && (state.hiyuki_kendo_count >= 4 || is_timeout)) {
        if (c.hold_liberation(8000)) {
            state.hiyuki_kendo_count = 0;
            state.last_r = c.seconds();
            Sleep(500);
            return false;
        }
    }

    if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0 &&
        c.cast('E', s.resonance_white, "hiyuki_liberation_resonance")) {
        state.last_e = c.seconds();
        if (is_timeout) return false;
        state.hiyuki_post_res_until = c.seconds() + 0.3;
        return true;
    }

    if (lib_heavy) {
        if (is_timeout) return false;
        if (!c.heavy(0, 700)) throw std::runtime_error("Hiyuki liberation heavy failed");
        const bool consumed = !c.feature("OKWW_hiyuki_lib_forte", 740, 625, 85, 80, 0.7);
        if (consumed) ++state.hiyuki_kendo_count;
        std::cout << "hiyuki kendo_count=" << state.hiyuki_kendo_count
                  << " consumed=" << consumed << '\n';
        if (consumed && s.liberation_white > 0.08 && c.hold_liberation(8000)) {
            state.hiyuki_kendo_count = 0;
            state.last_r = c.seconds();
            return false;
        }
        return true;
    }

    if (c.feature("OKWW_hiyuki_left", 740, 625, 85, 80, 0.5)) {
        if (!c.click()) throw std::runtime_error("Hiyuki left follow-up failed");
        return true;
    }
    if (c.feature("OKWW_hiyuki_right", 740, 625, 85, 80, 0.5)) {
        if (!c.right_click()) throw std::runtime_error("Hiyuki right follow-up failed");
        return true;
    }
    if (!c.click()) throw std::runtime_error("Hiyuki liberation attack failed");
    return true;
}
