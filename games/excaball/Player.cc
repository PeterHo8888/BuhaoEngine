#include "Player.h"
#include <BuhaoEngine/Sprite.h>
#include <SDL2/SDL.h>
#include <cmath>

#include <iostream>
using namespace std;

Player::Player(Sprite *s)
{
    set_visible(true);
    set_sprite(s);
}

void Player::update()
{
}

void Player::render() const
{
    sprite->render(x, y);
}
