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

void Factions::removeMember(Human *h) {
    if(std::count( factionMembers.begin(), factionMembers.end(), h ) == 1)
    {
        factionMembers.erase(std::find( factionMembers.begin(), factionMembers.end(), h ) );
    }
}

void Factions::addMember(Human *h) {
    if(std::count( factionMembers.begin(), factionMembers.end(), h ) == 0)
    {
        factionMembers.push_back(h);
    }
}

void Factions::build(Building *b) {
    // meg kell nézni van a pénz meg ilyenek
    buildings.push_back(b);
    // le kell vonni a dolgokat amibol elkeszult az epulet
}
