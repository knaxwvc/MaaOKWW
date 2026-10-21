#pragma once
#include "../official/OfficialCharacter.h"
// Aemeath official method bodies: ../official/generated/Aemeath.cpp
class AemeathOriginal final:public official::OfficialCharacter {
public:
    AemeathOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Aemeath"){}
};
