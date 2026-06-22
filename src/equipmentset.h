#pragma once

#include "equipment.h"
#include <map>

class EquipmentSet {
    public:
        void addEquipment(Equipment);
        int getTotalStat(Equipment::Stat);
        int getSpeed();
    private:
        std::map<Equipment::Slot, Equipment> equipment;
        Equipment equipment[Equipment::SLOTS_COUNT];
};