#pragma once

struct Sprite;
/*
 * Base 2D GameObject class
 */
class GameObject {
protected:
    double x, y, z;
    double vx, vy;
    double gravity;
    bool visible;
    Sprite *sprite;
public:
    /* Optional impls */
    virtual void update();
    // TODO: Create event stubs
public:
    /* Engine req'd impls */
    virtual void render() const = 0;

protected:
    GameObject(int x = 0.0, int y = 0.0, int z = 0.0,
            double vx = 0.0, double vy = 0.0,
            double g = 0.0, bool v = false, Sprite *s = nullptr) :
        x(x), y(y), z(z), vx(vx), vy(vy), gravity(g), visible(v), sprite(s)
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
    void set_vx(double vx) { this->vx = vx; }
    void set_vy(double vy) { this->vy = vy; }
    void set_gravity(double g) { this->gravity = g; }
    void set_z(double z) { this->z = z; }
    void set_visible(bool v) { this->visible = v; }
    void set_sprite(Sprite *s) { this->sprite = s; }
public:
    // Accessors
    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_z() const { return z; }
    int get_vx() const { return vx; }
    int get_vy() const { return vy; }
    double get_gravity() const { return gravity; }
    bool is_visible() const { return visible; }
    Sprite *get_sprite() const { return sprite; }
};
