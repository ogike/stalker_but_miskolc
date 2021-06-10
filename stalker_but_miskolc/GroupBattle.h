//Created by: Geri
//Date: 2021-06-09
//Edited: 2021-06-10 By: Geri

#pragma once

#include <vector>
#include "Human.h"

class GroupBattle
{
private:
    std::vector<Human*> faction1;
    std::vector<Human*> faction2;
    
public:
    std::vector<Human*> dead;
    GroupBattle(std::vector<Human*> f1,std::vector<Human*> f2);
    void SimulateBattle();
};




