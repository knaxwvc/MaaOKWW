#include "../task/CombatAxis.h"
#include <cassert>

int main() {
    CombatAxis axis;
    axis.team = 1;
    axis.current_role = 0;
    assert(axis.choose_switch_target(0, false) == 1); // Mornye -> Linnai MUST
    axis.switched(1, 1, true);                       // confirmed full-con switch
    assert(axis.buff_active(0, 2));
    assert(axis.choose_switch_target(2, false) == 2);
    axis.switched(2, 3, true);
    assert(axis.all_buffs(4));
    assert(axis.choose_switch_target(4, true) == 1);  // intro priority from main

    CombatAxis second;
    second.team = 2;
    second.current_role = 1;
    assert(second.priority(2, 1, true, 0) == CombatAxis::must); // Lucilla -> Hiyuki
    second.current_role = 2;
    second.healer_full_switch = 1;
    assert(second.priority(0, 2, false, 2) == CombatAxis::no); // healer lockout
}
