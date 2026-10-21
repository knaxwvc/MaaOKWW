#pragma once
#include "../official/OfficialCharacter.h"
// Jiyan official method bodies: ../official/generated/Jiyan.cpp
class Jiyan final:public official::OfficialCharacter {
public:
    Jiyan(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Jiyan"){}
};
