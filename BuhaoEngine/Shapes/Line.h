#pragma once

#include "../GameObject.h"

struct SDL_Rect;

class Line : public GameObject {
private:
    // x1 and y1 are from GameObject as x, y
    int x2, y2;
    int r, g, b, a;
    int t;
public:
    Line(int x1, int y1, int x2, int y2, int t = 1);
    void set_color(int r, int g, int b, int a = 255);
    void render() const override;
    // TODO: Figure out motion overrides for physics
};
