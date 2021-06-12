//Created by: Geri
//Date: 2021-06-09
//Edited: 2021-06-10 By: Geri

#include "Human.h"
#include "Utils.h"
#include <sstream>

Human::Human(std::string n, int a, int h, int w)
{
    name = n;
    age = a;
    height = h;
    weight = w;
}

Human::Human(std::string n)
{
    name = n;
    int a = rand() % 18000 + 6480; // age generated in days 18-68
    age = a;
    int h = rand() % 40 + 160;
    height = h;
    int w = rand() % 40 + 55;
    weight = w;
}

//--------A MONUMENT TO OUR FALIURE-------------

/*Human::Human(Human* hP)
{
    name=hP->name;
    weight=hP->weight; 
    height=hP->height; 
    age=hP->age; 
    isDead = hP->isDead;
    health = hP->health;

    head = hP->head;
    thorax = hP->thorax;
    leftArm = hP->leftArm;
    rightArm = hP->rightArm;
    leftLeg = hP->leftLeg;
    rightLeg = hP->leftLeg;    
                                                        
    weapon = hP->weapon;
    bodyPartList = {&head, &thorax, &leftArm, &leftLeg, &rightArm, &rightLeg};
}*/

//----------------------------------------------

float Human::CalculateHealth()
{
    health = 0;
    for (BodyPart *b : bodyPartList)
    {
        health += b->GetCurHealth();
    }
    if (thorax.GetCurHealth() == 0 || head.GetCurHealth() == 0)
    {
        isDead = true;
    }
    return health;
}

void Human::TakeHit(BodyPart *b, int amount)
{
    b->ModifyCurHealth(-amount);
    
    CalculateHealth();
    if(isDead == false)
    {
        b->AddCondition(BodyPart::WOUND);
        if (b->GetCurHealth() == 0)
        {
            b->AddCondition(BodyPart::MAJOR_WOUND);
            b->RemCondition(BodyPart::WOUND);
            battleStatus = RETREATING;
        }
    }
    
}

bool Human::IsDead() const
{
    return isDead;
}

bool CalcParryChance(int n, int limit)
{
    int chance = rand() % n;
    if (chance > limit)
    {
        return false;
    }
    return true;
}



bool Human::Parry(Human *attacker) //calculates if the parry was succesful
{
    Weapon::Class attackerWeaponClass = attacker->weapon.weaponClass;
    Weapon::Class defenderWeaponClass = weapon.weaponClass;

    Weapon::Type attackerWeaponType = attacker->weapon.weaponType;
    Weapon::Type defenderWeaponType = weapon.weaponType;

    int parryChance;

    switch (attackerWeaponClass)
    {
    case Weapon::RANGED:
        switch (attackerWeaponType)
        {
        case Weapon::PRIMITIVE:
            
            return ChanceCalc(5);
            break;

        default:
            return false;
            break;
        }
        break;

    case Weapon::MELEE:
        if (defenderWeaponClass == Weapon::RANGED)
        {
            return false;
        }
        else
        {
            switch (attackerWeaponType)
            {
            case Weapon::LARGE:
                switch (defenderWeaponType)
                {
                case Weapon::LARGE:
                    
                    return ChanceCalc(50);
                    break;

                case Weapon::MEDIUM:
                    
                    return ChanceCalc(25);
                    break;

                case Weapon::SMALL:
                    return false;
                    break;
                }
                break;

            case Weapon::MEDIUM:
                switch (defenderWeaponType)
                {
                case Weapon::LARGE:
                    return ChanceCalc(50);
                    break;

                case Weapon::MEDIUM:
                    return ChanceCalc(50);
                    break;

                case Weapon::SMALL:
                    return ChanceCalc(10);
                    break;
                }
                break;

            case Weapon::SMALL:
                switch (defenderWeaponType)
                {
                case Weapon::LARGE:
                    return ChanceCalc(10);
                    break;

                case Weapon::MEDIUM:
                    return ChanceCalc(10);
                    break;

                case Weapon::SMALL:
                    return ChanceCalc(10);
                    break;
                }
                break;
            }
        }
    }
    return false;
}
bool Human::Riposte(Human* attacker, int basePercentage) //calculates if the riposte was succesful
{
    return ChanceCalc(basePercentage);
}

void Human::Attack(Human *attacker, Human *defender, int distance)
{
    if (attacker->weapon.weaponClass == Weapon::RANGED && defender->weapon.weaponClass == Weapon::RANGED)
    {
        //Human::RangedFight(attacker, defender, distance);
    }
    else if (attacker->weapon.weaponClass == Weapon::MELEE && defender->weapon.weaponClass == Weapon::MELEE)
    {
        Human::MeleeFight(attacker, defender, distance);
    }
    else
    {
        //MixedFight(attacker, defender, distance);
    }
}

bool isFightOver(Human *attacker, Human *defender)
{
    if (attacker->battleStatus == Human::RETREATING || defender->battleStatus == Human::RETREATING || attacker->IsDead() || defender->IsDead())
    {
        return true;
    }
    return false;
}

void Human::MeleeFight(Human *attacker, Human *defender, int distance)
{
    std::stringstream userOutput;

    Human *curAttacker;
    Human *curDefender;

    BodyPart *targetBodyPartAttacker = nullptr;
    BodyPart *targetBodyPartDefender = nullptr;

    int i = 2;
    
    while (!isFightOver(attacker, defender))
    {
        //REPRESENTS ONE "TURN" OF MELEE COMBAT

        //Decides the atteck of this turn
        if(i % 2 == 0)
        {
            curAttacker = attacker;
            curDefender = defender;
        }
        else
        {
            curAttacker = defender;
            curDefender = attacker;
        }

        userOutput << curAttacker->name << " attacked " << curDefender->name << " with " << curAttacker->weapon.name << "!";

        if (!curDefender->Parry(curAttacker)) // The initial attack was not parried
        {
            
            int i = rand() % curDefender->bodyPartList.size();
            curDefender->TakeHit(curDefender->bodyPartList[i], curAttacker->weapon.damage);
            targetBodyPartDefender = curDefender->bodyPartList[i];

            userOutput << " and hit them on their " << curDefender->bodyPartStrings[i] << "." << std::endl;

            //If conditions are met, the defender can attack back
            if (!curDefender->isDead && !curDefender->battleStatus != Human::RETREATING && curDefender->Riposte(curAttacker,25))
            {
                userOutput << curDefender->name << " attacked back";

                //The riposte can be parried too
                if(curAttacker->Parry(curDefender))
                {
                    userOutput << " but got parried." << std::endl;
                }
                else
                {
                    i = rand() % curAttacker->bodyPartList.size();
                    curAttacker->TakeHit(curAttacker->bodyPartList[i], curDefender->weapon.damage);
                    targetBodyPartAttacker = curAttacker->bodyPartList[i];
                    userOutput << " and hit " << curAttacker->name << " on their " << curAttacker->bodyPartStrings[i] << "." << std::endl;
                }
            }
        }
        else // The initial attack was parried
        {
            userOutput << " but got parried." << std::endl;

            //If conditions are met, the defender can attack back
            if (curDefender->Riposte(curAttacker,50))
            {
                userOutput << curDefender->name << " attacked back";

                //The riposte can be parried too
                if(curAttacker->Parry(curDefender))
                {
                    userOutput << " but got parried." << std::endl;
                }
                else
                {
                    i = rand() % curAttacker->bodyPartList.size();
                    curAttacker->TakeHit(curAttacker->bodyPartList[i], curDefender->weapon.damage);
                    targetBodyPartAttacker = curAttacker->bodyPartList[i];
                    userOutput << " and hit " << curAttacker->name << " on their " << curAttacker->bodyPartStrings[i] << "." << std::endl;
                }
            }
        }

        //Decides the ending message for the fight

        if(curDefender->battleStatus == Human::RETREATING)
        {
            userOutput << curDefender->name << " is retreating!"<< std::endl;
        }
        else if(curAttacker->battleStatus == Human::RETREATING)
        {
            userOutput << curAttacker->name << " is retreating!"<< std::endl;
        }
        else if (curDefender->isDead == true)
        {
            if (targetBodyPartDefender == &curDefender->head)
            {
                userOutput << curAttacker->name << " beheaded " << curDefender->name << "!" << std::endl;
            }
            else
            {
                userOutput << curDefender->name << " got killed in the fight by " << curAttacker->name << "!" << std::endl;
            }
        }
        else if (curAttacker->isDead == true)
        {
            if (targetBodyPartAttacker == &curAttacker->head)
            {
                userOutput << curDefender->name << " beheaded " << curAttacker->name << "!" << std::endl;
            }
            else
            {
                userOutput << curAttacker->name << " got killed in the fight by " << curDefender->name << "!" << std::endl;
            }
        }
        userOutput << std::endl;
        
        i++;
    }
    std::cout << userOutput.str();
    std::cout << *attacker << std::endl;
    std::cout << *defender << std::endl;
}
