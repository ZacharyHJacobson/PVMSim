#include "equipment.h"

int Equipment::ApplyBane(int max_hit, Encounter encounter)
{
    return max_hit;
}

Equipment::Slot Equipment::GetSlot()
{
    return slot;
}

int Equipment::GetSpeed()
{
    return speed;
}

Equipment::Equipment(Slot s)
{
    if(s == WEAPON) throw std::invalid_argument("Incorrect constructor for weapon");
}

Equipment::Equipment(int s)
{
    slot = WEAPON;
    speed = s;
}
