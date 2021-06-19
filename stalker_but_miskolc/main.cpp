
#include <ctime>

#include "Human.h"
#include "GroupBattle.h"
#include "WorldManager.h"
#include <iostream>

int main()
{

    srand (time(nullptr));


    WorldManager wm;

    std::vector<Human*> faction1;
    std::vector<Human*> faction2;

    for(int i = 0; i < 100; i++)
    {
        Human* h = wm.CreateHuman();
        faction1.push_back(h);
    }

    for(int i = 0; i < 100; i++)
    {
        Human* h = wm.CreateHuman();
        faction2.push_back(h);
    }

    //std::cout << faction1.size() << " " << faction2.size();

    GroupBattle aCsata2(faction1,faction2);
    //aCsata2.SimulateBattle();

    dateForm date = wm.getFormattedDate();
    std::cout << date << std::endl;

    wm.Simulate(15132);


}