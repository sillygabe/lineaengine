#include <SDL2/SDL.h>
#include "../scrap/pair.hpp"
#pragma once

namespace video
{
    class texture
    {
    private:
        SDL_Texture *tex = nullptr; 
    public:
        texture(SDL_Texture *other)
        {
            this->tex = other;
        }

        data::pair<int32_t, int32_t>
        get_size()
        {
            data::pair<int32_t, int32_t> ret;
            SDL_QueryTexture(tex, NULL, NULL, &ret.first, &ret.second);
            return ret;
        }

        friend class window;
    };
}