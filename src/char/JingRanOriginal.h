#pragma once
#include "../official/OfficialCharacter.h"
// JingRan official method bodies: ../official/generated/JingRan.cpp
class JingRanOriginal final:public official::OfficialCharacter {
public:
    JingRanOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"JingRan"){}
};
