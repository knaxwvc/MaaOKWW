#pragma once
#include "../official/OfficialCharacter.h"
// ShoreKeeper official method bodies: ../official/generated/ShoreKeeper.cpp
class OriginalShoreKeeper final:public official::OfficialCharacter {
public:
    OriginalShoreKeeper(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"ShoreKeeper"){}
};
