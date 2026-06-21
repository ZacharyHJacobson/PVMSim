#pragma once

namespace damage_calc
{
    const int burst_of_strength_damage = 5;
    const int superhuman_strength_damage = 10;
    const int ultimate_strength_damage = 15;
    const int chivalry_damage = 18;
    const int piety_damage = 23;

    const int sharp_eye_damage = 5;
    const int hawk_eye_damage = 10;
    const int eagle_eye_damage = 15;
    const int deadeye_damage = 18;
    const int rigour_damage = 23;

    const int mystic_will_damage = 0;
    const int mystic_lore_damage = 1;
    const int mystic_might_damage = 2;
    const int mystic_vigour_damage = 3;
    const int augury_damage = 4;

    const int aggressive_strength_bonus = 3;
    const int accurate_melee_strength_bonus = 0;
    const int defensive_strength_bonus = 0;
    const int controlled_strength_bonus = 1;
    const int accurate_ranged_strength_bonus = 3;
    const int rapid_strength_bonus = 0;
    const int longrange_strength_bonus = 0;

    const int no_void = 0;
    const int melee_normal_void_damage = 10;
    const int melee_elite_void_damage = 10;
    const int ranged_normal_void_damage = 10;
    const int ranged_elite_void_damage = 8;
    const int mage_normal_void_damage = 0;
    const int mage_elite_void_damage = 20;

    int physicalMaxHit(
        int strength_level,     //includes temporary boosts/drains
        int prayer_multiplier,  //percent damage boost of prayer, ie 15% is 15
        int style_bonus,        //aggressive/controlled boost
        int void_multiplier,    //inverse of void bonus %, ie 12.5% is 8
        int strength_bonus      //from equipment
    );
}