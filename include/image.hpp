#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include "rect.hpp"
#include "helper.hpp"
#include <utility>

namespace linea::__private
{
	using __sdl_texture = handle_t<SDL_Texture, SDL_DestroyTexture>;
}

namespace linea::graphics
{
	using size_2d_t = std::pair<uint32_t, uint32_t>;
		
	class image_t
	{
	private:
		linea::__private::__sdl_texture texture;
	public:
		image_t(SDL_Texture *tex)
			: texture(std::move(tex)) {}

		uint32_t get_width();
		uint32_t get_height();
		size_2d_t get_size();

		rect_t get_rect(void);
		rect_t get_rect(size_2d_t center);

		SDL_Texture *get_ptr();
	};
}

#endif
