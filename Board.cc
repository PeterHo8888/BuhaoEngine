#include "Board.h"
#include "Player.h"
#include "BuhaoEngine/Texture.h"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

static Texture *texture_o;
static Texture *texture_x;

Board::Board()
{
}

void Board::init()
{
    texture_o = new Texture(renderer, "/home/pho/Desktop/c.png");
    texture_x = new Texture(renderer, "/home/pho/Desktop/p.png");
}

void Board::add_player(int x, int y)
{
    static int turn = 0;

    Player *p;
    if (turn == 0)
        p = new Player(texture_o);
    else
        p = new Player(texture_x);

    int cell_x = x / p->get_width();
    int cell_y = y / p->get_height();
    p->set_pos(cell_x, cell_y);
    game_objs.push_back(p);

    turn = !turn;
}

void Board::update()
{
    Room::update();
}

void Board::process_input(SDL_Event *e)
{
    switch (e->type) {
    case SDL_MOUSEBUTTONUP:
        if (e->button.button == SDL_BUTTON_LEFT) {
            add_player(e->button.x, e->button.y);
        }
        break;
    default:
        break;
    }
}
