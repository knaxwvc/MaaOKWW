#pragma once
#include "../official/OfficialCharacter.h"
// Sanhua official method bodies: ../official/generated/Sanhua.cpp
class Sanhua final:public official::OfficialCharacter {
public:
    Sanhua(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Sanhua"){}
};
