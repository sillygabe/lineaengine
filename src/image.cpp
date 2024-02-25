#include "../include/image.hpp"
using namespace linea::graphics;

SDL_Texture *image_t::get_ptr()
{
    return this->texture.get();
}

uint32_t image_t::get_width()
{
    int32_t ret;
	SDL_QueryTexture(this->get_ptr(), NULL, NULL, &ret, NULL);
    return abs(ret);
}

uint32_t image_t::get_height()
{
    int32_t ret;
	SDL_QueryTexture(this->get_ptr(), NULL, NULL, NULL, &ret);
    return abs(ret);
}

linea::graphics::size_2d_t image_t::get_size()
{
    return {get_width(), get_height()};
}

linea::graphics::rect_t image_t::get_rect()
{
    rect_t ret {get_width(), get_height(), 0, 0};
    return ret;
}

linea::graphics::rect_t image_t::get_rect(size_2d_t center)
{
    rect_t ret {
        get_width(), 
        get_height(), 
        center.first - get_width() / 2, 
        center.second - get_height() / 2
    };
    return ret;
}