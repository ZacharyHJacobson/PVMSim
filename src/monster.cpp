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

            if(monster_stats["attributes"].findString("draconic")) bane = bane_DRAGON;
            if(monster_stats["attributes"].findString("demon")) bane = bane_DEMON;
            if(monster_stats["attributes"].findString("rat")) bane = bane_RAT;
            if(monster_stats["attributes"].findString("undead")) bane = bane_UNDEAD;
            if((monster_stats["attributes"].findString("vampyre1"))||(monster_stats["attributes"].findString("vampyre2"))||(monster_stats["attributes"].findString("vampyre3"))) bane = bane_VAMPYRE;
            if(monster_stats["attributes"].findString("golem")) bane = bane_GOLEM;
            if(monster_stats["attributes"].findString("leafy")) bane = bane_LEAF;
            if(monster_stats["attributes"].findString("kalphite")) bane = bane_KALPHITE;
            if(name == "Corporeal Beast") bane = bane_CORP;
            if((name == "Mirrorback Araxyte")||(name == "Ruptura Araxyte")||(name == "Acidic Araxyte")) bane = bane_HATCHED_ARAXYTE;
            if(monster_stats["attributes"].findString("xerician")) bane = bane_XERIC;
            if((name == "Baboon Brawler")||(name == "Baboon Mage")||(name == "Baboon Shaman")||(name == "Baboon Thrall")||(name == "Baboon Thrower")||(name == "Cursed Baboon")||(name == "Volatile Baboon")||
                (name == "Ba-Ba")||(name == "Baboon")||(name == "Boulder")||
                (name == "Sacarab (Tombs of Amascut)")||
                (name == "Kephri")||(name == "Egg (Tombs of Amascut)")||(name == "Agile Scarab")||(name == "Arcane Scarab")||(name == "Scarab Swarm (Tombs of Amascut)")||(name == "Soldier Scarab")||(name == "Spitting Scarab")||
                (name == "Akkha")||(name == "Akkha's Shadow")||
                (name == "Crocodile (Tombs of Amascut)")||
                (name == "Zebak")||(name == "Blood Cloud")||
                (name == "Obelisk (Tombs of Amascut)")||(name == "Tumeken's Warden")||(name == "Elidinis' Warden")) bane = bane_AMASCUT;
            
            if(monster_stats["weakness"])
            {
                if(monster_stats["weakness"]["element"].asString() == "water") elemental_weakness = ew_WATER;
                else if(monster_stats["weakness"]["element"].asString() == "fire") elemental_weakness = ew_FIRE;
                else if(monster_stats["weakness"]["element"].asString() == "air") elemental_weakness = ew_AIR;
                else if(monster_stats["weakness"]["element"].asString() == "earth") elemental_weakness = ew_EARTH;
            }
            weakness_magnitude = monster_stats["weakness"]["severity"].asInt();

            if(monster_stats["immunities"]["burn"]) immunities[i_BURN] = true;  //no other immunities, resistances, or wilderness location are present in monsters.json, must be assigned manually

            if (monster_stats["is_slayer_monster"].asBool()) on_task = true;
            
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
