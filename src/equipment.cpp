#include "equipment.h"
#include <fstream>
#include <json/json.h>

int Equipment::ApplyBane(int max_hit, Monster monster)
{
    return max_hit;
}

Equipment::Slot Equipment::GetSlot()
{
    return slot;
}

int Equipment::GetSpeed()
{
    return speed;
}

Equipment::Equipment(Slot s)
{
    if(s == WEAPON) throw std::invalid_argument("Incorrect constructor for weapon");
}

Equipment::Equipment(int s)
{
    slot = WEAPON;
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
                slot = (equipment_stats["isTwoHanded"].asBool()) ? TWOHAND : WEAPON;
                speed = equipment_stats["speed"].asInt();
            }
            else if (stats_slot == "head") slot = HEAD;
            else if (stats_slot == "cape") slot = BACK;
            else if (stats_slot == "neck") slot = NECK;
            else if (stats_slot == "ammo") slot = AMMUNITION;
            else if (stats_slot == "body") slot = BODY;
            else if (stats_slot == "shield") slot = SHIELD;
            else if (stats_slot == "legs") slot = LEGS;
            else if (stats_slot == "hands") slot = HANDS;
            else if (stats_slot == "feet") slot = FEET;
            else if (stats_slot == "ring") slot = FINGER;
            else throw std::invalid_argument("Invalid slot");
            stats[STAB_ACCURACY] = equipment_stats["offensive"]["stab"].asInt();
            stats[SLASH_ACCURACY] = equipment_stats["offensive"]["slash"].asInt();
            stats[CRUSH_ACCURACY] = equipment_stats["offensive"]["crush"].asInt();
            stats[MAGIC_ACCURACY] = equipment_stats["offensive"]["magic"].asInt();
            stats[STAB_DEFENCE] = equipment_stats["defensive"]["stab"].asInt();
            stats[SLASH_DEFENCE] = equipment_stats["defensive"]["slash"].asInt();
            stats[CRUSH_DEFENCE] = equipment_stats["defensive"]["crush"].asInt();
            stats[MAGIC_DEFENCE] = equipment_stats["defensive"]["magic"].asInt();
            stats[MELEE_STRENGTH] = equipment_stats["bonuses"]["str"].asInt();
            stats[RANGED_STRENGTH] = equipment_stats["bonuses"]["ranged_str"].asInt();
            stats[MAGIC_STRENGTH] = equipment_stats["bonuses"]["magic_str"].asInt();
            stats[MAGIC_STRENGTH] = equipment_stats["bonuses"]["prayer"].asInt();
            return;
        }
    }
    std::invalid_argument("Equipment not found");
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
