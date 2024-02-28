#include "../include/window.hpp"
using namespace linea::graphics;

window_t::window_t(std::string name, size_2d_t size) : win(
    std::move(
        SDL_CreateWindow(
            name.c_str(), 
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            size.first,
            size.second, 0
    ))), rend(std::move(SDL_CreateRenderer(win.get(), -1, 0))) {}

void window_t::update()
{
    SDL_RenderPresent(rend.get());
    SDL_RenderClear(rend.get());
}

void window_t::fill(color_t color)
{
    SDL_SetRenderDrawColor(rend.get(), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(rend.get(), NULL);
}

void window_t::blit(image_t &image, size_2d_t pos)
{
    rect_t r = image.get_rect();
    r.x = pos.first; r.y = pos.second;

    SDL_RenderCopy(rend.get(), image.get_ptr(), NULL, r.get_ptr());
}

void window_t::blit(image_t &image, rect_t r)
{
    SDL_RenderCopy(rend.get(), image.get_ptr(), NULL, r.get_ptr());
}

void window_t::blit(sdl_ptr pt, rect_t rect)
{
    image_t img = this->create_image(pt);
    this->blit(img, rect);
}

void window_t::blit(sdl_ptr pt, size_2d_t rect)
{
    image_t img = this->create_image(pt);
    this->blit(img, rect);
}


image_t window_t::load(std::string path)
{
    image_t ret = SDL_CreateTextureFromSurface(
        rend.get(),
        IMG_Load(path.c_str())
    );
    return ret;
}

image_t window_t::create_image(sdl_ptr pt)
{
    return SDL_CreateTextureFromSurface(this->rend.get(), pt);
}

rect_t window_t::get_rect()
{
    int32_t x, y;
    SDL_GetWindowSize(win.get(), &x, &y);
    return {x, y, 0, 0};
}

void window_t::draw_rect(color_t color, rect_t rect)
{
    SDL_SetRenderDrawColor(rend.get(), color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(rend.get(), rect.get_ptr());
}
