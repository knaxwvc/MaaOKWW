#pragma once
#include "../official/OfficialCharacter.h"
// Rover official method bodies: ../official/generated/Rover.cpp
class RoverOriginal final:public official::OfficialCharacter {
public:
    RoverOriginal(OriginalCombatIO& io,OriginalSwitchCharacter& member):OfficialCharacter(io,member,"Rover"){}
};
