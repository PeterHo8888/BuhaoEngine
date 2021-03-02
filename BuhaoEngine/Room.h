#pragma once

#include <vector>
struct GameObject;
union SDL_Event;
struct App;

#ifdef __SWITCH__
#define yeet (void*)
#else
#define yeet throw
#endif

class Room {
private:
public:
    std::vector<GameObject*> game_objs;
    App *app;
public:
    Room(App *app);
    void render() const;

    void add_gameobj(GameObject *obj)
    {
        if (!obj)
            yeet "NullPointerException";
        game_objs.push_back(obj);
    }
public:
    virtual void update();
    virtual void process_input(SDL_Event *);
    virtual void init();
};
