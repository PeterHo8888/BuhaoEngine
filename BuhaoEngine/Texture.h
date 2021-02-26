#pragma once

#include <SDL2/SDL.h>

class Texture {
private:
    SDL_Texture *texture;
    SDL_Rect rect;
    SDL_Renderer *renderer;
public:
    Texture(SDL_Renderer *renderer, const char filename[]);
    void blit(int x, int y);
    int get_width()
    {
        return rect.w;
    }
    int get_height()
    {
        return rect.h;
    }
};
