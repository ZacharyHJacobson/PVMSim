#include "monster.h"
#include <fstream>

Json::Value Monster::root;

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

Monster::Monster(std::string name)
{
    Json::Value monster_root = GetRoot();

    Json::Value monster_stats;
    for(int x = 0; x < monster_root.size(); x++)
    {
        monster_stats = monster_root[x];
        if(monster_stats["name"].asString() == name)
        {
            combat_stats[cs_HITPOINTS] = monster_stats["skills"]["hp"].asInt();
            combat_stats[cs_ATTACK] = monster_stats["skills"]["atk"].asInt();
            combat_stats[cs_STRENGTH] = monster_stats["skills"]["str"].asInt();
            combat_stats[cs_DEFENCE] = monster_stats["skills"]["def"].asInt();
            combat_stats[cs_MAGIC] = monster_stats["skills"]["magic"].asInt();
            combat_stats[cs_RANGED] = monster_stats["skills"]["ranged"].asInt();

            aggressive_stats[as_ATTACK] = monster_stats["offensive"]["atk"].asInt();
            aggressive_stats[as_STRENGTH] = monster_stats["offensive"]["str"].asInt();
            aggressive_stats[as_MAGIC] = monster_stats["offensive"]["magic"].asInt();
            aggressive_stats[as_MAGIC_STRENGTH] = monster_stats["offensive"]["magic_str"].asInt();
            aggressive_stats[as_RANGED] = monster_stats["offensive"]["ranged"].asInt();
            aggressive_stats[as_RANGED_STRENGTH] = monster_stats["offensive"]["ranged_str"].asInt();

            defensive_stats[ds_STAB] = monster_stats["defensive"]["stab"].asInt();
            defensive_stats[ds_SLASH] = monster_stats["defensive"]["slash"].asInt();
            defensive_stats[ds_CRUSH] = monster_stats["defensive"]["crush"].asInt();
            defensive_stats[ds_MAGIC] = monster_stats["defensive"]["magic"].asInt();
            defensive_stats[ds_LIGHT] = monster_stats["defensive"]["light"].asInt();
            defensive_stats[ds_MEDIUM] = monster_stats["defensive"]["medium"].asInt();
            defensive_stats[ds_HEAVY] = monster_stats["defensive"]["heavy"].asInt();
            defensive_stats[ds_FLAT_ARMOUR] = monster_stats["defensive"]["flat_armour"].asInt();
            return;
        }
    }
    std::invalid_argument("Monster not found");
}

Json::Value Monster::GetRoot()
{
    if(root.size() < 1)
    {
        std::ifstream monster_json_file("monsters.json", std::ifstream::binary);
        monster_json_file >> root;
    }
    return root;
}
