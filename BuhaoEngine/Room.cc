#include "Room.h"
#include "GameObject.h"

using namespace std;

Room::Room()
{
}

void Room::init()
{
    // Stub, user-defined derived room logic
}

void Room::process_input(SDL_Event *)
{
    // Stub, user-defined derived room logic
}

void Room::update()
{
    for (GameObject *game_obj : game_objs) {
        /*
         * THIS IS FORBIDDEN BY ISO C++ [-fpermissive]
         *
         * Call derived (read: user's) update()
         * ONLY if it's been overridden.
         *
         * Do NOT call if not overriden, or else
         * GameObject::update() will be called twice.
         */
        if (&game_obj->update != &game_obj->GameObject::update)
            game_obj->update();

        // Call base update() for things like velocity and gravity
        game_obj->GameObject::update();
    }
}

void Room::render() const
{
    // TODO: Add layering system

    // background->render();

    for (const GameObject *game_obj : game_objs)
        if (game_obj->is_visible())
            game_obj->render();

    // hud->render();
}
