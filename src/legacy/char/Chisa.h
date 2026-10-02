#pragma once

inline bool perform_chisa(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (c.phase_elapsed_ms == 0) state.chisa_forte_stage = 0;
    // The supplied OK-WW Character Config.json has "Chisa DPS": false, so the
    // port follows her configured support rotation.
    if (state.has_intro && c.phase_elapsed_ms < 2000) {
        if (!c.click()) throw std::runtime_error("Chisa intro attack failed");
        return true;
    }
    if (s.concerto_full) return false;

    if (s.echo_white > 0.08 && c.now - state.last_q > 8.0 &&
        c.cast('Q', s.echo_white, "chisa_echo")) state.last_q = c.now;

    if (state.chisa_forte_stage == 1) {
        // Chisa.perform_forte checks that the held E spent her full Forte
        // gauge before starting the 3.5 s heavy attack.
        if (s.forte_white <= 0.08) {
            if (!c.heavy(0, 3500)) throw std::runtime_error("Chisa forte heavy failed");
            state.chisa_forte_stage = 2;
            return false;
        }
        state.chisa_forte_stage = 0;
    } else if (state.chisa_forte_stage == 2) {
        return false;
    }

    if (s.liberation_white > 0.08 && c.now - state.last_r > 1.0 &&
        c.cast('R', s.liberation_white, "chisa_liberation")) {
        state.last_r = c.now;
        return true;
    }

    const bool enhanced_e = c.feature("OKWW_chisa_e2", 505, 285, 90, 80, 0.7);
    if (s.forte_white > 0.08) {
        if (!c.hold_key('E', 1200)) throw std::runtime_error("Chisa forte skill hold failed");
        state.last_e = c.now;
        state.chisa_forte_stage = 1;
        return true;
    }
    if ((enhanced_e || s.resonance_white > 0.06) && c.now - state.last_e > 2.0 &&
        c.cast('E', s.resonance_white, "chisa_resonance")) state.last_e = c.now;
    if (!c.click()) throw std::runtime_error("Chisa attack input failed");
    return true;
}
