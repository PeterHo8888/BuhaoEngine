#pragma once

struct Texture;

/*
 * Base 2D GameObject class
 */
class GameObject {
protected:
    double x, y, z;
    double gravity;
    bool visible;
    //Sprite *s;
public:
    virtual void update() = 0;
    virtual void render() const = 0;

public:
    void set_gravity(double g) { g = g; }
    void set_x(double x) { this->x = x; }
    void set_y(double y) { this->y = y; }
    void set_pos(double x, double y)
    {
        set_x(x);
        set_y(y);
    }
    void set_z(double z) { this->z = z; }
};
