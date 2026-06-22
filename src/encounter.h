#pragma once

#include <stdexcept>

class Encounter {
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
        bool wilderness = false;
        bool on_task = true;
        Encounter();                    //non-bane constructor
        Encounter(Bane b, float br);    //bane constructor
};