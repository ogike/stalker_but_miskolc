//
// Created by zsozszsozsi on 2021. 06. 11..
//

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <ostream>
#include <cstdlib>


#ifdef __linux__
    //linux code goes here
#elif _WIN32
    #include <windows.h>

#endif

#include "Human.h"
#include "Date.h"
#include "Faction.h"

class WorldManager
{
    private:
        std::vector<std::string> names;

        std::string filename = "name.txt";
        std::ifstream f;
        int daysElapsed = 0; // starting date 2031.03.15.
        dateForm date;

    public:
        std::vector<Faction*> factions;

        WorldManager();
        ~WorldManager() {for(Faction* f : factions) delete f;}

        Human* CreateHuman();
        int getDaysElapsed() const;
        dateForm getFormattedDate() const;
        void Simulate(int days);

        TimeOfDay getTimeOfDay();

        void SimulateMorning();
        void SimulateAfternoon();
        void SimulateEvening();



};