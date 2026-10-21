#pragma once
#include "../official/OfficialCharacter.h"
// Jinhsi official method bodies: ../official/generated/Jinhsi.cpp
class JinhsiOriginal final:public official::OfficialCharacter {
public:
    JinhsiOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Jinhsi"){}
};
