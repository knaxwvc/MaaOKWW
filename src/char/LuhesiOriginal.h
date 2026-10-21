#pragma once
#include "../official/OfficialCharacter.h"
// Luhesi official method bodies: ../official/generated/Luhesi.cpp
class LuhesiOriginal final:public official::OfficialCharacter {
public:
    LuhesiOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Luhesi"){}
};
