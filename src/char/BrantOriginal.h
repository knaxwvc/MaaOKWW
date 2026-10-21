#pragma once
#include "../official/OfficialCharacter.h"
// Brant official method bodies: ../official/generated/Brant.cpp
class BrantOriginal final:public official::OfficialCharacter {
public:
    BrantOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Brant"){}
};
