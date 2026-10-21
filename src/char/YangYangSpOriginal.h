#pragma once
#include "../official/OfficialCharacter.h"
// YangYangSp official method bodies: ../official/generated/YangYangSp.cpp
class YangYangSpOriginal final:public official::OfficialCharacter {
public:
    YangYangSpOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"YangYangSp"){}
};
