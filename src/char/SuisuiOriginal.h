#pragma once
#include "../official/OfficialCharacter.h"
// Suisui official method bodies: ../official/generated/Suisui.cpp
class SuisuiOriginal final:public official::OfficialCharacter {
public:
    SuisuiOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Suisui"){}
};
