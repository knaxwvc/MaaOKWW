#pragma once
#include "../official/OfficialCharacter.h"
// Lucilla official method bodies: ../official/generated/Lucilla.cpp
class LucillaOriginal final:public official::OfficialCharacter {
public:
    LucillaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Lucilla"){}
};
