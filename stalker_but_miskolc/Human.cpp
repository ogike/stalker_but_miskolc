//Created by: Geri
//Date: 2021-06-09
//Edited: 2021-06-10 By: Geri

#include "Human.h"
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
    for (BodyPart* b: bodyPartList)
    {
        health += b->GetCurHealth();
    }
    if(thorax.GetCurHealth() == 0 || head.GetCurHealth() == 0)
    {
        isDead = true;
    }
    return health;
}

void Human::TakeHit(BodyPart* b, int amount)
{
    b->ModifyCurHealth(-amount);
    b->AddCondition(BodyPart::WOUND);
    int i = rand() % 2;
    if(b->GetCurHealth() == 0)
    {
        b->AddCondition(BodyPart::MAJOR_WOUND);
        b->RemCondition(BodyPart::WOUND);
    }
    CalculateHealth();
}

bool Human::IsDead() const
{
    return isDead;
}
bool Human::Parry(int n, int limit) //calculates if the parry was succesful
{
    int parryChance = rand() % n;
    if(parryChance < limit)
    {
        return false;
    }
    return true;
}
bool Human::Riposte(int n, int limit) //calculates if the riposte was succesful
{
    int riposteChance = rand() % n;
    if(riposteChance < limit)
    {
        return false;
    }
    return true;
}

void Human::Attack(Human *attacker, Human *defender)
{
    /*if(attacker->leftLeg.GetCurHealth() != 0 && attacker->rightLeg.GetCurHealth() != 0)
    {*/
        std::stringstream userOutput;

        BodyPart* targetBodyPartAttacker = nullptr;
        BodyPart* targetBodyPartDefender = nullptr;

        userOutput << attacker->name << " attacked " << defender->name;
        if(!defender->Parry(9,6))
        {
            userOutput << " and hit them." << std::endl;
            int i = rand() % defender->bodyPartList.size();
            defender->TakeHit(defender->bodyPartList[i],attacker->weapon.damage);
            targetBodyPartDefender = defender->bodyPartList[i];

            
            if(!defender->isDead && defender->Riposte(9,7))
            {
                i = rand() % attacker->bodyPartList.size();
                attacker->TakeHit(attacker->bodyPartList[i],defender->weapon.damage);
                targetBodyPartAttacker = attacker->bodyPartList[i];
                userOutput << defender->name << " attacked back " << attacker->name << "." << std::endl;
            }
        }
        else
        {
            userOutput << " but got parried." << std::endl;
            if(defender->Riposte(9,4))
            {
                int i = rand() % attacker->bodyPartList.size();
                attacker->TakeHit(attacker->bodyPartList[i],defender->weapon.damage);
                targetBodyPartAttacker = attacker->bodyPartList[i];
                userOutput << defender->name << " attacked back " << attacker->name << "." << std::endl;
            }
        }
        
        if(defender->isDead == true)
        {
            if(targetBodyPartDefender == &defender->head)
            {
                userOutput << attacker->name << " beheaded " << defender->name << "!" << std::endl;
            }
            else
            {
                userOutput << defender->name << " got killed in the fight by " << attacker->name << "!" << std::endl;
            }
        }
        else if(attacker->isDead == true)
        {
            if(targetBodyPartAttacker == &attacker->head)
            {
                userOutput << defender->name << " beheaded " << attacker->name << "!" << std::endl;
            }
            else
            {
                userOutput << attacker->name << " got killed in the fight by " << defender->name << "!" << std::endl;
            }
        }
        userOutput << std::endl;

        std::cout << userOutput.str();
    /*{
    else
    {
        std::cout << attacker->name << " couldn't attack " << defender->name << " because of their injuries." << std::endl;
    }*/
    
}

std::string Human::getName() const {
    return name;
}

