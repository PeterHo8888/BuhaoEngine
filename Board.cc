#include "Board.h"
#include "Player.h"
#include "BuhaoEngine/Sprite.h"
#include "BuhaoEngine/Sound.h"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

static Sprite *sprite_o;
static Sprite *sprite_x;

static char board[9];
static bool game_over;
static bool reset_on_click;

static Sound *sound_x;
static Sound *sound_o;
static Sound *sound_win;
static Sound *sound_lose;
static Sound *sound_draw;

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

void Board::init()
{
    sprite_x = new Sprite("tic-tac-toe/images/x.png");
    sprite_o = new Sprite("tic-tac-toe/images/o.png");

    sound_x = new Sound("tic-tac-toe/audio/c.wav");
    sound_o = new Sound("tic-tac-toe/audio/e.wav");
    sound_win = new Sound("tic-tac-toe/audio/arp.wav");
    sound_lose = new Sound("tic-tac-toe/audio/C_Reverse_Trim.wav");
    sound_draw = new Sound("tic-tac-toe/audio/C_Tritone_trimmed.wav");

    game_over = false;
}

void Board::add_player(int x, int y)
{
    static int turn = 0;

    if (reset_on_click) {
        memset(board, 0, sizeof(board));
        game_objs.clear();
        turn = 0;
        reset_on_click = false;
        return;
    }

    Player *p;
    if (turn == 0)
        p = new Player(sprite_x);
    else
        p = new Player(sprite_o);

    int sprite_width = sprite_o->get_width();
    int sprite_height = sprite_o->get_height();

    int cell_x = x / sprite_width;
    int cell_y = y / sprite_height;
    int draw_x = cell_x * sprite_width;
    int draw_y = cell_y * sprite_height;

    if (board[cell_y * 3 + cell_x] == 0) {
        p->set_pos(draw_x, draw_y);
        game_objs.push_back(p);
        board[cell_y * 3 + cell_x] = (turn == 0) ? 'x' : 'o';
        if (turn == 0)
            sound_x->play();
        else
            sound_o->play();
        turn = !turn;
    }

    char winners = check_win();
    for (int i = 0; i < 8; ++i) {
        if (winners & (1 << i)) {
            game_over = true;
            break;
        }
    }
}

void Board::update()
{
    if (game_over) {
        printf("Winner\n");
        fflush(stdout);
        sound_win->play();
        game_over = false;
        reset_on_click = true;
    }
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
