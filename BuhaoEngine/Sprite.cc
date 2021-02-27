#include "Sprite.h"
#include <SDL2/SDL.h>

Sprite::Sprite(const char filename[]) : framerate(0.0), cur_frame(0)
{
    add_frame(filename);
}

void Sprite::add_frame(const char filename[])
{
    t.push_back(new Texture(filename));
}

void Sprite::render(int x, int y)
{
    t[cur_frame]->blit(x, y);
}
