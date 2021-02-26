#pragma once

#include "BuhaoEngine/GameObject.h"

struct SDL_Renderer;
struct Texture;

class Player : public GameObject {
private:
    Texture *texture;
    int board_x, board_y;
    double draw_x, draw_y;

public:
    Player(Texture *texture);
    Player(SDL_Renderer *renderer, const char texture[]);
    void init(Texture *texture);
    void set_pos(int x, int y);
    void update() override;
    void render(SDL_Renderer *) const override;
    int get_width();
    int get_height();
};
