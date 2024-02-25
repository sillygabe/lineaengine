#ifndef __HELPER_HPP__
#define __HELPER_HPP__

#include <memory>
#include <stdexcept>

namespace linea::__private
{
	template<typename T, void(*destroy)(T*), typename Ptr = std::unique_ptr<T, decltype(destroy)>>
	struct handle_t : public Ptr
	{
  		handle_t(T*&& p) : Ptr{p, destroy} {}
	};	
}

namespace linea
{
	struct color_t
	{
		uint8_t r = 0, g = 0, b = 0, a = 255;
	};
}

#endif
