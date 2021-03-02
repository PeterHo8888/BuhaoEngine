#pragma once

#include <BuhaoEngine/GameObject.h>

class Button : public GameObject {
private:
    int x2, y2, rad;
    int r, g, b, a;
public:
    Button(int x1, int y1, int x2, int y2, int rad);
    void set_color(int r, int g, int b, int a);
    void update() override;
    void render() const override;
};
