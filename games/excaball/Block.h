#pragma once

#include <BuhaoEngine/GameObject.h>

struct Sprite;

class Block : public GameObject {
private:
    static Sprite *sprite;
public:
    Block();
    void update() override;
    void render() const override;
};
