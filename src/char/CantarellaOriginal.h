#pragma once
#include "../official/OfficialCharacter.h"
// Cantarella official method bodies: ../official/generated/Cantarella.cpp
class CantarellaOriginal final:public official::OfficialCharacter {
public:
    CantarellaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Cantarella"){}
};
