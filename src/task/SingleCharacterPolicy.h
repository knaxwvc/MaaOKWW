#pragma once
#include <array>
#include <string>
#include <string_view>

// One-member support is selected from the observed team, never a user lock.
// A two/three-member team immediately restores its normal switching policy.
struct SingleCharacterPolicy {
    bool enabled=false;
    int slot=0,known_team_count=0;
    std::string character;
    bool bind(int observed,int count,std::string_view identity) {
        if(observed<1 || observed>3 || count<observed || count>3)return false;
        if(count==1 && (identity.empty() || identity=="BaseChar"))return false;
        enabled=count==1;known_team_count=count;
        slot=enabled?observed:0;character=enabled?std::string(identity):std::string{};
        return true;
    }
    bool allows(int observed) const {return !enabled || (slot>0 && observed==slot);}
    bool can_probe_single_member(bool in_combat=false) const {return !in_combat || known_team_count<2;}
    bool single_member_hud(const std::array<bool,3>& portraits,bool skill_hud,bool in_combat=false) const {
        return can_probe_single_member(in_combat) && skill_hud && portraits[0] && !portraits[1] && !portraits[2];
    }
};
