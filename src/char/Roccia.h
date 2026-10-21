#pragma once
#include "../official/OfficialCharacter.h"
// Roccia official method bodies: ../official/generated/Roccia.cpp
class Roccia final:public official::OfficialCharacter {
public:
    Roccia(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Roccia"){}
};
