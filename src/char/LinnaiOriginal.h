#pragma once
#include "../official/OfficialCharacter.h"
// Linnai official method bodies: ../official/generated/Linnai.cpp
class LinnaiOriginal final:public official::OfficialCharacter {
public:
    LinnaiOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Linnai"){}
};
