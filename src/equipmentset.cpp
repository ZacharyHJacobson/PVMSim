#include "equipmentset.h"

void EquipmentSet::addEquipment(Equipment e)
{
    if(e.GetSlot() == Equipment::eslot_TWOHAND)
    {
        equipment[Equipment::eslot_WEAPON] = Equipment();
        equipment[Equipment::eslot_SHIELD] = Equipment();
    }
    else if((e.GetSlot() == Equipment::eslot_WEAPON)||(e.GetSlot() == Equipment::eslot_SHIELD))
    {
        equipment[Equipment::eslot_TWOHAND] = Equipment();
    }
    equipment[e.GetSlot()] = e;
}

int EquipmentSet::getTotalStat(Equipment::EquipmentStat s)
{
    int total = 0;
    for (auto equip : equipment) {
        total += equip.stats[s];
    }
    return total;
}

int EquipmentSet::getSpeed()
{
    return equipment[Equipment::eslot_WEAPON].GetSpeed();
}

EquipmentSet::EquipmentSet()
{

}
