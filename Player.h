#pragma once

#include "BuhaoEngine/GameObject.h"

struct Texture;

class Player : public GameObject {
private:
    Texture *texture;
    int board_x, board_y;
    int draw_x, draw_y;

public:
    Player(Texture *texture);
    void init(Texture *texture);
    void update() override;
    void render() const override;
    int get_width();
    int get_height();
    void set_pos(int x, int y);
};
