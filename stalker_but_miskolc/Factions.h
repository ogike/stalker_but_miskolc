//
// Created by zsozszsozsi on 2021. 06. 19..
//

#pragma once

#include <vector>
#include "Building.h"

class Factions
{
    protected:
        std::string factionName;
        Human* leader;
        std::vector<Human*> factionMembers;
        std::vector<Building> buildings;

    public:
        Factions(std::string fName, Human* l, std::vector<Human*> fMembers);

};