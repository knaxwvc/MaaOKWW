#pragma once
inline bool perform_aemeath(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (!state.has_intro || !state.has_all_buff) {
        // Original Aemeath.do_perform: unbuffed entry only prepares a heavy
        // action for at most three seconds, then hands off.
        if (c.phase_elapsed_ms >= 3000) return false;
        const bool heavy_ready = c.feature("OKWW_aemeath_human_heavy", 900, 590, 140, 120, 0.65);
        if (heavy_ready && c.now - state.last_heavy > 0.4) {
            if (!c.heavy(0, 600)) throw std::runtime_error("Aemeath prep heavy failed");
            state.last_heavy = c.now;
        } else if (!c.click()) throw std::runtime_error("Aemeath prep attack failed");
        return true;
    }
    if (c.phase_elapsed_ms < 2100) {
        if (!c.click()) throw std::runtime_error("Aemeath intro attack failed");
        return true;
    }
    if (s.liberation_white > 0.08 && c.now - state.last_r > 8) {
        const bool lib2 = c.feature("OKWW_aemeath_lib2", 580, 295, 60, 70);
        if (c.cast('R', s.liberation_white,
                   lib2 ? "aemeath_lib2" : "aemeath_liberation")) {
            state.last_r = c.now;
            if (lib2) return false;
        }
    }
    bool enhanced_e = c.feature("OKWW_aemeath_e1", 1030, 600, 100, 90) ||
                      c.feature("OKWW_aemeath_e2", 1030, 600, 100, 90);
    if (enhanced_e && s.resonance_white > 0.06 && c.now - state.last_e > 2) {
        if (c.cast('E', s.resonance_white, "aemeath_resonance")) state.last_e = c.now;
    }
    const bool heavy_ready = c.feature("OKWW_aemeath_human_heavy", 900, 590, 140, 120, 0.65);
    if (heavy_ready && c.now - state.last_heavy > 0.5) {
        if (!c.heavy(0, 600)) throw std::runtime_error("Aemeath heavy failed");
        state.last_heavy = c.now;
    } else if (!c.click()) {
        throw std::runtime_error("Maa attack input failed");
    }
    return true;
}
