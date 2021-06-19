//
// Created by zsozszsozsi on 2021. 06. 19..
//

#pragma once

#include <vector>
#include <string>

#include "Human.h"
#include "Building.h"

class Factions
{
    protected:
        //std::vector<Item> inventory;
        std::string factionName;
        Human* leader;
        std::vector<Human*> factionMembers;
        std::vector<Building*> buildings;

    public:
        Factions(std::string fName, Human* l, std::vector<Human*> fMembers);
        void addMember(Human* h);
        void removeMember(Human* h);
        void build(Building* b);


};