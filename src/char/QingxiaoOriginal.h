#pragma once
#include "../official/OfficialCharacter.h"
// Qingxiao official method bodies: ../official/generated/Qingxiao.cpp
class QingxiaoOriginal final:public official::OfficialCharacter {
public:
    QingxiaoOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Qingxiao"){}
};
