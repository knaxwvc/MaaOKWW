#pragma once
#include "../official/OfficialCharacter.h"
// Xigelika official method bodies: ../official/generated/Xigelika.cpp
class XigelikaOriginal final:public official::OfficialCharacter {
public:
    XigelikaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Xigelika"){}
};
