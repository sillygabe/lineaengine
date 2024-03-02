#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <SDL2_ttf/SDL_ttf.h>
#include "helper.hpp"

namespace linea::__private
{
    using __sdl_font = handle_t<TTF_Font, TTF_CloseFont>;
}

namespace linea::graphics
{
    class font_t
    {
    private:
        __private::__sdl_font fnt;
    public:
        void destroy();
        font_t(std::string path, uint32_t size)
            : fnt(std::move(
                TTF_OpenFont(path.c_str(), size)
            )) {}

        sdl_ptr render(std::string, color_t);
    };  
}

#endif