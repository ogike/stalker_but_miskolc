
#include <ctime>

#include "Human.h"
#include "GroupBattle.h"
#include "Factions.h"

#include <iostream>



int main()
{
    //setlocale(LC_ALL, "hun");

    srand (time(nullptr));
    
    /*Arm arm(50,50);
    
    std::cout << arm.GetCurHealth()<< " " << arm.GetMaxHealth() << std::endl;
    arm.ModifyCurHealth(-20);
    std::cout << arm.GetCurHealth()<< " " << arm.GetMaxHealth() << std::endl;
    arm.ModifyCurHealth(-200);
    std::cout << arm.GetCurHealth()<< " " << arm.GetMaxHealth() << std::endl;
    arm.ModifyCurHealth(200);
    std::cout << arm.GetCurHealth()<< " " << arm.GetMaxHealth() << std::endl;

    std::cout << arm.GetConditions().size() << std::endl;
    arm.AddCondition(BodyPart::INFECTION);
    std::cout << arm.GetConditions()[0] << " " << arm.GetConditions().size() << std::endl;
    arm.AddCondition(BodyPart::INFECTION);
    std::cout << arm.GetConditions().size() << std::endl;
    arm.RemCondition(BodyPart::INFECTION);
    arm.RemCondition(BodyPart::WOUND);
    std::cout << arm.GetConditions().size() << std::endl;*/


    /*Human h("dzson");
    
    h.weapon = Sword("Giroszoskard");
    h.leftArm.AddCondition(BodyPart::INFECTION);
    h.thorax.AddCondition(BodyPart::INFECTION);
    h.head.AddCondition(BodyPart::WOUND);
    h.head.AddCondition(BodyPart::INFECTION);
    std::cout << h << std::endl;

    Human h2("lajos");

    Human::Attack(&h,&h2);
    Human::Attack(&h,&h2);
   

    std::cout << h2 << std::endl;*/


    Human h1("Dzson");
    h1.weapon = Sword("Giroszoskard");
    Human h2("Lajos");
    Human h3("Tibi");
    Human h4("John");
    Human h5("Béla");
    Human h6("Type C");
    Human h7("Fáraó");
    Human h8("Az örvényesi rambó");
    Human h9("Jani");
    Human h10("Feri");

    Human g1("Menogyerek1");
    Human g2("Menogyerek2");
    Human g3("Menogyerek3");
    Human g4("Menogyerek4");
    Human g5("Menogyerek5");
    Human g6("Menogyerek6");
    Human g7("Menogyerek7");
    Human g8("Menogyerek8");
    Human g9("Menogyerek9");
    Human g10("Menogyerek10");
    
    std::vector<Human*> faction1 = {&h1,&h2,&h3,&h4,&h5,&h7,&h8,&h9,&h10,&h6};
    std::vector<Human*> faction2 = {&g1,&g2,&g3,&g4,&g5,&g6,&g7,&g8,&g9,&g10};

    GroupBattle aCsata(faction1,faction2);
    aCsata.SimulateBattle();

    /*std::cout << std::endl << "Eletuket vesztettek: " << std::endl;

    for (int i = 0; i < aCsata.dead.size(); i++)
    {
        std::cout << *(aCsata.dead[i]) << std::endl;
    }*/


    
    std::cout << std::endl << std::endl << (char)200 << "Thats all folks!" << " test" << std::endl;


    std::cout << "test2" << std::endl;


    Factions pirate("Kaloz", &h1, faction1);

}