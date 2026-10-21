#pragma once
#include "../official/OfficialCharacter.h"
// Hsin official method bodies: ../official/generated/Hsin.cpp
class HsinOriginal final:public official::OfficialCharacter {
public:
    HsinOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Hsin"){}
};
