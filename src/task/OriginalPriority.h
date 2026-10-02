#pragma once
#include <array>
#include <string_view>
#include "OriginalSwitch.h"

// Character overrides copied from the original get_switch_priority methods.
// Entries that need image/state observations are added beside their character
// ports; the BaseChar result is NORMAL (200) outside the healer lockout.
inline int original_priority_for_ported_character(
    const OriginalSwitchCharacter& candidate,
    const OriginalSwitchCharacter& current,
    bool has_intro, bool /*target_low_con*/, double now,
    const std::array<OriginalSwitchCharacter, 3>& team,
    const std::function<double(double,bool)>& elapsed = {}) {
    const auto since = [&](double start, bool intro = false) {
        return start < 0 ? 10000.0 : elapsed ? elapsed(start, intro) : now - start;
    };
    if (candidate.healer_full_con_switch_locked(now)) return 0;
    const auto name = candidate.definition->class_name;
    const auto from = current.definition->class_name;
    if(name=="Phoebe" && !has_intro && candidate.last_outro_time>0 && since(candidate.last_outro_time,true)<4.5) return 0;
    if(name=="Zani") {
        if(candidate.linkage_in_liberation) return 400;
        if(!candidate.linked_rover && candidate.linked_phoebe && has_intro && from!="Phoebe") return 0;
        if(has_intro && candidate.crisis_time>0 && since(candidate.crisis_time,true)<1.6) return 0;
    }
    if (name == "Linnai" && from == "Mornye") return 400;
    if (name == "Jinhsi")
        return has_intro || candidate.incarnation || candidate.incarnation_cd ? 400 : 0;
    if(name=="Cartethyia" && candidate.alternate_form) return 400;
    if(name=="Camellya" && has_intro) return 400;
    if (name == "Mornye" && has_intro) {
        if (from == "Aemeath" || from == "Qingxiao") return 400;
        bool has_linnai = false;
        for (const auto& member : team)
            has_linnai |= member.definition && member.definition->class_name == "Linnai";
        if (has_linnai && from != "Linnai") return 400;
    }
    if (name == "Hiyuki" && has_intro && (from == "Linnai" || from == "Lucilla")) return 400;
    if (name == "Lucilla" && has_intro && (from == "Verina" || from == "ShoreKeeper")) return 400;
    if (name == "Verina" && has_intro && from == "Hiyuki") return 400;
    if (name == "Douling") return since(candidate.last_perform) < 8 ? 0 : 200;
    if (name == "Encore") {
        if (since(candidate.last_heavy, true) < 4.6) return 0;
        if (since(candidate.liberation_time) < 9.5 ||
            since(candidate.last_resonance, true) < 2) return 400;
    }
    if (name == "Phrolova") {
        if (since(candidate.last_liberation) > 14 && has_intro && from == "Cantarella") return 400;
        if (since(candidate.last_liberation) < 24) return 0;
    }
    if (name == "Denia") {
        if (has_intro) {
            if ((from == "Aemeath" || from == "Qingxiao") && !candidate.has_buff(now)) return 200;
            return 1;
        }
        if (candidate.has_buff(now)) return 100;
    }
    if (name == "Cantarella" && has_intro &&
        (from == "Roccia" || from == "Sanhua")) return 400;
    if (name == "Luhesi" && has_intro && now-candidate.last_intro > 24) return 400;
    if (name == "Suisui") {
        const double since_last = since(candidate.last_forte3_switch);
        if (since_last > 40) return 400;
        if (since_last < 16) return 0;
        bool has_main_dps = false;
        for (const auto& member : team)
            has_main_dps |= member.definition && member.index != candidate.index && member.is_main_dps();
        if (has_main_dps && current.is_main_dps() && has_intro) return 400;
    }
    if (name == "Lucy" && has_intro && from == "Rebecca") return 400;
    if (name == "Changli" && has_intro && from == "Brant") return 400;
    if(name=="Carlotta" && has_intro && from=="Zhezhi") return 400;
    if(name=="Zhezhi") for(const auto& member:team)
        if(member.definition && member.definition->class_name=="Carlotta" && member.linkage_ready) return 400;
    if (name == "Brant") {
        if (since(candidate.perform_anchor, true) < 4) return 0;
        if (since(candidate.last_liberation) < 12) return 400;
        if (has_intro && from == "Lupa") return 400;
    }
    if (name == "Lupa") {
        if(since(candidate.last_liberation)<12 || (has_intro && from=="Changli")) return 400;
    }
    if(name=="Ciaccona" && candidate.linkage_in_liberation) {
        if(candidate.linkage_attribute==2 && since(candidate.last_liberation)<20) return 0;
        if(candidate.linkage_attribute==3) {
            bool cartethyia_form=true;
            for(const auto& member:team) if(member.definition && member.definition->class_name=="Cartethyia") cartethyia_form=!member.alternate_form;
            if(since(candidate.last_liberation)<8 || !cartethyia_form) return 0;
        }
    }
    if (name == "ShoreKeeper" && has_intro && from == "Augusta") return 400;
    return 200;
}
