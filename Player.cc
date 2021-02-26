#include "Player.h"
#include "BuhaoEngine/Sprite.h"
#include <SDL2/SDL.h>

Player::Player(Sprite *s)
{
    set_visible(true);
    set_sprite(s);
}

void Player::update()
{
    // Stub, players don't update after placed onto board
}

void Player::render() const
{
    sprite->render(x, y);
}
