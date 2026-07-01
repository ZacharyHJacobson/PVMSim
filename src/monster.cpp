#include "monster.h"

Monster::Monster(Bane b, float br, ElementalWeakness e, int wm)
{
    if(b == BANELESS && br != 0) throw std::invalid_argument("Bane Resistance requires a Bane");
    if(e == NO_WEAKNESS && wm != 0) throw std::invalid_argument("Weakness Magnitude requires a Weakness");
    if(e != NO_WEAKNESS && wm == 0) throw std::invalid_argument("Weakness requires a Weakness Magnitude");
    bane = b;
    bane_resistance = br;
    elemental_weakness = e;
    weakness_magnitude = wm;
}
