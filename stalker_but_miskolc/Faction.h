//
// Created by zsozszsozsi on 2021. 06. 19..
//

#pragma once

#include <vector>
#include <string>

#include "Human.h"
//#include "Building.h"

class Faction
{
    protected:
        //std::vector<Item> inventory;
        //std::vector<Building*> buildings;
        std::string factionName;
        Human* leader;
        std::vector<Human*> factionMembers;



    public:
        Faction(std::string fName, Human* l, std::vector<Human*> fMembers);
        void addMember(Human* h);
        void removeMember(Human* h);
        //void build(Building* b);
        virtual void SimulateMorning() = 0;
        virtual void SimulateAfternoon() = 0;
        virtual void SimulateEvening() = 0;
        virtual ~Faction() { for(Human* h : factionMembers) delete h; }

};

class Test : public Faction
{
    public:
        Test(std::string fName, std::vector<Human*> fMembers) : Faction(fName, nullptr, fMembers) {}
        void SimulateMorning() override;
        void SimulateAfternoon() override;
        void SimulateEvening() override;

};

class Test2 : public Faction
{
public:
    Test2(std::string fName, std::vector<Human*> fMembers) : Faction(fName, nullptr, fMembers) {}
    void SimulateMorning() override;
    void SimulateAfternoon() override;
    void SimulateEvening() override;

};