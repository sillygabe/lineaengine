#ifndef __RECT_HPP__
#define __RECT_HPP__

#include <SDL2/SDL.h>

namespace linea::graphics
{
	class rect_t
	{
	private:
		SDL_Rect __rect;
		void __set_rect();
	public:
		int32_t w = 0, h = 0, x = 0, y = 0;
		
		rect_t(int32_t w1, int32_t h1, int32_t x1, int32_t y1)
			: w(w1), h(h1), x(x1), y(y1) {}

		SDL_Rect *get_ptr();
		bool collides_with(rect_t &other);
	};
}

#endif
