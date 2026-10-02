#pragma once

inline bool perform_mornye(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (c.phase_elapsed_ms == 0) {
        state.mornye_waiting_con = false;
        state.mornye_dodge_sent = false;
        state.mornye_echo_ready_start = s.echo_white > 0.08;
    }

    if (state.has_intro && c.phase_elapsed_ms < 1330) {
        if (!c.click()) throw std::runtime_error("Mornye intro attack failed");
        return true;
    }

    // OK-WW on_air() is the target-state icon in target_box_long2, not merely
    // any target detected elsewhere in the HUD.
    const bool on_air = c.feature("NativeHasTarget", 817, 624, 45, 45, 0.6);
    if (state.mornye_waiting_con) {
        if (s.concerto_full) {
            state.last_heavy = c.seconds();
            state.mornye_waiting_con = false;
            return false;
        }
        if (c.now - state.mornye_con_wait_start < 2.0) {
            if (!c.click()) throw std::runtime_error("Mornye concerto fill attack failed");
            return true;
        }
        if (s.echo_white > 0.08 && c.now - state.last_q > 8.0 &&
            c.cast('Q', s.echo_white, "mornye_echo_after_heavy")) state.last_q = c.now;
        state.last_heavy = c.seconds();
        state.mornye_waiting_con = false;
        return false;
    }

    const bool combo_limit = state.last_heavy >= 0 && c.now - state.last_heavy < 23.0;
    if (!on_air && combo_limit) {
        if (s.echo_white > 0.08 && c.now - state.last_q > 8.0 &&
            c.cast('Q', s.echo_white, "mornye_quick_echo")) state.last_q = c.now;
        else if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0 &&
                 c.cast('E', s.resonance_white, "mornye_quick_resonance")) state.last_e = c.now;
        else if (!c.click()) throw std::runtime_error("Mornye quick attack failed");
        return false;
    }

    if (c.phase_elapsed_ms >= 10000) return false;

    if (on_air) {
        if (state.mornye_echo_ready_start && s.echo_white < 0.02 && !state.mornye_dodge_sent) {
            if (!c.right_click()) throw std::runtime_error("Mornye elbow-strike dodge failed");
            state.mornye_dodge_sent = true;
            return true;
        }
        if (s.liberation_white > 0.08 && c.now - state.last_r > 1.0 &&
            c.cast('R', s.liberation_white, "mornye_liberation")) state.last_r = c.now;
        const bool forte = c.feature("OKWW_mouse_forte", 340, 290, 85, 80, 0.6);
        if (forte && c.now - state.last_heavy > 0.6) {
            if (!c.heavy(0, 600)) throw std::runtime_error("Mornye airborne heavy failed");
            if (s.concerto_full) {
                state.last_heavy = c.seconds();
                return false;
            }
            state.mornye_waiting_con = true;
            state.mornye_con_wait_start = c.seconds();
            return true;
        }
        if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0 &&
            c.cast('E', s.resonance_white, "mornye_airborne_resonance")) state.last_e = c.now;
        if (!c.click()) throw std::runtime_error("Mornye airborne attack failed");
        return true;
    }

    if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0 &&
        c.cast('E', s.resonance_white, "mornye_ground_resonance")) state.last_e = c.now;
    const bool forte = c.feature("OKWW_mouse_forte", 340, 290, 85, 80, 0.6);
    if (forte && c.now - state.last_heavy > 0.6) {
        if (!state.mornye_dodge_sent) {
            if (!c.right_click()) throw std::runtime_error("Mornye ground forte dodge failed");
            state.mornye_dodge_sent = true;
        }
        if (!c.heavy(0, 600)) throw std::runtime_error("Mornye ground heavy failed");
        state.mornye_waiting_con = true;
        state.mornye_con_wait_start = c.seconds();
        return true;
    }
    if (!c.click()) throw std::runtime_error("Mornye ground attack failed");
    return true;
}
