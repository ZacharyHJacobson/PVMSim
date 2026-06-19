#include "damagecalc.h"

int damage_calc::physicalMaxHit(
    int strength_level,     //includes temporary boosts/drains
    int prayer_multiplier,  //percent damage boost of prayer, ie 15% is 15
    int style_bonus,        //aggressive/controlled boost
    int void_multiplier,         //inverse of void bonus %, ie 12.5% is 8
    int strength_bonus     //from equipment
    )
{
    int effective_strength = (strength_level * (100 + prayer_multiplier))/100;
    effective_strength += style_bonus + 8;
    if(void_multiplier > 0) effective_strength += effective_strength/void_multiplier;
    float max_hit = 0.5 + ((effective_strength * (strength_bonus + 64))/640.0);
    return int(max_hit);
};
