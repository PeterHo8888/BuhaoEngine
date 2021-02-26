#pragma once

#include "Texture.h"

class Sprite {
    Texture *t;
public:
    void render();
    int get_width() { return t->get_width(); }
    int get_height() { return t->get_height(); }
};
