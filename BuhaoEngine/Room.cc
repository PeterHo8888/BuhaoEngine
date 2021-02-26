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
    for (GameObject *game_obj : game_objs)
        game_obj->update();
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
