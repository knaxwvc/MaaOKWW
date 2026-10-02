#pragma once
#include <algorithm>
#include <array>
#include <vector>

// Port of OK-WW BaseCombatTask._choose_switch_target and
// BaseChar.switch_out for the supported three-character teams.
// Roles: 0 healer, 1 sub DPS, 2 main DPS. Commit a switch only after HUD
// recognition confirms that the target character is actually active.
struct CombatAxis {
    static constexpr int no = 0, low = 100, normal = 200, must = 400;
    std::array<double, 3> buff_until{};
    std::array<double, 3> last_entry{{-1, -1, -1}};
    std::array<double, 3> last_switch{{-1, -1, -1}};
    double healer_full_switch = -1;
    int current_role = -1;
    bool intro = false;
    int team = 0;

    double buff_seconds(int role) const {
        if (role == 0) return team == 2 ? 20.0 : 28.0;
        return 14.0;
    }
    bool buff_active(int role, double now) const { return buff_until[role] > now; }
    double buff_remaining(int role, double now) const {
        return std::max(0.0, buff_until[role] - now);
    }
    bool all_buffs(double now) const {
        return intro && buff_active(0, now) && buff_active(1, now);
    }
    bool healer_locked(double now) const {
        return healer_full_switch >= 0 && now - healer_full_switch < 16.0;
    }
    int priority(int candidate, int current, bool has_intro, double now) const {
        if (candidate == 0 && healer_locked(now)) return no;
        if (team == 1) {
            if (candidate == 1 && current == 0) return must; // Mornye -> Linnai
            if (candidate == 0 && has_intro && current != 1) return must;
        }
        if (team == 2 && candidate == 2 && has_intro && current == 1) return must;
        if (team == 3 && candidate == 1) {
            if (has_intro) return current == 2 && !buff_active(1, now) ? normal : no + 1;
            if (buff_active(1, now)) return low;
        }
        return normal;
    }
    int oldest(const std::vector<int>& candidates) const {
        return *std::min_element(candidates.begin(), candidates.end(), [&](int a, int b) {
            if (last_entry[a] != last_entry[b]) return last_entry[a] < last_entry[b];
            return a < b;
        });
    }
    int unbuffed_support(const std::vector<int>& candidates, double now) const {
        for (int role : {0, 1})
            if (std::find(candidates.begin(), candidates.end(), role) != candidates.end() &&
                !buff_active(role, now)) return role;
        return -1;
    }
    int choose_switch_target(double now, bool has_intro) const {
        if (current_role < 0) return -1;
        std::vector<int> candidates;
        int best_priority = no;
        for (int role = 0; role < 3; ++role) {
            if (role == current_role) continue;
            const int value = priority(role, current_role, has_intro, now);
            if (value > best_priority) { candidates.clear(); best_priority = value; }
            if (value == best_priority && value > no) candidates.push_back(role);
        }
        if (candidates.empty()) return current_role;
        if (has_intro) {
            if (best_priority >= must) return oldest(candidates);
            const int support = unbuffed_support(candidates, now);
            if (support >= 0) return support;
            for (int role : {2, 1, 0})
                if (std::find(candidates.begin(), candidates.end(), role) != candidates.end()) return role;
        }
        std::vector<int> cooled;
        for (int role : candidates)
            if (last_switch[role] < 0 || now - last_switch[role] > 1.0) cooled.push_back(role);
        if (!cooled.empty()) candidates = std::move(cooled);
        if (current_role == 2) {
            std::vector<int> supports;
            for (int role : candidates) if (role < 2) supports.push_back(role);
            if (!supports.empty()) return *std::min_element(supports.begin(), supports.end(), [&](int a, int b) {
                if (buff_remaining(a, now) != buff_remaining(b, now))
                    return buff_remaining(a, now) < buff_remaining(b, now);
                if (last_entry[a] != last_entry[b]) return last_entry[a] < last_entry[b];
                return a < b;
            });
        } else {
            std::vector<int> unbuffed;
            for (int role : candidates) if (role < 2 && !buff_active(role, now)) unbuffed.push_back(role);
            if (!unbuffed.empty()) return oldest(unbuffed);
            if (std::find(candidates.begin(), candidates.end(), 2) != candidates.end()) return 2;
        }
        const int support = unbuffed_support(candidates, now);
        if (support >= 0) return support;
        if (std::find(candidates.begin(), candidates.end(), 2) != candidates.end()) return 2;
        return oldest(candidates);
    }
    void switched(int target, double now, bool previous_full) {
        if (current_role >= 0) {
            last_switch[current_role] = now;
            if (previous_full) {
                buff_until[current_role] = now + buff_seconds(current_role);
                if (current_role == 0) healer_full_switch = now;
            }
        }
        current_role = target;
        last_entry[target] = now;
        intro = previous_full;
    }
};
