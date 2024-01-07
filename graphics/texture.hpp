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

        data::texture_size get_size()
        {
            data::texture_size ret;
            SDL_QueryTexture(tex, NULL, NULL, &ret.first, &ret.second);
            return ret;
        }

        friend class window;
    };
}