#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "image.hpp"
#include "font.hpp"
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
        void blit(sdl_ptr, rect_t rect);
        void blit(sdl_ptr, size_2d_t pos);

        image_t load(std::string path);
        image_t create_image(sdl_ptr);
        rect_t get_rect();

        void draw_rect(color_t color, rect_t rect);
    };
}

#endif