#include "equipmentset.h"

void EquipmentSet::addEquipment(Equipment e)
{
    equipment[e.GetSlot()] = e;
}

int EquipmentSet::getTotalStat(Equipment::Stat s)
{
    int total = 0;
    for (auto equip : equipment) {
        total += equip.stats[s];
    }
    return total;
}

int EquipmentSet::getSpeed()
{
    return equipment[Equipment::WEAPON].GetSpeed();
}

EquipmentSet::EquipmentSet()
{

}
