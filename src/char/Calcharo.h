#pragma once
#include "../official/OfficialCharacter.h"
// Calcharo official method bodies: ../official/generated/Calcharo.cpp
class Calcharo final:public official::OfficialCharacter {
public:
    Calcharo(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Calcharo"){}
};
