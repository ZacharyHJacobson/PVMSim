#pragma once

#include "equipment.h"
#include <map>

class EquipmentSet {
    public:
        void addEquipment(Equipment);
        int getTotalStat(Equipment::Stat);
        int getSpeed();
    private:
        Equipment equipment[Equipment::SLOTS_COUNT];
};