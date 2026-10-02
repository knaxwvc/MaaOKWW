#pragma once
#include "BaseChar.h"
#include "Aemeath.h"
#include "Linnai.h"
#include "Mornye.h"
#include "Hiyuki.h"
#include "Lucilla.h"
#include "Chisa.h"
#include "Qingxiao.h"
#include "Denia.h"
#include "ShoreKeeper.h"

// The slot order matches the original OK-WW team portraits: 1, 2, 3.
// CombatTask chooses a role after confirming the actual team, then calls its
// editable per-character action function here.
inline bool perform_character_tick(int team, int role, CombatOps& c) {
    auto& state = c.state;
    if (!(team == 2 && role == 1 && state.lucilla_transformed) &&
        c.frame.echo_white > 0.08 && c.now - state.last_q > 8) {
        if (c.cast('Q', c.frame.echo_white, "echo")) state.last_q = c.now;
    }
    if (team == 1) {
        if (role == 0) return perform_mornye(c);
        if (role == 1) return perform_linnai(c);
        return perform_aemeath(c);
    }
    if (team == 2) {
        if (role == 0) return perform_chisa(c);
        if (role == 1) return perform_lucilla(c);
        return perform_hiyuki(c);
    }
    if (team == 3) {
        if (role == 0) return perform_shorekeeper(c);
        if (role == 1) return perform_denia(c);
        return perform_qingxiao(c);
    }
    // Never invent a fallback rotation for an unported squad. The caller
    // rejects unknown teams before combat input is sent.
    return false;
}
