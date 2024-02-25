#include "../include/rect.hpp"
using namespace linea::graphics;

void rect_t::__set_rect()
{
	__rect.w = this->w;
	__rect.h = this->h;
	__rect.x = this->x;
	__rect.y = this->y;
}

SDL_Rect *rect_t::get_ptr()
{	
	this->__set_rect();
	return &__rect;
}

bool rect_t::collides_with(rect_t &other)
{
	this->__set_rect();
	return SDL_HasIntersection(get_ptr(), other.get_ptr());
}
