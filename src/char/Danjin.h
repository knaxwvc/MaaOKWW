#pragma once
#include "../official/OfficialCharacter.h"
// Danjin official method bodies: ../official/generated/Danjin.cpp
class Danjin final:public official::OfficialCharacter {
public:
    Danjin(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Danjin"){}
};
