#include <cassert>
#include <iostream>
#include "../task/OriginalPriority.h"

int main() {
    auto by_name = [](std::string_view name) -> const CharacterDefinition* {
        for (const auto& definition : character_definitions)
            if (definition.class_name == name) return &definition;
        return nullptr;
    };
    std::array<OriginalSwitchCharacter, 3> chars{};
    for (int i = 0; i < 3; ++i) chars[i].index = i;
    chars[0].definition = by_name("Aemeath");
    chars[1].definition = by_name("Linnai");
    chars[2].definition = by_name("Mornye");
    auto choose = [&](int current, bool intro, double now) {
        return choose_original_switch_target(chars, current, intro, false, now,
            [&](const OriginalSwitchCharacter& candidate, const OriginalSwitchCharacter& from,
                bool has_intro, bool low_con, double time) {
                return original_priority_for_ported_character(candidate, from, has_intro, low_con, time, chars);
            });
    };
    assert(choose(2, false, 100) == 1); // Mornye -> Linnai MUST
    assert(choose(0, true, 100) == 2);  // Aemeath intro -> Mornye MUST
    chars[2].switch_out(100, true);
    assert(chars[2].last_full_con_switch_time == 100);
    assert(chars[2].last_buff_time == 100);
    assert(choose(0, true, 101) == 1);  // healer lockout blocks Mornye
    chars[2].last_full_con_switch_time = -1;
    chars[1].last_buff_time = 99;
    assert(choose(0, false, 101) == 1); // lowest support buff remaining
    chars[2].last_buff_time = 0;
    chars[1].last_buff_time = 99;
    assert(choose(0, false, 102.2) == 2); // unbuffed support after switch cooldown
    std::cout << "original_switch_test passed\n";
}
