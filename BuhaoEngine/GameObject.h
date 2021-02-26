#pragma once

struct SDL_Renderer;

class GameObject {
public:
    virtual void update() = 0;
    virtual void render(SDL_Renderer *) const = 0;
};
