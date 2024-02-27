#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include "helper.hpp"

namespace linea::events
{
    /*
    static std::vector<uint32_t> event_query;
    static SDL_Event event;

    struct context_t
    {
        uint32_t event_type;
        const char *error;

        void throw_err() {throw std::runtime_error(error);}
    };

    void update_events();
    void throw_event(uint32_t event_type);
    */
   
    bool get_key_pressed(char symbol);
    std::pair<int, int> get_mouse_pos();
}

#endif