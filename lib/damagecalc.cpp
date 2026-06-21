#include "damagecalc.h"

int damage_calc::physicalMaxHit(int strength_level, int prayer_multiplier, int style_bonus, int void_multiplier, int strength_bonus)
{
    int effective_strength = (strength_level * (100 + prayer_multiplier))/100;
    effective_strength += style_bonus + 8;
    if(void_multiplier > 0) effective_strength += effective_strength/void_multiplier;
    float max_hit = 0.5 + ((effective_strength * (strength_bonus + 64))/640.0);
    return int(max_hit);
};
