#pragma once

inline bool perform_linnai(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    const bool mouse_forte = c.feature("OKWW_mouse_forte", 340, 290, 85, 80, 0.6);

    // BaseChar creates a new turn for every entry. Reset only turn-local
    // charge/follow-up state; shared cooldown timestamps stay in RoleState.
    if (c.phase_elapsed_ms == 0) {
        state.linnai_heavy = false;
        state.linnai_followup = 0;
    }

    if (state.linnai_heavy) {
        if (s.concerto_full) return false;
        if (state.linnai_followup < 2 && s.resonance_white > 0.06 &&
            c.now - state.last_e > 1.0 && c.cast('E', s.resonance_white, "linnai_followup_resonance")) {
            state.last_e = c.now;
            ++state.linnai_followup;
            return true;
        }
        if (state.linnai_followup >= 2 && c.phase_elapsed_ms > 5000) return false;
        if (s.liberation_white > 0.08 && c.now - state.last_r > 8.0 &&
            c.cast('R', s.liberation_white, "linnai_liberation_after_forte")) {
            state.last_r = c.now;
            return true;
        }
        if (c.phase_elapsed_ms > 7000) return false;
        if (!c.click()) throw std::runtime_error("Linnai forte follow-up attack failed");
        return true;
    }

    if (state.has_intro && c.target_locked && c.phase_elapsed_ms < 1330) {
        if (!c.click()) throw std::runtime_error("Linnai intro attack failed");
        return true;
    }

    if (c.phase_elapsed_ms < 1000 && !mouse_forte) {
        if (!c.click()) throw std::runtime_error("Linnai charge opening attack failed");
        return true;
    }
    if (s.echo_white > 0.08 && c.now - state.last_q > 8.0 &&
        c.cast('Q', s.echo_white, "linnai_echo")) state.last_q = c.now;
    if (!s.concerto_full && s.liberation_white > 0.08 && c.now - state.last_r > 8.0 &&
        c.cast('R', s.liberation_white, "linnai_charge_liberation")) state.last_r = c.now;

    if (mouse_forte) {
        if (!c.heavy(0, 500)) throw std::runtime_error("Linnai forte heavy failed");
        state.last_heavy = c.now;
        Sleep(120);
        state.linnai_heavy = !c.feature("OKWW_mouse_forte", 340, 290, 85, 80, 0.6);
        std::cout << "linnai_forte_consumed=" << state.linnai_heavy << '\n';
        return true;
    }

    if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0 &&
        c.cast('E', s.resonance_white, "linnai_charge_resonance")) state.last_e = c.now;
    if (!c.click()) throw std::runtime_error("Linnai normal attack failed");
    return true;
}
