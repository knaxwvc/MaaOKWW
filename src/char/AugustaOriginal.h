#pragma once
#include "../official/OfficialCharacter.h"
// Augusta official method bodies: ../official/generated/Augusta.cpp
class AugustaOriginal final:public official::OfficialCharacter {
public:
    AugustaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Augusta"){}
};
