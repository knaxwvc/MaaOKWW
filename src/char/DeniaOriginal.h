#pragma once
#include "../official/OfficialCharacter.h"
// Denia official method bodies: ../official/generated/Denia.cpp
class DeniaOriginal final:public official::OfficialCharacter {
public:
    DeniaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Denia"){}
};
