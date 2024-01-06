#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "../scrap/pair.hpp"
#pragma once

namespace video
{
    class surface
    {
    private:
        SDL_Surface *surf = nullptr;
    public:
        surface(SDL_Surface *s) : surf(s) {}

        surface(data::pair<int32_t, int32_t> size)
        {
            this->surf = SDL_CreateRGBSurface
            (
                0,
                size.first,
                size.second,
                64,
                0,
                0,
                0,
                0
            );
        }
        
        data::pair<int32_t, int32_t> 
        get_size()
        {
            return data::pair(surf->w, surf->h);
        }

        SDL_Surface * get_sdl_surface()
        {
            return this->surf;
        }

        friend void load_surface(surface&, const char *);
        friend class window;
    };

    surface load_surface(const char * path)
    {
        return surface(IMG_Load(path));
    }

    void load_surface(surface &to_load, const char * path)
    {
        to_load = load_surface(path);
    }
}