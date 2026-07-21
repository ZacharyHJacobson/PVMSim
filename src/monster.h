#pragma once

#include "json/json.h"
#include <stdexcept>

class Monster {
    public:
        enum Bane {
            bane_NONE = 0,
            bane_DRAGON,
            bane_DEMON,
            bane_RAT,
            bane_UNDEAD,
            bane_VAMPYRE,
            bane_GOLEM,
            bane_LEAF,
            bane_KALPHITE,
            bane_CORP,
            bane_HATCHED_ARAXYTE,
            bane_XERIC,
            bane_AMASCUT
        };
        Bane bane;
        enum ElementalWeakness {
            ew_NONE = 0,
            ew_AIR,
            ew_WATER,
            ew_EARTH,
            ew_FIRE
        };
        ElementalWeakness elemental_weakness;
        int weakness_magnitude;
        enum CombatStat {
            cs_HITPOINTS = 0,
            cs_ATTACK,
            cs_STRENGTH,
            cs_DEFENCE,
            cs_MAGIC,
            cs_RANGED,
            cs_COUNT     //not a stat
        };
        int combat_stats[cs_COUNT];
        enum AggressiveStat {
            as_ATTACK = 0,
            as_STRENGTH,
            as_MAGIC,
            as_MAGIC_STRENGTH,
            as_RANGED,
            as_RANGED_STRENGTH,
            as_COUNT     //not a stat
        };
        int aggressive_stats[as_COUNT];
        enum DefensiveStat {
            ds_STAB = 0,
            ds_SLASH,
            ds_CRUSH,
            ds_MAGIC,
            ds_LIGHT,
            ds_MEDIUM,
            ds_HEAVY,
            ds_FLAT_ARMOUR,
            ds_COUNT       //not a stat
        };
        int defensive_stats[ds_COUNT];
        enum Immunity {
            i_VENOM = 0,           //converts to poison if immune
            i_POISON,
            i_CANNON,
            i_THRALL,
            i_COUNT    //not a stat
        };
        bool immunities[i_COUNT];
        enum Resistance {
            r_BANE = 0,
            r_VENOM,
            r_POISON,
            r_COUNT    //not a stat
        };
        float resistances[r_COUNT];
        bool wilderness = false;
        bool on_task = true;
        Monster(Bane b = bane_NONE, float br = 0.0, ElementalWeakness e = ew_NONE, int wm = 0);
        Monster(std::string name); //load from monsters.json
    private:
        static Json::Value root;
        Json::Value GetRoot();
};