//
// Created by zsozszsozsi on 2021. 06. 11..
//

#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "Human.h"

class WorldManager
{
    private:
        std::vector<std::string> names;
        std::string filename = "name.txt";
        std::ifstream f;

    public:
        WorldManager();
        Human CreateHuman();

};