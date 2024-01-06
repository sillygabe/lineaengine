#include <SDL2/SDL_timer.h>
#include "include.hpp"
#pragma once

namespace time
{
    size_t curr_ticks;
    size_t delta_ms;
    flt64_t delta;
    size_t __buff;

    void __time_start()
    {
        curr_ticks = 0;
        delta = 0;
        delta_ms = 0;
    }

    void __time_update()
    {
        __buff = SDL_GetTicks64();
        delta_ms = curr_ticks - __buff;
        delta = (flt64_t) (delta_ms / 1000.0);

        curr_ticks = __buff;
    }

    flt64_t get_fps()
    {
        return (flt64_t) (1 / delta);
    }
}