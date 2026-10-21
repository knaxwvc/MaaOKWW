#pragma once
#include "../official/OfficialCharacter.h"
// Rebecca official method bodies: ../official/generated/Rebecca.cpp
class RebeccaOriginal final:public official::OfficialCharacter {
public:
    RebeccaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Rebecca"){}
};
