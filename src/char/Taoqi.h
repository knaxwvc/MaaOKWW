#pragma once
#include "../official/OfficialCharacter.h"
// Taoqi official method bodies: ../official/generated/Taoqi.cpp
class Taoqi final:public official::OfficialCharacter {
public:
    Taoqi(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Taoqi"){}
};
