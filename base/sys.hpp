#include <SDL2/SDL_video.h>
#include <stdlib.h>
#include "define.hpp"
#pragma once

//System data
namespace sys
{
    size_t screen_width;
    size_t screen_height;
    size_t refresh_rate;

    void __init_sys()
    {
        SDL_DisplayMode dm;
        SDL_GetDesktopDisplayMode(0, &dm);
        
        screen_width = dm.w;
        screen_height = dm.h;
        refresh_rate = dm.refresh_rate;
    }
} 
