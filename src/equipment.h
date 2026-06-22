#pragma once

#include "encounter.h"

class Equipment {
    public:
        enum Slot {
            HEAD,
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
            FINGER
        };
        int stab_accuracy = 0;
        int slash_accuracy = 0;
        int crush_accuracy = 0;
        int magic_accuracy = 0;
        int stab_defence = 0;
        int slash_defence = 0;
        int crush_defence = 0;
        int magic_defence = 0;
        int melee_strength = 0;
        int ranged_strength = 0;
        int magic_strength = 0;     //1.5% = 15, 2% = 20
        int prayer_bonus;
        int ApplyBane(int max_hit, Encounter encounter);
        Slot GetSlot();
        int GetSpeed();
        Equipment(Slot s);    //non-weapon constructor
        Equipment(int s);    //weapon constructor
    private:
        Slot slot;
        int speed;              //in ticks
};