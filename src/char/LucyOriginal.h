#pragma once
#include "../official/OfficialCharacter.h"
// Lucy official method bodies: ../official/generated/Lucy.cpp
class LucyOriginal final:public official::OfficialCharacter {
public:
    LucyOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Lucy"){}
};
