#include "DamageRule.h"

int SimpleDamageRule::CalculateDamage(bool correct)
{
    if (correct)
    {
        return 10;
    }

    return 0;
}