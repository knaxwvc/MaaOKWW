#pragma once
#include "../official/OfficialCharacter.h"
// Ciaccona official method bodies: ../official/generated/Ciaccona.cpp
class CiacconaOriginal final:public official::OfficialCharacter {
public:
    CiacconaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Ciaccona"){}
};
