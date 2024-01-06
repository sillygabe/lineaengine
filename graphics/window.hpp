#include <SDL2/SDL.h>
#include "surface.hpp"
#include "../scrap/pair.hpp"
#include "texture.hpp"
#pragma once

namespace video
{
    class window
    {
    private:
        SDL_Window * win = nullptr;
        SDL_Renderer * rend = nullptr;
    public:
        window
        (
            const char * name,
            data::texture_size size,
            data::pair<uint32_t, uint32_t> window_pos = data::pair
            (SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED)
        )
        {
            this->win = SDL_CreateWindow
            (
                name,
                window_pos.first,
                window_pos.second,
                size.first,
                size.second,
                0
            );
            this->rend = SDL_CreateRenderer
            (
                this->win,
                -1,
                SDL_RENDERER_ACCELERATED
            );
        }   

        surface get_surface()
        {
            return SDL_GetWindowSurface(win);
        }

        //It does what it says :)
        texture create_texture_from_surface(
            surface from
        )
        {
            texture ret = SDL_CreateTextureFromSurface
            (
                this->rend,
                from.get_sdl_surface()
            );
            return ret;
        }

        texture create_texture
        (
            data::texture_size size
        )
        {
            texture ret = SDL_CreateTexture
            (
                this->rend,
                SDL_PixelFormatEnum::SDL_PIXELFORMAT_ARGB32,
                SDL_TextureAccess::SDL_TEXTUREACCESS_STATIC,
                size.first,
                size.second
            );
            return ret;
        }
    };
}