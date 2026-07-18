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
