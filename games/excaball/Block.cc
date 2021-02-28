#include "Block.h"

#include <BuhaoEngine/Sprite.h>

#include <iostream>
using namespace std;

Sprite *Block::sprite = nullptr;

Block::Block()
{
    if (!sprite)
        sprite = new Sprite("excaball/images/wall_block48.png");
    set_visible(true);
    set_sprite(sprite);
}

void Block::update()
{}

void Block::render() const
{
    sprite->render(x, y);
}
