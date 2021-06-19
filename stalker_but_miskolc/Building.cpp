//
// Created by zsozszsozsi on 2021. 06. 19..
//

#include "Building.h"

Weapon* Blacksmith::createWeapon()
{
    if(iron > 30 && leather > 10)
    {
        return new Weapon();
    }
}

void Building::assignWorker(Human *h)
{

}
