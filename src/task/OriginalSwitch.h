#pragma once
#include <algorithm>
#include <array>
#include <functional>
#include <vector>
#include "../char/CharFactory.h"

// Direct translation of BaseCombatTask._choose_switch_target and the helpers
// immediately above it.  Index is the original zero-based portrait slot.
// Character-specific get_switch_priority overrides are supplied by the caller.
struct OriginalSwitchCharacter {
    const CharacterDefinition* definition = nullptr;
    int index = -1;
    double last_switch_in_time = -1;
    double last_switch_time = -1;
    double last_full_con_switch_time = -1;
    double last_buff_time = -1;
    double last_outro_time = -1;
    double current_con = 0;
    double last_perform = 0;
    double last_heavy = -10000;
    double liberation_time = -10000;
    double last_resonance = -10000;
    double last_liberation = -10000;
    double last_intro = -10000;
    double last_forte3_switch = -10000;
    double perform_anchor = -10000;
    bool has_intro = false;
    bool has_sub_dps_intro = false;
    bool is_current_char = false;
    bool has_tool_box = false;
    bool cached_liberation_available = false;
    bool force_switch_me = false;
    int ring_index = -1;
    bool incarnation = false;
    bool incarnation_cd = false;
    int linkage_attribute = 0;
    bool linkage_in_liberation = false;
    bool alternate_form = false;
    bool linkage_ready = false;
    double crisis_time = -1;
    bool linked_phoebe = false;
    bool linked_rover = false;
    int role_override = -1;
    double buff_override = -1;
    std::function<double(double,bool)> elapsed_accounting_for_freeze;
    double elapsed(double start,double now) const {
        return elapsed_accounting_for_freeze?elapsed_accounting_for_freeze(start,false):
               start<0?10000:now-start;
    }

    CharacterRole effective_role() const { return role_override < 0 ? definition->role : static_cast<CharacterRole>(role_override); }

    bool is_healer() const { return definition && effective_role() == CharacterRole::HEALER; }
    bool is_sub_dps() const { return definition && effective_role() == CharacterRole::SUB_DPS; }
    bool is_main_dps() const { return definition && effective_role() == CharacterRole::MAIN_DPS; }
    double buff_time() const { return buff_override >= 0 ? buff_override : definition ? definition->buff_seconds : 0; }
    bool has_buff(double now) const {
        return buff_time() > 0 && last_buff_time > 0 && elapsed(last_buff_time,now) < buff_time();
    }
    double buff_remaining(double now) const {
        if (!has_buff(now)) return 0;
        return std::max(0.0, buff_time() - elapsed(last_buff_time,now));
    }
    bool healer_full_con_switch_locked(double now) const {
        return is_healer() && last_full_con_switch_time >= 0 &&
               elapsed(last_full_con_switch_time,now) < 16.0;
    }
    void switch_out(double now, bool con_full) {
        last_switch_time = now;
        const bool full = con_full || current_con == 1;
        if (is_healer() && full) last_full_con_switch_time = now;
        is_current_char = false;
        has_intro = false;
        has_sub_dps_intro = false;
        if (full) {
            if (buff_time() > 0) last_buff_time = now;
            current_con = 0;
        }
    }
};

using OriginalPriority = std::function<int(const OriginalSwitchCharacter& candidate,
                                            const OriginalSwitchCharacter& current,
                                            bool has_intro, bool target_low_con,
                                            double now)>;

inline int choose_original_switch_target(const std::array<OriginalSwitchCharacter, 3>& chars,
                                         int current_index, bool has_intro,
                                         bool target_low_con, double now,
                                         const OriginalPriority& get_priority) {
    if (current_index < 0 || current_index >= 3) return -1;
    const auto& current = chars[current_index];
    std::vector<int> candidates;
    int highest_priority = 0;
    for (int i = 0; i < 3; ++i) {
        if (i == current_index || !chars[i].definition) continue;
        const int priority = chars[i].healer_full_con_switch_locked(now) ? 0 :
            get_priority(chars[i], current, has_intro, target_low_con, now);
        if (priority <= 0) continue;
        if (priority > highest_priority) {
            highest_priority = priority;
            candidates.clear();
        }
        if (priority == highest_priority) candidates.push_back(i);
    }
    if (candidates.empty()) return current_index;
    auto oldest = [&](const std::vector<int>& pool) -> int {
        if (pool.empty()) return -1;
        return *std::min_element(pool.begin(), pool.end(), [&](int a, int b) {
            if (chars[a].last_switch_in_time != chars[b].last_switch_in_time)
                return chars[a].last_switch_in_time < chars[b].last_switch_in_time;
            return chars[a].index < chars[b].index;
        });
    };
    auto filtered = [&](const std::vector<int>& pool, const std::function<bool(int)>& predicate) {
        std::vector<int> result;
        for (int i : pool) if (predicate(i)) result.push_back(i);
        return result;
    };
    auto unbuffed_support = [&](const std::vector<int>& pool, bool allow_healer = true) -> int {
        if (allow_healer) {
            const int healer = oldest(filtered(pool, [&](int i) {
                return chars[i].is_healer() && chars[i].buff_time() > 0 && !chars[i].has_buff(now);
            }));
            if (healer >= 0) return healer;
        }
        return oldest(filtered(pool, [&](int i) {
            return chars[i].is_sub_dps() && chars[i].buff_time() > 0 && !chars[i].has_buff(now);
        }));
    };
    if (has_intro) {
        if (highest_priority >= 400) return oldest(candidates);
        const int support = unbuffed_support(candidates);
        if (support >= 0) return support;
        for (CharacterRole role : {CharacterRole::MAIN_DPS, CharacterRole::SUB_DPS,
                                   CharacterRole::HEALER}) {
            const int found = oldest(filtered(candidates, [&](int i) {
                return chars[i].effective_role() == role;
            }));
            if (found >= 0) return found;
        }
        return current_index;
    }
    const auto cooled = filtered(candidates, [&](int i) {
        // OK-WW applies the cooldown predicate even when last_switch_time is -1.
        return chars[i].elapsed(chars[i].last_switch_time,now) > 1.0;
    });
    if (!cooled.empty()) candidates = cooled;
    if (current.is_main_dps()) {
        const auto buffers = filtered(candidates, [&](int i) {
            return !chars[i].is_main_dps() && chars[i].buff_time() > 0;
        });
        if (!buffers.empty()) {
            return *std::min_element(buffers.begin(), buffers.end(), [&](int a, int b) {
                const auto ka = std::array<double, 3>{chars[a].buff_remaining(now),
                    chars[a].last_switch_in_time, double(chars[a].index)};
                const auto kb = std::array<double, 3>{chars[b].buff_remaining(now),
                    chars[b].last_switch_in_time, double(chars[b].index)};
                return ka < kb;
            });
        }
    }
    if (!current.is_main_dps() && current.buff_time() > 0) {
        const int unbuffed = oldest(filtered(candidates, [&](int i) {
            return !chars[i].is_main_dps() && chars[i].buff_time() > 0 && !chars[i].has_buff(now);
        }));
        if (unbuffed >= 0) return unbuffed;
    }
    if (current.is_sub_dps() || current.is_healer()) {
        const int main = oldest(filtered(candidates, [&](int i) { return chars[i].is_main_dps(); }));
        if (main >= 0) return main;
    }
    const int support = unbuffed_support(candidates);
    if (support >= 0) return support;
    const int main = oldest(filtered(candidates, [&](int i) { return chars[i].is_main_dps(); }));
    return main >= 0 ? main : oldest(candidates);
}
