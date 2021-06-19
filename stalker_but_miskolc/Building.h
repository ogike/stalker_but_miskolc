//
// Created by zsozszsozsi on 2021. 06. 19..
//

#pragma once

#include <vector>

#include "Weapon.h"
#include "Human.h"

class Building
{
    protected:
        std::vector<Human*> workers;

    public:
        void assignWorker(Human* h);
};


class Blacksmith : public Building
{
    private:
        // Inventory
        int iron = 0;
        int leather = 0;


        std::vector<Weapon*> armory;

    public:
        Weapon* createWeapon();
};

