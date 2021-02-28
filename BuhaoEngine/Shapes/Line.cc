#include "Line.h"
#include "../Draw.h"

#include <SDL2/SDL.h>

Line::Line(int x1, int y1, int x2, int y2, int t) : x2(x2), y2(y2), t(t)
{
    set_x(x1);
    set_y(y1);
    set_visible(true);
}

void Line::set_color(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Line::render() const
{
    Draw::draw_line(x, y, x2, y2, t, r, g, b, a);
}
