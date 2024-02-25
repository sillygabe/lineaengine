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

#endif
