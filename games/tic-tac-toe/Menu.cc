#include "Menu.h"
#include "Board.h"
#include <BuhaoEngine/App.h>

#include <SDL2/SDL.h>

static Board *board = nullptr;
void Menu::init()
{
    if (!board)
        board = new Board(app);
    app->add_room("Board", board);
}

void Menu::update()
{
}

void Menu::process_input(SDL_Event *e)
{
    switch (e->type) {
    case SDL_FINGERUP:
        app->change_room("Board");
        break;
    case SDL_MOUSEBUTTONUP:
        if (e->button.button == SDL_BUTTON_LEFT)
            app->change_room("Board");
        break;
    default:
        break;
    }
}
