#pragma once

#include "Texture.h"
#include <vector>

class Sprite {
    std::vector<Texture *> t;
    double framerate;
    size_t cur_frame;
public:
    Sprite(const char filename[]);
    void add_frame(const char filename[]);
    void render(int, int);
    void set_rate(double rate) { framerate = rate; }
    void set_frame(size_t frame)
    {
        if (frame >= t.size())
            return;
        cur_frame = frame;
    }
    int get_width() { return t[cur_frame]->get_width(); }
    int get_height() { return t[cur_frame]->get_height(); }
};
