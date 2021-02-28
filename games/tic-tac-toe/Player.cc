#include "Player.h"
#include <BuhaoEngine/Sprite.h>
#include <SDL2/SDL.h>
#include <cmath>

#include <iostream>
using namespace std;

// http://dentedpixel.com/LeanTweenDocumentation/files/LeanTween.cs.html
static float ease_out_bounce(float start, float end, float val)
{
    val /= 1.0f;
    end -= start;
    if (val < (1 / 2.75f)) {
        return end * (7.5625f * val * val) + start;
    } else if (val < (2 / 2.75f)) {
        val -= (1.5f / 2.75f);
        return end * (7.5625f * (val) * val + .75f) + start;
    } else if (val < (2.5 / 2.75)) {
        val -= (2.25f / 2.75f);
        return end * (7.5625f * (val) * val + .9375f) + start;
    } else {
        val -= (2.625f / 2.75f);
        return end * (7.5625f * (val) * val + .984375f) + start;
    }
}

Player::Player(Sprite *s)
{
    set_visible(true);
    set_sprite(s);
}

void Player::update()
{
    // Stupid anim test, if vx == 1 then do animation
    static float count = 0;
    if (vx == 1) {
        x -= 1;
        if (count <= 100.0)
            y = ease_out_bounce(0, 400, count++ / 100.0);
        else
            vx = 0;
    }
}

void Player::render() const
{
    sprite->render(x, y);
}
