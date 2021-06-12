//Created by: Geri
//Date: 2021-06-09
//Edited: 2021-06-11 By: Geri

#pragma once

#include <string>

class Weapon
{
    public:
        float damage;
        float durability;
        std::string name;

        enum Class
        {
            MELEE, RANGED
        };
        enum DamageType
        {
            PIERCE, BLUNT, SLASH
        };
        enum Type
        {
            PRIMITIVE, HIGH_CALIBER, LOW_CALIBER, SMALL, MEDIUM, LARGE
        };

        Type weaponType;
        DamageType damageType;
        Class weaponClass;
        Weapon(){}
        Weapon(float dmg, float dur, std::string n, Class wC, Type wT, DamageType wDT)
        {
            damage = dmg;
            durability = dur;
            name = n;
            weaponType = wT;
            damageType = wDT;
            weaponClass = wC;
        }
};

class Ranged : public Weapon
{
    public:
        float accuracy;
        Ranged(){}
        Ranged(float dmg, float acc, float dur, std::string n, Type wT, DamageType wDT) : Weapon(dmg,dur,n, RANGED, wT, wDT)
        {
            accuracy = acc;
        }    
};

class Melee : public Weapon
{
    public:
        Melee(){}
        Melee(float dmg, float dur, std::string n, Type wT, DamageType wDT) : Weapon(dmg,dur,n, MELEE, wT, wDT)
        {
            
        }
};

class Pistol : public Ranged
{
    public:
        
        Pistol() : Ranged(30,1,100,"Pistol", LOW_CALIBER, PIERCE)
        {
            
        }
};

class Rifle : public Ranged
{
    public:
        Rifle() : Ranged(50,1,100,"Rifle",HIGH_CALIBER,PIERCE)
        {
            
        }
};

class Sword : public Melee{
    public:
        Sword() : Melee(20,100,"Sword",MEDIUM,SLASH)
        {
            
        }
        /*Sword(std::string n)
        {
            damage = 50;
            durability = 100;
            name = n;
        }*/
};

class Hammer : public Melee{
    public:
        Hammer() : Melee(15,100,"Hammer",SMALL,BLUNT)
        {
            
        }
};

class GreatSword : public Melee{
    public:
        GreatSword() : Melee(30,100,"Great Sword",LARGE,SLASH)
        {
            
        }
};