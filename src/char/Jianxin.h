#pragma once
#include "../official/OfficialCharacter.h"
// Jianxin official method bodies: ../official/generated/Jianxin.cpp
class Jianxin final:public official::OfficialCharacter {
public:
    Jianxin(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Jianxin"){}
};
