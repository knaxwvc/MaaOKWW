#pragma once
#include "../official/OfficialCharacter.h"
// Cartethyia official method bodies: ../official/generated/Cartethyia.cpp
class CartethyiaOriginal final:public official::OfficialCharacter {
public:
    CartethyiaOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Cartethyia"){}
};
