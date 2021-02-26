#pragma once

#include <vector>
struct SDL_Renderer;
struct GameObject;
union SDL_Event;

class Room {
private:
public:
    std::vector<GameObject*> game_objs;
    SDL_Renderer *renderer;
public:
    Room();
    void render(SDL_Renderer *) const;

    void set_renderer(SDL_Renderer *renderer)
    {
        this->renderer = renderer;
    }

    void add_gameobj(GameObject *obj)
    {
        if (!obj)
            throw "NullPointerException";
        game_objs.push_back(obj);
    }
public:
    virtual void update();
    virtual void process_input(SDL_Event *);
    virtual void init();
};
