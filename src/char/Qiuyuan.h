#pragma once
#include "../official/OfficialCharacter.h"
// Qiuyuan official method bodies: ../official/generated/Qiuyuan.cpp
class Qiuyuan final:public official::OfficialCharacter {
public:
    Qiuyuan(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Qiuyuan"){}
};
