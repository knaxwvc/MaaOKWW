#pragma once
#include "../official/OfficialCharacter.h"
// Phrolova official method bodies: ../official/generated/Phrolova.cpp
class Phrolova final:public official::OfficialCharacter {
public:
    Phrolova(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Phrolova"){}
};
