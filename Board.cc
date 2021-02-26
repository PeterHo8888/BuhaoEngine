#include "Board.h"
#include "Player.h"
#include "BuhaoEngine/Texture.h"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

static Texture *texture_o;
static Texture *texture_x;

static char board[9];

static char check_win()
{
    return ((board[0] && board[0] == board[1] && board[1] == board[2])) |
        ((board[3] && board[3] == board[4] && board[4] == board[5]) << 1) |
        ((board[6] && board[6] == board[7] && board[7] == board[8]) << 2) |
        ((board[0] && board[0] == board[3] && board[3] == board[6]) << 3) |
        ((board[1] && board[1] == board[4] && board[4] == board[7]) << 4) |
        ((board[2] && board[2] == board[5] && board[5] == board[8]) << 5) |
        ((board[0] && board[0] == board[4] && board[4] == board[8]) << 6) |
        ((board[2] && board[2] == board[4] && board[4] == board[6]) << 7);
}

Board::Board()
{
}

void Board::init()
{
    texture_o = new Texture("tic-tac-toe/images/o.png");
    texture_x = new Texture("tic-tac-toe/images/x.png");
}

void Board::add_player(int x, int y)
{
    static int turn = 0;

    Player *p;
    if (turn == 0)
        p = new Player(texture_x);
    else
        p = new Player(texture_o);

    int cell_x = x / p->get_width();
    int cell_y = y / p->get_height();

    if (board[cell_y * 3 + cell_x] == 0) {
        p->set_pos(cell_x, cell_y);
        game_objs.push_back(p);
        turn = !turn;
        board[cell_y * 3 + cell_x] = (turn == 0) ? 'x' : 'o';
    }

    char winners = check_win();
    for (int i = 0; i < 8; ++i) {
        if (winners & (1 << i)) {
            printf("Winner\n");
            fflush(stdout);
        }
    }
}

void Board::update()
{
    Room::update();
}

void Board::process_input(SDL_Event *e)
{
    switch (e->type) {
    case SDL_FINGERUP:
        add_player(e->tfinger.x * 600, e->tfinger.y * 600);
        break;
    case SDL_MOUSEBUTTONUP:
        if (e->button.button == SDL_BUTTON_LEFT)
            add_player(e->button.x, e->button.y);
        break;
    default:
        break;
    }
}
