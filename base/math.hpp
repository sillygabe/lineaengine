#include "define.hpp"
#include <math.h>
#include <time.h>
#pragma once

namespace math
{
    flt64_t random()
    {
        srand(clock());
        return (flt64_t) (rand() / 32767.0);
    }   
}