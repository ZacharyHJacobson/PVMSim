#include "maxhitmenu.h"
#include <iostream>
#include "..\\lib\\damagecalc.h"

enum Choices
{
    TOP_MENU,
    DEMO,
    EXIT
};

void MaxHitMenu::Navigate()
{
    enum Choices choice = TOP_MENU;
    while(choice != EXIT)
    {
        switch(choice)
        {
            case DEMO:
                std::cout << "Max hit: " << damage_calc::physicalMaxHit(118, damage_calc::piety_damage, damage_calc::aggressive_strength_bonus, damage_calc::melee_normal_void_damage, 100) << std::endl;
                TopMenu();
                break;
            case TOP_MENU:
                TopMenu();
                break;
            default:
                throw std::runtime_error("unhandled choice");
                break;
        }
        choice = (Choices)ProcessMenu();
    }
}

void MaxHitMenu::TopMenu()
{
    AddOption("Demo", (int)DEMO);
    AddOption("Back", (int)EXIT);
}
