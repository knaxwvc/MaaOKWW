#pragma once
#include "../official/OfficialCharacter.h"
// Chixia official method bodies: ../official/generated/Chixia.cpp
class Chixia final:public official::OfficialCharacter {
public:
    Chixia(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Chixia"){}
};
