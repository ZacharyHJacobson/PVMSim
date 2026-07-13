#include "monster.h"

Monster::Monster(Bane b, float br, ElementalWeakness e, int wm)
{
    if(b == bane_NONE && br != 0) throw std::invalid_argument("Bane Resistance requires a Bane");
    if(e == ew_NONE && wm != 0) throw std::invalid_argument("Weakness Magnitude requires a Weakness");
    if(e != ew_NONE && wm == 0) throw std::invalid_argument("Weakness requires a Weakness Magnitude");
    bane = b;
    resistances[r_BANE] = br;
    elemental_weakness = e;
    weakness_magnitude = wm;
}
