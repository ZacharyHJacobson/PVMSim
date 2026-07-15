#pragma once

#include "monster.h"
#include "json/json.h"

class Equipment {
    public:
        enum EquipmentSlot {
            eslot_HEAD = 0,
            eslot_BACK,
            eslot_NECK,
            eslot_AMMUNITION,
            eslot_WEAPON,
            eslot_TWOHAND,
            eslot_BODY,
            eslot_SHIELD,
            eslot_LEGS,
            eslot_HANDS,
            eslot_FEET,
            eslot_FINGER,
            eslot_COUNT     //not a slot
        };
        enum EquipmentStat {
            estat_STAB_ACCURACY = 0,
            estat_SLASH_ACCURACY,
            estat_CRUSH_ACCURACY,
            estat_MAGIC_ACCURACY,
            estat_STAB_DEFENCE,
            estat_SLASH_DEFENCE,
            estat_CRUSH_DEFENCE,
            estat_MAGIC_DEFENCE,
            estat_MELEE_STRENGTH,
            estat_RANGED_STRENGTH,
            estat_MAGIC_STRENGTH,
            estat_PRAYER_BONUS,    //1.5% = 15, 2% = 20
            estat_COUNT     //not a stat
        };
        int stats[estat_COUNT];
        int ApplyBane(int max_hit, Monster monster);
        EquipmentSlot GetSlot();
        int GetSpeed();
        Equipment(EquipmentSlot s);           //non-weapon constructor
        Equipment(int s);            //weapon constructor
        Equipment(std::string name); //load from equipment.json
        Equipment();
    private:
        EquipmentSlot slot;
        int speed;              //in ticks
        static Json::Value root;
        Json::Value GetRoot();
};