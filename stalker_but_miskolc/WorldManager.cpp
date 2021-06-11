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

Human WorldManager::CreateHuman()
{
    int i = rand() % names.size();

    return Human(names[i]);
}
