#include "../include/events.hpp"

bool linea::events::get_key_pressed(char symbol)
{
    static auto keys = SDL_GetKeyboardState(NULL);
    return keys[SDL_GetScancodeFromKey(symbol)];
}

std::pair<int, int> linea::events::get_mouse_pos()
{
    std::pair<int, int> ret;
    SDL_GetMouseState(&ret.first, &ret.second);
    return ret;
}

/*
void throw_event(uint32_t event_type)
{
    event_query.push_back(event_type);
}

void update_events()
{

}
*/