#pragma once
#include "../official/OfficialCharacter.h"
// Lupa official method bodies: ../official/generated/Lupa.cpp
class LupaOriginal final:public official::OfficialCharacter {
public:
    LupaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Lupa"){}
};
