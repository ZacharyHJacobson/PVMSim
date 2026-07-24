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
                TestEquipment("Rune scimitar");
                TestEquipment("Barrows gloves");
                TestEquipment("Bronze 2h sword");
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

void MaxHitMenu::TestEquipment(std::string newEquipment)
{
    equips.addEquipment(Equipment(newEquipment));
    std::cout << newEquipment << " equipped" << std::endl;
    std::cout << "Total melee strength: " << equips.getTotalStat(Equipment::estat_MELEE_STRENGTH) << std::endl;
    std::cout << "Max hit: " << damage_calc::physicalMaxHit(118, damage_calc::piety_damage, damage_calc::aggressive_strength_bonus, damage_calc::melee_normal_void_damage, equips.getTotalStat(Equipment::estat_MELEE_STRENGTH)) << std::endl;
}