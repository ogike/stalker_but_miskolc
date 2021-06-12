//Created by: Geri
//Date: 2021-06-09
//Edited: 2021-06-10 By: Geri

#include "GroupBattle.h"

GroupBattle::GroupBattle(std::vector<Human*> f1,std::vector<Human*> f2)
{
    faction1 = f1;
    faction2 = f2;
}

/*void GroupBattle::SimulateBattle()
{
    while(faction1.size() != 0 && faction2.size() != 0)
    {
        std::cout << "----------" << faction1.size() << " v " << faction2.size() << "----------" << std::endl;
        for (int i = 0; i < faction1.size(); i++)
        {
            if(faction2.size() == 0) break;

            int d = rand() % faction2.size();
            Human::Attack(faction1[i],faction2[d]);
            if(faction2[d]->IsDead() == true)
            {
                dead.push_back(faction2[d]);
                faction2.erase(faction2.begin()+d);
            }
            else if(faction1[i]->IsDead() == true)
            {
                dead.push_back(faction1[i]);
                faction1.erase(faction1.begin()+i);
            }
        }
        for (int i = 0; i < faction2.size(); i++)
        {
            if(faction1.size() == 0) break;

            int d = rand() % faction1.size();
            Human::Attack(faction2[i],faction1[d]);
            if(faction1[d]->IsDead() == true)
            {
                dead.push_back(faction1[d]);
                faction1.erase(faction1.begin()+d);
            }
            else if(faction2[i]->IsDead() == true)
            {
                dead.push_back(faction2[i]);
                faction2.erase(faction2.begin()+i);
            }
        }
    }
    std::cout << "----------" << faction1.size() << " v " << faction2.size() << "----------" << std::endl;
}*/