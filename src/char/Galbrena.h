#pragma once
#include "../official/OfficialCharacter.h"
// Galbrena official method bodies: ../official/generated/Galbrena.cpp
class Galbrena final:public official::OfficialCharacter {
public:
    Galbrena(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Galbrena"){}
};
