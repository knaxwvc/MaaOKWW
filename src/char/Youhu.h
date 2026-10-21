#pragma once
#include "../official/OfficialCharacter.h"
// Youhu official method bodies: ../official/generated/Youhu.cpp
class Youhu final:public official::OfficialCharacter {
public:
    Youhu(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Youhu"){}
};
