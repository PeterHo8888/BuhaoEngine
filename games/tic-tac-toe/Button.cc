#include "Button.h"
#include <BuhaoEngine/Draw.h>

#include <iostream>
using namespace std;

Button::Button(int x1, int y1, int x2, int y2, int rad) :
    x2(x2), y2(y2), rad(rad), r(96), g(128), b(255), a(255)
{
    set_x(x1);
    set_y(y1);
    set_visible(true);
}

void Button::set_color(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Button::update()
{
}

void Button::render() const
{
    Draw::draw_rounded_rect(x, y, x2, y2, rad, r, g, b, a);
}
