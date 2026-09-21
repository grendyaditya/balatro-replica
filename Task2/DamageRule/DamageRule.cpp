#include "DamageRule.h"

int SimpleDamageRule::CalculateDamage(bool correct)
{
    if (correct)
    {
        return 25;
    }

    return 0;
}