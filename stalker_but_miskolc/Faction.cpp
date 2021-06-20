//
// Created by zsozszsozsi on 2021. 06. 19..
//

#include "Faction.h"

Faction::Faction(std::string fName, Human* l, std::vector<Human*> fMembers)
{
    factionName = fName;
    leader = l;
    factionMembers = fMembers;
}

void Faction::removeMember(Human *h) {
    if(std::count( factionMembers.begin(), factionMembers.end(), h ) == 1)
    {
        factionMembers.erase(std::find( factionMembers.begin(), factionMembers.end(), h ) );
    }
}

void Faction::addMember(Human *h) {
    if(std::count( factionMembers.begin(), factionMembers.end(), h ) == 0)
    {
        factionMembers.push_back(h);
    }
}

void Test::SimulateMorning()
{
    std::cout << factionName << ", simulated morning!\n";
}

void Test::SimulateAfternoon()
{
    std::cout << factionName << ", simulated afternoon!\n";
}

void Test::SimulateEvening()
{
    std::cout << factionName << ", simulated evening!\n";
}

void Test2::SimulateMorning()
{
    std::cout << factionName << ", simulated morning!\n";
}

void Test2::SimulateAfternoon()
{
    std::cout << factionName << ", simulated afternoon!\n";
}

void Test2::SimulateEvening()
{
    std::cout << factionName << ", simulated evening!\n";
}

/*void Faction::build(Building *b) {
    // meg kell nézni van a pénz meg ilyenek
    buildings.push_back(b);
    // le kell vonni a dolgokat amibol elkeszult az epulet
}*/