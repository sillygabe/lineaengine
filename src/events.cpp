#include "../include/events.hpp"

void linea::events::add_listener(uint32_t t, func_t<void> f)
{
    listeners.emplace(t, f);
}

void linea::events::update(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        uint32_t ty = event.type;

        if (listeners.contains(ty)) 
            listeners[ty].func();
    }
}