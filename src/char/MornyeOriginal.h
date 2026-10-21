#pragma once
#include "../official/OfficialCharacter.h"
// Mornye official method bodies: ../official/generated/Mornye.cpp
class MornyeOriginal final:public official::OfficialCharacter {
public:
    MornyeOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Mornye"){}
};
