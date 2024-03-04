#include "../include/events.hpp"

void linea::events::attach_listener(uint32_t eve, listener_t lst)
{
    listeners.insert({eve, lst});
}   

void linea::events::remove_listener(uint32_t eve)
{
    listeners.erase(eve);
}

void linea::events::throw_event(uint32_t eve)
{
    event_query.push_back(eve);
}

void linea::events::update_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) 
        event_query.push_back(event.type);

    for (context_t ctx : event_query)
        listeners[ctx.type](ctx);

    event_query.clear();
}

bool linea::events::get_key_state(uint8_t key)
{
    return keyboard[SDL_GetScancodeFromKey(key)];
}