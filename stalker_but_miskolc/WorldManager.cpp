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

int WorldManager::getDaysElapsed() const
{
    return daysElapsed;
}

dateForm WorldManager::getFormattedDate() const
{
    return Date::addDays(15, 3, 2031, daysElapsed); // startind date 2031.03.15
}

void WorldManager::Simulate(int days)
{
    for (int i = 0; i < days; i++)
    {
        //itt kell majd mindent simulalni

        //Sleep(10);

        daysElapsed += 1;
        date = Date::addDays(15, 3, 2031, daysElapsed);


        SimulateMorning();

        SimulateAfternoon();

        SimulateEvening();

    }
}

void WorldManager::SimulateMorning() {
    date.timeOfDay = MORNING;

    for(Faction* _f : factions)
    {
        _f->SimulateMorning();
    }

    std::cout << date;
    //Sleep(1000);
    #ifdef __linux__
        system("clear");
    #elif _WIN32
    #include <windows.h>
        system("cls");
    #endif

}

void WorldManager::SimulateAfternoon() {
    date.timeOfDay = AFTERNOON;

    for(Faction* _f : factions)
    {
        _f->SimulateAfternoon();
    }

    std::cout << date;
    //Sleep(1000);
    #ifdef __linux__
        system("clear");
    #elif _WIN32
    #include <windows.h>
        system("cls");
    #endif
}

void WorldManager::SimulateEvening() {
    date.timeOfDay = EVENING;

    for(Faction* _f : factions)
    {
        _f->SimulateEvening();
    }

    std::cout << date;
    //Sleep(1000);
    #ifdef __linux__
        system("clear");
    #elif _WIN32
    #include <windows.h>
        system("cls");
    #endif
}

TimeOfDay WorldManager::getTimeOfDay() {
    return date.timeOfDay;
}

