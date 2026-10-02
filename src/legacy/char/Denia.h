#pragma once

inline bool perform_denia(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;

    if (state.has_intro && c.phase_elapsed_ms < 2000) {
        if (!c.click()) throw std::runtime_error("Denia intro attack failed");
        return true;
    }
    if (!state.has_intro && c.denia_lib1_casted && c.phase_elapsed_ms < 1300) {
        if (!c.click()) throw std::runtime_error("Denia post-lib1 attack failed");
        return true;
    }
    if (c.now - state.last_lib2 < 10.0 && s.concerto_full) return false;

    // Port of Denia.do_perform: Resonance first, then select Liberation 1/2
    // from the original OK-WW end-of-Liberation image.
    if (s.resonance_white > 0.06 && c.now - state.last_e > 2.0) {
        if (c.cast('E', s.resonance_white, "denia_resonance")) state.last_e = c.now;
        return true;
    }
    if (s.liberation_white > 0.08 && c.now - state.last_r > 1.0) {
        const bool end_lib = c.feature("OKWW_denia_end_lib", 1175, 610, 85, 85, 0.7);
        if (c.cast('R', s.liberation_white, end_lib ? "denia_end_lib" : "denia_first_lib")) {
            state.last_r = c.now;
            if (end_lib) {
                state.last_lib2 = c.now;
                c.denia_lib1_casted = false;
                if (s.echo_white > 0.08 && c.cast('Q', s.echo_white, "denia_echo"))
                    state.last_q = c.now;
            } else {
                c.denia_lib1_casted = true;
                for (int i = 0; i < 10 && !c.stop_requested(); ++i) {
                    if (!c.click()) throw std::runtime_error("Denia follow-up attack failed");
                    Sleep(180);
                }
            }
            return false;
        }
        return true;
    }
    if (!c.click()) throw std::runtime_error("Denia attack input failed");
    return true;
}
