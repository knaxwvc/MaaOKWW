#pragma once
#include "../official/OfficialCharacter.h"
// Baizhi official method bodies: ../official/generated/Baizhi.cpp
class Baizhi final:public official::OfficialCharacter {
public:
    Baizhi(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Baizhi"){}
};
