//
// Created by zsozszsozsi on 2021. 06. 11..
//

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <ostream>

#include "Human.h"
#include "Date.h"

class WorldManager
{
    private:
        std::vector<std::string> names;
        std::string filename = "name.txt";
        std::ifstream f;
        int daysElapsed = 0; // starting date 2031.03.15.

    public:
        WorldManager();
        Human* CreateHuman();
        int getDaysElapsed() const;
        dateForm getFormattedDate() const;
        void Simulate(int days);



};