#include "Room.h"
#include "GameObject.h"
#include <SDL2/SDL.h>

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

void Room::render(SDL_Renderer *renderer) const
{
    // TODO: Add layering system

    // background->render();

    for (const GameObject *game_obj : game_objs)
        game_obj->render(renderer);

    // hud->render();
}
