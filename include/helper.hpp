#ifndef __HELPER_HPP__
#define __HELPER_HPP__

#include <memory>
#include <stdexcept>
#include <SDL2/SDL.h>

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

	template <typename Ret, typename ...Args>
	struct func_t
	{
		Ret (*func) (Args...);
		func_t(Ret (*f) (Args...)) : func(f) {}
		func_t() : func(nullptr) {}
		Ret operator()(Args... args)
		{this->func(args...);}
	};

	struct context_t
	{
		context_t(uint32_t type)
			: type(type), error(SDL_GetError()) {}
		uint32_t type;
		std::string error;
	};
}

#endif
