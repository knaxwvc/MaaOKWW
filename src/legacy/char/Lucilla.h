#pragma once

// Port of Lucilla.do_perform: wait for the team HUD, spend Echo before a ready
// Liberation, charge with held E (or a held heavy), then pulse heavy attacks
// during the 15-second transformed window until the concerto ring drains.
inline bool perform_lucilla(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (c.phase_elapsed_ms == 0) {
        state.lucilla_transformed = false;
        state.lucilla_con_seen = false;
        state.lucilla_transform_end = -1;
    }
    if (c.phase_elapsed_ms < 800) return true;

    if (state.lucilla_transformed) {
        if (c.now < state.lucilla_transform_end - 15.0) return true; // three-second entry animation
        if (c.now >= state.lucilla_transform_end) return false;
        if (s.concerto_coverage > 0.10) state.lucilla_con_seen = true;
        if (state.lucilla_con_seen && s.concerto_coverage < 0.05) {
            std::cout << "lucilla transform ended: concerto drained\n";
            return false;
        }
        if (!c.heavy(0, 600)) throw std::runtime_error("Lucilla transformed heavy pulse failed");
        return true;
    }

    if (c.phase_elapsed_ms >= 7200) {
        std::cout << "lucilla charge window ended without a confirmed transformation\n";
        return false;
    }

    if (s.liberation_white > 0.08) {
        if (s.echo_white > 0.08 && c.now - state.last_q > 8.0 &&
            c.cast('Q', s.echo_white, "lucilla_echo_before_liberation")) {
            state.last_q = c.now;
            return true;
        }
        if (c.hold_liberation(1500)) {
            state.last_r = c.seconds();
            state.lucilla_transformed = true;
            state.lucilla_con_seen = false;
            state.lucilla_transform_end = c.seconds() + 18.0;
            std::cout << "lucilla liberation transition confirmed\n";
            return true;
        }
    }

    if (s.resonance_white > 0.06 && c.now - state.last_e >= 1.4) {
        if (!c.hold_key('E', 1400)) throw std::runtime_error("Lucilla held resonance failed");
        state.last_e = c.now;
    } else if (c.now - state.last_heavy >= 1.4) {
        if (!c.heavy(0, 1400)) throw std::runtime_error("Lucilla charge heavy failed");
        state.last_heavy = c.now;
    }
    return true;
}
