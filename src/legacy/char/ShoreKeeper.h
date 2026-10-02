#pragma once
inline bool perform_shorekeeper(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (state.has_intro && c.phase_elapsed_ms < 1200) {
        if (!c.click()) throw std::runtime_error("ShoreKeeper intro attack failed");
        return true;
    }
    if (s.liberation_white > 0.08 && c.now - state.last_r > 8) {
        if (c.cast('R', s.liberation_white, "shorekeeper_liberation")) state.last_r = c.now;
    }
    bool resonance_cast = false;
    if (s.resonance_white > 0.06 && c.now - state.last_e > 2) {
        resonance_cast = c.cast('E', s.resonance_white, "shorekeeper_resonance");
        if (resonance_cast) state.last_e = c.now;
    }
    if (resonance_cast) return false;
    if (c.now - state.last_heavy > 2) {
        if (!c.heavy(0, 700)) throw std::runtime_error("ShoreKeeper heavy failed");
        state.last_heavy = c.now;
        return false;
    } else if (!c.click()) {
        throw std::runtime_error("Maa attack input failed");
    }
    return true;
}
