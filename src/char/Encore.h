#pragma once
#include "../official/OfficialCharacter.h"
// Encore official method bodies: ../official/generated/Encore.cpp
class Encore final:public official::OfficialCharacter {
public:
    Encore(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Encore"){}
};
