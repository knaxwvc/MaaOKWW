#pragma once
#include "../official/OfficialCharacter.h"
// Douling official method bodies: ../official/generated/Douling.cpp
class DoulingOriginal final:public official::OfficialCharacter {
public:
    DoulingOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Douling"){}
};
