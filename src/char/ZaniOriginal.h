#pragma once
#include "../official/OfficialCharacter.h"
// Zani official method bodies: ../official/generated/Zani.cpp
class ZaniOriginal final:public official::OfficialCharacter {
public:
    ZaniOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Zani"){}
};
