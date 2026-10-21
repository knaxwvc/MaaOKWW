#pragma once
#include "../official/OfficialCharacter.h"
// Xiangliyao official method bodies: ../official/generated/Xiangliyao.cpp
class Xiangliyao final:public official::OfficialCharacter {
public:
    Xiangliyao(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Xiangliyao"){}
};
