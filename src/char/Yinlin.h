#pragma once
#include "../official/OfficialCharacter.h"
// Yinlin official method bodies: ../official/generated/Yinlin.cpp
class Yinlin final:public official::OfficialCharacter {
public:
    Yinlin(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Yinlin"){}
};
