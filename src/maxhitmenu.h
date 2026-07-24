#pragma once

#include "menu.h"
#include "equipmentset.h"

class MaxHitMenu : Menu {
    public:
        void Navigate();
    private:
        EquipmentSet equips;
        void TopMenu();
        void TestEquipment(std::string newEquipment);
};