#pragma once

class Draw {
private:
public:
    static void draw_line(int x1, int y1, int x2, int y2, int t, int r, int g, int b, int a);
    static void draw_rounded_rect(int x1, int y1, int x2, int y2, int rad, int r, int g, int b, int a);
    static void get_scale(float *x, float *y);
    static void set_scale(float x, float y);
};
