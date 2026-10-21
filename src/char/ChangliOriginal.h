#pragma once
#include "../official/OfficialCharacter.h"
// Changli official method bodies: ../official/generated/Changli.cpp
class ChangliOriginal final:public official::OfficialCharacter {
public:
    ChangliOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Changli"){}
};
