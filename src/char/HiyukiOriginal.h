#pragma once
#include "../official/OfficialCharacter.h"
// Hiyuki official method bodies: ../official/generated/Hiyuki.cpp
class HiyukiOriginal final:public official::OfficialCharacter {
public:
    HiyukiOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Hiyuki"){}
};
