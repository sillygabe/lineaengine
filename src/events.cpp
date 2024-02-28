#include "../include/events.hpp"

void linea::events::add_listener(uint32_t t, func_t<void> f)
{
    listeners.emplace(t, f);
}

void linea::events::throw_event(uint32_t ty)
{
    linea::events::event_query.push_back(ty);
}

void linea::events::update(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
        event_query.push_back(event.type);

    for (auto ty : event_query)
        if (listeners.contains(ty)) 
            listeners[ty].func();

    event_query.clear();
}