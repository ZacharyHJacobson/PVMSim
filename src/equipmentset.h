#pragma once

#include "equipment.h"
#include <map>

class EquipmentSet {
    public:
        void addEquipment(Equipment);
        int getTotalStat(Equipment::EquipmentStat);
        int getSpeed();
        EquipmentSet();
    private:
        Equipment equipment[Equipment::eslot_COUNT];
};