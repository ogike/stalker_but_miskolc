#pragma once

#include <stdlib.h>

bool ChanceCalc(int percentage)
{
    int roll = rand() % 100 + 1;
    if(roll <= percentage)
    {
        return true;
    }
    return false;
}