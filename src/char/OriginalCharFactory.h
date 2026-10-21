#pragma once
#include <memory>
#include <string_view>
#include "../official/OfficialCharacter.h"
inline bool has_original_strategy(std::string_view name){for(const auto& definition:character_definitions)if(name==definition.class_name)return true;return false;}
inline std::shared_ptr<OriginalBaseChar> make_original_character(std::string_view name,OriginalCombatIO& io,OriginalSwitchCharacter& member){
    if(name!="BaseChar"&&!has_original_strategy(name))throw std::runtime_error("Unregistered official character");
    auto actor=std::make_shared<official::OfficialCharacter>(io,member,std::string(name));actor->bind_lifetime(actor);return actor;
}
