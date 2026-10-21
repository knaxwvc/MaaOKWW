#pragma once
#include "../official/OfficialCharacter.h"
// Zhezhi official method bodies: ../official/generated/Zhezhi.cpp
class ZhezhiOriginal final:public official::OfficialCharacter {
public:
    ZhezhiOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Zhezhi"){}
};
