#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "image.hpp"
#include <SDL2_image/SDL_image.h>

namespace linea::__private
{
	using __sdl_window = handle_t<SDL_Window, SDL_DestroyWindow>;
    using __sdl_renderer = handle_t<SDL_Renderer, SDL_DestroyRenderer>;
}

namespace linea::graphics
{
    class window_t
    {
    private:
        __private::__sdl_window win;
        __private::__sdl_renderer rend;
    public:
        window_t(std::string, size_2d_t);

        void update();
        void fill(color_t color);
        void blit(image_t &image, size_2d_t pos);
        void blit(image_t &image, rect_t rect);
        image_t load(std::string path);
        rect_t get_rect();
    };
}

#endif