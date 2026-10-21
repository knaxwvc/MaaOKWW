#pragma once
#include "../official/OfficialCharacter.h"
// Chisa official method bodies: ../official/generated/Chisa.cpp
class ChisaOriginal final:public official::OfficialCharacter {
public:
    ChisaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Chisa"){}
};
