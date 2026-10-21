#pragma once
#include "../official/OfficialCharacter.h"
// Carlotta official method bodies: ../official/generated/Carlotta.cpp
class CarlottaOriginal final:public official::OfficialCharacter {
public:
    CarlottaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Carlotta"){}
};
