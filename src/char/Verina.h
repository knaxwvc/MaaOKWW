#pragma once
#include "../official/OfficialCharacter.h"
// Verina official method bodies: ../official/generated/Verina.cpp
class Verina final:public official::OfficialCharacter {
public:
    Verina(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Verina"){}
};
