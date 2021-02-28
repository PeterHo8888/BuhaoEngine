#include "Draw.h"
#include "App.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

void Draw::draw_line(int x1, int y1, int x2, int y2, int t, int r, int g, int b, int a)
{
    SDL_Renderer *renderer = App::get_renderer();
    thickLineRGBA(renderer, x1, y1, x2, y2, t, r, g, b, a);
    //SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Draw::get_scale(float *x, float *y)
{
    SDL_Renderer *renderer = App::get_renderer();
    SDL_RenderGetScale(renderer, x, y);
}

void Draw::set_scale(float x, float y)
{
    SDL_Renderer *renderer = App::get_renderer();
    SDL_RenderSetScale(renderer, x, y);
}
