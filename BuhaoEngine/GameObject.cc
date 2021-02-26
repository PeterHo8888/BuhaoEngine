#include "GameObject.h"

#include <SDL2/SDL.h>

void GameObject::update()
{
    x += vx;
    y += vy;
    vy += gravity;
}
