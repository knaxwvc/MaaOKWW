#pragma once
#include "../official/OfficialCharacter.h"
// Iuno official method bodies: ../official/generated/Iuno.cpp
class IunoOriginal final:public official::OfficialCharacter {
public:
    IunoOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Iuno"){}
};
