#include "encounter.h"

Encounter::Encounter()
{
    bane = BANELESS;
    bane_resistance = 0;
}

Encounter::Encounter(Bane b, float br)
{
    if(b == BANELESS) throw std::invalid_argument("Bane Resistance requires a Bane");
    bane = b;
    bane_resistance = br;
}
