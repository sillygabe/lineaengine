#include "window.hpp"
#include "events.hpp"
#include "image.hpp"
#include "helper.hpp"
#include "image.hpp"
#include "font.hpp"

//Include them just in case!!
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

namespace linea::__private
{
    void init()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(
            IMG_INIT_AVIF | 
            IMG_INIT_JPG | 
            IMG_INIT_JXL | 
            IMG_INIT_PNG |
            IMG_INIT_TIF |
            IMG_INIT_WEBP
        );
        TTF_Init();
        Mix_Init(
            MIX_INIT_FLAC | 
            MIX_INIT_MID |
            MIX_INIT_MOD |
            MIX_INIT_MP3 |
            MIX_INIT_OGG | 
            MIX_INIT_OPUS
        );
    }

    void quit()
    {
        SDL_Quit(); TTF_Quit();
        IMG_Quit(); Mix_Quit();
    }
}