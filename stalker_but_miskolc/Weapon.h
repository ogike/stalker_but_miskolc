//Created by: Geri
//Date: 2021-06-09
//Edited: 2021-06-09 By: Geri

#pragma once

#include <string>

class Weapon
{
    public:
        float damage;
        float durability;
        std::string name;
};

class Sword : public Weapon{
    public:
        Sword()
        {
            damage = 15;
            durability = 100;
            name = "Sword";
        }
        Sword(std::string n)
        {
            damage = 50;
            durability = 100;
            name = n;
        }
};