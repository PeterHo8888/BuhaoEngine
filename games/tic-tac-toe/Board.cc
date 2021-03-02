#include "Board.h"
#include "Player.h"
#include "Button.h"
#include <BuhaoEngine/Sprite.h>
#include <BuhaoEngine/Sound.h>
#include <BuhaoEngine/Shapes/Line.h>
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

static pair<char, char> results;
static bool is_draw;

static Line *win_lines[8];

static Button *btn_exit;

inline static bool check_draw()
{
    for (int i = 0; i < 9; ++i)
        if (!board[i])
            return false;
    return true;
}

static pair<char, char> check_win()
{
    char winner = '\0';
    char paths = 0;

    // check horizontals
    for (int y = 0; y < 3; ++y) {
        if (board[y * 3] && board[y * 3] == board[y * 3 + 1] && board[y * 3] == board[y * 3 + 2]) {
            winner = board[y * 3];
            paths |= 1 << y;
        }
    }

    // check verticals
    for (int x = 0; x < 3; ++x) {
        if (board[x] && board[x] == board[3 + x] && board[x] == board[6 + x]) {
            winner = board[x];
            paths |= 1 << (x + 3);
        }
    }

    // check diagonals
    if (board[0] && board[0] == board[4] && board[4] == board[8]) {
        winner = board[0];
        paths |= 1 << 6;
    }

    if (board[2] && board[2] == board[4] && board[4] == board[6]) {
        winner = board[2];
        paths |= 1 << 7;
    }

    return pair<char, char>(winner, paths);
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

    const int pad = 60;
    const int diag_adj = 50;
    for (int y = 0; y < 3; ++y)
        win_lines[y] = new Line(440 - pad, 160 + y * 200, 840 + pad, 160 + y * 200, 5);
    for (int x = 0; x < 3; ++x)
        win_lines[x + 3] = new Line(440 + x * 200, 160 - pad, 440 + x * 200, 560 + pad, 5);
    win_lines[6] = new Line(440 - pad + diag_adj, 160 - pad + diag_adj, 840 + pad - diag_adj, 560 + pad - diag_adj, 5);
    win_lines[7] = new Line(840 + pad - diag_adj, 160 - pad + diag_adj, 440 - pad + diag_adj, 560 + pad - diag_adj, 5);
    for (int i = 0; i < 8; ++i)
        win_lines[i]->set_color(100, 200, 0);

    game_over = false;
    is_draw = false;
    results = pair<char, char>(0, 0);

    int btn_width = 100;
    int btn_height = 25;
    btn_exit = new Button(640 - btn_width, 360 - btn_height, 640 + btn_width, 360 + btn_height, btn_height);
    btn_exit->set_color(98, 203, 158, 255);
    game_objs.push_back(btn_exit);
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

    int sprite_width = sprite_o->get_width();
    int sprite_height = sprite_o->get_height();

    if (x < 640 - 1.5 * sprite_width || x >= 640 + 1.5 * sprite_width) {
        cout << "X out of bounds" << endl;
        return;
    }
    if (y < 360 - 1.5 * sprite_height || y >= 360 + 1.5 * sprite_height) {
        cout << "Y out of bounds" << endl;
        return;
    }

    Player *p;
    if (turn == 0)
        p = new Player(sprite_x);
    else
        p = new Player(sprite_o);

    int cell_x = (x - 640 + 1.5 * sprite_width) / sprite_width;
    int cell_y = (y - 360 + 1.5 * sprite_height) / sprite_height;
    int draw_x = cell_x * sprite_width + 640 - 1.5 * sprite_width;
    int draw_y = cell_y * sprite_height + 360 - 1.5 * sprite_height;

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

    results = check_win();
    is_draw = check_draw() && !results.second;
    if (results.second || is_draw)
        game_over = true;
}

void Board::update()
{
    if (game_over) {
        if (is_draw) {
            cout << "Draw" << endl;
            sound_draw->play();
        } else {
            cout << "Winner is " << results.first << endl;
            if (results.first == 'x')
                sound_win->play();
            else
                sound_lose->play();
            for (int i = 0; i < 8; ++i)
                if (results.second & (1 << i))
                    game_objs.push_back(win_lines[i]);
        }
        game_over = false;
        reset_on_click = true;
    }
}

void Board::process_input(SDL_Event *e)
{
    switch (e->type) {
    case SDL_FINGERUP:
        add_player(e->tfinger.x * 1280, e->tfinger.y * 720);
        break;
    case SDL_MOUSEBUTTONUP:
        if (e->button.button == SDL_BUTTON_LEFT)
            add_player(e->button.x, e->button.y);
        break;
    default:
        break;
    }
}
