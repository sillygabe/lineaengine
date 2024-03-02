#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include "helper.hpp"
#include <map>
#include <vector>

namespace linea::events
{   
    struct context_t
	{
		context_t(uint32_t type)
			: type(type), error(SDL_GetError()) {}
		uint32_t type;
		std::string error;
	};

    /// @brief Default function for listener_t
    static void LISTENER_DEFAULT(context_t)
    {return;}

    /// @brief Function container which gets executed on an assigned event
    struct listener_t
    {
        void (*func) (context_t);
        listener_t() : func(LISTENER_DEFAULT) {}
        listener_t(void (*f) (context_t)) : func(f) {}
        void operator()(context_t ctx) {func(ctx);}
    };      

    static std::vector<uint32_t> event_query;   
    static std::map<uint32_t, listener_t> listeners;

    void attach_listener(uint32_t, listener_t);
    void remove_listener(uint32_t);
    void throw_event(uint32_t);
    void update_events();
}   

#endif