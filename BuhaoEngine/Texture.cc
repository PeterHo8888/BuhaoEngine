#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

Texture::Texture(SDL_Renderer *renderer, const char filename[]) : renderer(renderer)
{
    texture = IMG_LoadTexture(renderer, filename);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    cout << "Initialized texture " << filename << " " << rect.w << " " << rect.h << endl;
}

void Texture::blit(int x, int y)
{
    rect.x = x;
    rect.y = y;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
