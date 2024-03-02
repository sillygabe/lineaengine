#include "../include/font.hpp"
using namespace linea::graphics;

linea::sdl_ptr font_t::render(std::string text, color_t c)
{
    SDL_Color a = {c.r, c.g, c.b, c.a}, b = {0, 0, 0, 0};
    return TTF_RenderText
    (
        this->fnt.get(),
        text.c_str(),
        a,
        b
    );
}

void font_t::destroy()
{
    this->fnt.reset();
}