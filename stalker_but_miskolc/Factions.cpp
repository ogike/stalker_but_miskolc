//
// Created by zsozszsozsi on 2021. 06. 19..
//

#include "Factions.h"

Factions::Factions(std::string fName, Human* l, std::vector<Human*> fMembers)
{
    factionName = fName;
    leader = l;
    factionMembers = fMembers;
}