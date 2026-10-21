#pragma once
#include "../official/OfficialCharacter.h"
// Yuanwu official method bodies: ../official/generated/Yuanwu.cpp
class Yuanwu final:public official::OfficialCharacter {
public:
    Yuanwu(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Yuanwu"){}
};
