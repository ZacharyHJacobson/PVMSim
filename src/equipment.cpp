#include "equipment.h"
#include <fstream>

Json::Value Equipment::root;

int Equipment::ApplyBane(int max_hit, Monster monster)
{
    return max_hit;
}

Equipment::EquipmentSlot Equipment::GetSlot()
{
    return slot;
}

int Equipment::GetSpeed()
{
    return speed;
}

Equipment::Equipment(EquipmentSlot s)
{
    if(s == eslot_WEAPON) throw std::invalid_argument("Incorrect constructor for weapon");
}

Equipment::Equipment(int s)
{
    slot = eslot_WEAPON;
    speed = s;
}

Equipment::Equipment(std::string name)
{
    Json::Value equipment_root = GetRoot();

    Json::Value equipment_stats;
    for(int x = 0; x < equipment_root.size(); x++)
    {
        equipment_stats = equipment_root[x];
        if(equipment_stats["name"].asString() == name)
        {
            std::string stats_slot = equipment_stats["slot"].asString();
            if(stats_slot == "weapon")
            {
                if(equipment_stats["speed"].asInt() < 1) throw std::invalid_argument("Weapon speed must be positive");
                slot = (equipment_stats["isTwoHanded"].asBool()) ? eslot_TWOHAND : eslot_WEAPON;
                speed = equipment_stats["speed"].asInt();
            }
            else if (stats_slot == "head") slot = eslot_HEAD;
            else if (stats_slot == "cape") slot = eslot_BACK;
            else if (stats_slot == "neck") slot = eslot_NECK;
            else if (stats_slot == "ammo") slot = eslot_AMMUNITION;
            else if (stats_slot == "body") slot = eslot_BODY;
            else if (stats_slot == "shield") slot = eslot_SHIELD;
            else if (stats_slot == "legs") slot = eslot_LEGS;
            else if (stats_slot == "hands") slot = eslot_HANDS;
            else if (stats_slot == "feet") slot = eslot_FEET;
            else if (stats_slot == "ring") slot = eslot_FINGER;
            else throw std::invalid_argument("Invalid slot");
            stats[estat_STAB_ACCURACY] = equipment_stats["offensive"]["stab"].asInt();
            stats[estat_SLASH_ACCURACY] = equipment_stats["offensive"]["slash"].asInt();
            stats[estat_CRUSH_ACCURACY] = equipment_stats["offensive"]["crush"].asInt();
            stats[estat_MAGIC_ACCURACY] = equipment_stats["offensive"]["magic"].asInt();
            stats[estat_STAB_DEFENCE] = equipment_stats["defensive"]["stab"].asInt();
            stats[estat_SLASH_DEFENCE] = equipment_stats["defensive"]["slash"].asInt();
            stats[estat_CRUSH_DEFENCE] = equipment_stats["defensive"]["crush"].asInt();
            stats[estat_MAGIC_DEFENCE] = equipment_stats["defensive"]["magic"].asInt();
            stats[estat_MELEE_STRENGTH] = equipment_stats["bonuses"]["str"].asInt();
            stats[estat_RANGED_STRENGTH] = equipment_stats["bonuses"]["ranged_str"].asInt();
            stats[estat_MAGIC_STRENGTH] = equipment_stats["bonuses"]["magic_str"].asInt();
            stats[estat_MAGIC_STRENGTH] = equipment_stats["bonuses"]["prayer"].asInt();
            return;
        }
    }
    std::invalid_argument("Equipment not found");
}

Equipment::Equipment()
{
    for(int statNum : stats)
    {
        std::fill(stats, stats+estat_COUNT, 0);
    }
}

Json::Value Equipment::GetRoot()
{
    if(root.size() < 1)
    {
        std::ifstream equipment_json_file("equipment.json", std::ifstream::binary);
        equipment_json_file >> root;
    }
    return root;
}
