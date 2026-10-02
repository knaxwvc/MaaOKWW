#pragma once
inline bool perform_qingxiao(CombatOps& c) {
    const auto& s = c.frame;
    auto& state = c.state;
    if (!state.has_intro || !state.has_all_buff) {
        bool enhanced = c.feature("OKWW_qingxiao_e", 1045, 610, 85, 85);
        if (enhanced && s.resonance_white > 0.06 &&
            c.cast('E', s.resonance_white, "qingxiao_prepare_resonance"))
            state.last_e = c.now;
        return false;
    }
    bool h2 = c.feature("OKWW_qingxiao_h2", 915, 605, 100, 95);
    bool h1 = h2 || c.feature("OKWW_qingxiao_h1", 915, 605, 100, 95);
    bool enhanced_e = c.feature("OKWW_qingxiao_e", 1045, 610, 85, 85);
    if (h1 && c.now - state.last_heavy > 1) {
        if (!c.heavy(0, 900)) throw std::runtime_error("Qingxiao heavy failed");
        state.last_heavy = c.now;
        Sleep(250);
        bool still_lit = c.feature("OKWW_qingxiao_h1", 915, 605, 100, 95) ||
                         c.feature("OKWW_qingxiao_h2", 915, 605, 100, 95);
        std::cout << "qingxiao_heavy_icon_dark_confirmed=" << !still_lit << '\n';
        if (h2 && !still_lit && s.liberation_white > 0.08) {
            if (c.cast('R', s.liberation_white, "qingxiao_h2_liberation")) state.last_r = c.now;
        }
    } else if (enhanced_e && s.resonance_white > 0.06 && c.now - state.last_e > 2) {
        if (c.cast('E', s.resonance_white, "qingxiao_enhanced_resonance")) state.last_e = c.now;
    } else if (!c.click()) {
        throw std::runtime_error("Maa attack input failed");
    }
    return true;
}
