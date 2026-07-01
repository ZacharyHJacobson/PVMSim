#pragma once

#include "monster.h"

class Equipment {
    public:
        enum Slot {
            HEAD = 0,
            BACK,
            NECK,
            AMMUNITION,
            WEAPON,
            TWOHAND,
            BODY,
            SHIELD,
            LEGS,
            HANDS,
            FEET,
            FINGER,
            SLOTS_COUNT     //not a slot
        };
        enum Stat {
            STAB_ACCURACY = 0,
            SLASH_ACCURACY,
            CRUSH_ACCURACY,
            MAGIC_ACCURACY,
            STAB_DEFENCE,
            SLASH_DEFENCE,
            CRUSH_DEFENCE,
            MAGIC_DEFENCE,
            MELEE_STRENGTH,
            RANGED_STRENGTH,
            MAGIC_STRENGTH,
            PRAYER_BONUS,    //1.5% = 15, 2% = 20
            STATS_COUNT     //not a stat
        };
        int stats[STATS_COUNT];
        int ApplyBane(int max_hit, Monster monster);
        Slot GetSlot();
        int GetSpeed();
        Equipment(Slot s);           //non-weapon constructor
        Equipment(int s);            //weapon constructor
        Equipment(std::string name); //load from equipment.json
    private:
        Slot slot;
        int speed;              //in ticks
        static Json::Value root;
        Json::Value GetRoot();
};