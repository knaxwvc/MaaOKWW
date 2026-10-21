#pragma once
#include "../official/OfficialCharacter.h"
// Phoebe official method bodies: ../official/generated/Phoebe.cpp
class PhoebeOriginal final:public official::OfficialCharacter {
public:
    PhoebeOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Phoebe"){}
};
