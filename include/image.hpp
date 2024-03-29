#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include "rect.hpp"
#include "helper.hpp"
#include <utility>
#include <string>

namespace linea::__private
{
	using __sdl_texture = handle_t<SDL_Texture, SDL_DestroyTexture>;
}

namespace linea::graphics
{
	using size_2d_t = std::pair<int32_t, int32_t>;
		
	class image_t
	{
	private:
		linea::__private::__sdl_texture texture;
	public:
		image_t(SDL_Texture *tex)
			: texture(std::move(tex)) {}

		int32_t get_width();
		int32_t get_height();
		size_2d_t get_size();

		rect_t get_rect(void);
		rect_t get_rect(size_2d_t center);

		SDL_Texture *get_ptr();
	};
}

#endif
