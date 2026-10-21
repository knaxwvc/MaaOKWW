#pragma once
#include "../official/OfficialCharacter.h"
// Camellya official method bodies: ../official/generated/Camellya.cpp
class CamellyaOriginal final:public official::OfficialCharacter {
public:
    CamellyaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Camellya"){}
};
