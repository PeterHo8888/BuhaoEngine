#include "Player.h"
#include "BuhaoEngine/Sprite.h"
#include <SDL2/SDL.h>

Player::Player(Sprite *s) : GameObject(0, 0, 0, 0.0, true, s)
{
}

void Player::update()
{
    // Stub, players don't update after placed onto board
}

void Player::render() const
{
    sprite->render(x, y);
}
