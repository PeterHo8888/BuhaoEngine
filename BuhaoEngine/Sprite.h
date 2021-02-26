#pragma once

#include "Texture.h"

class Sprite {
    Texture *t;
public:
    Sprite(const char filename[]);
    void render(int, int);
    int get_width() { return t->get_width(); }
    int get_height() { return t->get_height(); }
};
