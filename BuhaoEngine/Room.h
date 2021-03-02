#pragma once

#include <vector>
union SDL_Event;
class GameObject;
class App;

#ifdef __LINUX__
#define yeet throw
#else
#define yeet (void *)
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
