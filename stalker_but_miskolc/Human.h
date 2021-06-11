//Created by: Geri
//Date: 2021-06-07
//Edited: 2021-06-10 By: Geri


#pragma once
#include "BodyParts.h"
#include "Weapon.h"
#include "Item.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

class Human
{
    public:
        Human(std::string n, int a, int h, int w);
        Human(std::string n);
        Human(Human* hP);

        static void Attack(Human* attacker, Human* defender);

        BodyPart head = Head(30,30);
        BodyPart thorax = Thorax(70,70);
        BodyPart leftArm = Arm(40,40);
        BodyPart rightArm = Arm(40,40);
        BodyPart leftLeg = Leg(40,40);
        BodyPart rightLeg = Leg(40,40);

        std::vector<Item*> myItems;
        int myMoney;

        void AddItem(Item* item);
        bool UseHealingItem();
	
        bool IsDead() const;
        void TakeHit(BodyPart* b, int amount);
        void Heal(float heal_amount, int wound_remove_chance);
        bool Parry(int n, int limit);//n: meddig general randomot; limit: mi folott jó
        bool Riposte(int n, int limit);//n: meddig general randomot; limit: mi folott jó
        float CalculateHealth();
        Weapon weapon = Sword();
        std::vector<BodyPart*> bodyPartList = {&head, &thorax, &leftArm, &leftLeg, &rightArm, &rightLeg}; // leheet privat kene
        std::vector<BodyPart*> limbs = {&leftArm, &leftLeg, &rightArm, &rightLeg};

        

    private:
        
        std::string name;
        int weight; //in kg
        int height; //in cm
        int age; //in days
        bool isDead = false;
        float health = 260; //sum of bodypart healths

    friend std::ostream& operator<< (std::ostream& o, Human& h)
    {
        o << "Name: " << h.name << std::endl;
        o << "Health: " << h.health << std::endl;
        o << "Weight: " << h.weight << std::endl;
        o << "Height: " << h.height << std::endl;
        o << "Weapon: " << h.weapon.name << std::endl;
        o << "BodyParts:" << std::endl;
        o << "\tHead: " << h.head;
        o << "\tThorax: " << h.thorax;
        o << "\tRightArm: " << h.rightArm;
        o << "\tLeftArm: " << h.leftArm;
        o << "\tRightLeg: " << h.rightLeg;
        o << "\tLeftLeg: " << h.leftLeg;

        return o;
    }
        
};

