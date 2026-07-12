#include "maxhitmenu.h"
#include "equipmentset.h"
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
    EquipmentSet equips;
    while(choice != EXIT)
    {
        switch(choice)
        {
            case DEMO:
                equips.addEquipment(Equipment("Rune scimitar"));
                std::cout << "Total melee strength: " << equips.getTotalStat(Equipment::MELEE_STRENGTH) << std::endl;
                std::cout << "Max hit: " << damage_calc::physicalMaxHit(118, damage_calc::piety_damage, damage_calc::aggressive_strength_bonus, damage_calc::melee_normal_void_damage, equips.getTotalStat(Equipment::MELEE_STRENGTH)) << std::endl;
                equips.addEquipment(Equipment("Barrows gloves"));
                std::cout << "Total melee strength: " << equips.getTotalStat(Equipment::MELEE_STRENGTH) << std::endl;
                std::cout << "Max hit: " << damage_calc::physicalMaxHit(118, damage_calc::piety_damage, damage_calc::aggressive_strength_bonus, damage_calc::melee_normal_void_damage, equips.getTotalStat(Equipment::MELEE_STRENGTH)) << std::endl;
                equips.addEquipment(Equipment("Bronze scimitar"));
                std::cout << "Total melee strength: " << equips.getTotalStat(Equipment::MELEE_STRENGTH) << std::endl;
                std::cout << "Max hit: " << damage_calc::physicalMaxHit(118, damage_calc::piety_damage, damage_calc::aggressive_strength_bonus, damage_calc::melee_normal_void_damage, equips.getTotalStat(Equipment::MELEE_STRENGTH)) << std::endl;
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
