#pragma once

struct Sprite;
/*
 * Base 2D GameObject class
 */
class GameObject {
protected:
    double x, y, z;
    double gravity;
    bool visible;
    Sprite *sprite;
public:
    /* Engine req'd impls */
    virtual void update() = 0;
    virtual void render() const = 0;

protected:
    GameObject(double x = 0.0, double y = 0.0, double z = 0.0,
            double g = 0.0, bool v = false, Sprite *s = nullptr) :
        x(x), y(y), z(z), gravity(g), visible(v), sprite(s)
    {}
public:
    // Generic operations on a GameObject
    void set_x(double x) { this->x = x; }
    void set_y(double y) { this->y = y; }
    void set_pos(double x, double y)
    {
        set_x(x);
        set_y(y);
    }
    void set_gravity(double g) { g = g; }
    void set_z(double z) { this->z = z; }
    void set_visible(bool v) { this->visible = v; }
    void set_sprite(Sprite *s) { this->sprite = s; }
};
