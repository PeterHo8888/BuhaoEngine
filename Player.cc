#include "Player.h"
#include "BuhaoEngine/Texture.h"
#include <SDL2/SDL.h>

Player::Player(Texture *texture)
{
    init(texture);
}

void Player::init(Texture *texture)
{
    this->texture = texture;
    board_x = 0;
    board_y = 0;
}

void Player::set_pos(int x, int y)
{
    board_x = x;
    board_y = y;
    draw_x = board_x * texture->get_width();
    draw_y = board_y * texture->get_height();
}

void Player::update()
{
    // Stub, players don't update after placed onto board
}

void Player::render() const
{
    texture->blit(draw_x, draw_y);
}

int Player::get_width()
{
    return texture->get_width();
}
int Player::get_height()
{
    return texture->get_height();
}
