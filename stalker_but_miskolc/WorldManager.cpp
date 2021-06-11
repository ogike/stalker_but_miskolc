//
// Created by zsozszsozsi on 2021. 06. 11..
//

#include "WorldManager.h"


WorldManager::WorldManager()
{
    f.open(filename);

    std::string name;

    while(!f.eof())
    {
        std::getline(f, name);
        names.push_back(name);
    }


    f.close();
}

Human* WorldManager::CreateHuman()
{
    int i = rand() % names.size();

    return new Human(names[i]);
}

int WorldManager::getDaysElapsed() const {
    return daysElapsed;
}

dateForm WorldManager::getFormattedDate() const{
    return Date::addDays(15, 3, 2031, daysElapsed); // startind date 2031.03.15
}

void WorldManager::Simulate(int days) {
    //itt kell majd mindent simulalni

    daysElapsed += days;
    dateForm date = Date::addDays(15, 3, 2031, daysElapsed);
    std::cout << "Days elapsed: " << days << ", current date: " << date;
}

