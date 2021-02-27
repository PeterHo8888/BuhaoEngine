#pragma once

#include "BuhaoEngine/GameObject.h"

class Sprite;

class Player : public GameObject {
public:
    Player(Sprite *);
    void update() override;
    void render() const override;
};
