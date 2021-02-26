#include "Sprite.h"
#include <SDL2/SDL.h>

Sprite::Sprite(const char filename[])
{
    t = new Texture(filename);
}

void Sprite::render(int x, int y)
{
    t->blit(x, y);
}
