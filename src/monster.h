#pragma once

#include <stdexcept>

class Monster {
    public:
        enum Bane {
            BANELESS,
            DRAGON,
            DEMON,
            RAT,
            UNDEAD,
            VAMPYRE,
            GOLEM,
            LEAF,
            KALPHITE,
            CORP,
            ARAXYTE,
            XERIC,
            AMASCUT
        };
        Bane bane;
        float bane_resistance;
        enum ElementalWeakness {
            NO_WEAKNESS,
            AIR,
            WATER,
            EARTH,
            FIRE
        };
        ElementalWeakness elemental_weakness;
        int weakness_magnitude;
        int armour;
        bool wilderness = false;
        bool on_task = true;
        Monster(Bane b = BANELESS, float br = 0.0, ElementalWeakness e = NO_WEAKNESS, int wm = 0);
};