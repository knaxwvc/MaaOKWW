#pragma once
#include "../official/OfficialCharacter.h"
// Mortefi official method bodies: ../official/generated/Mortefi.cpp
class Mortefi final:public official::OfficialCharacter {
public:
    Mortefi(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Mortefi"){}
};
