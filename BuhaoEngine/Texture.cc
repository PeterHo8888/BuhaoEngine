#include "Texture.h"
#include "App.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

Texture::Texture(const char filename[])
{
    SDL_Renderer *renderer = App::get_renderer();
    texture = IMG_LoadTexture(renderer, filename);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    cout << "Initialized texture " << filename << " " << rect.w << " " << rect.h << endl;
}

void Texture::blit(int x, int y)
{
    SDL_Renderer *renderer = App::get_renderer();
    rect.x = x;
    rect.y = y;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
