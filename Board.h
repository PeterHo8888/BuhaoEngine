#pragma once

#include "BuhaoEngine/Room.h"

union SDL_Event;

class Board : public Room {
private:
    void add_player(int x, int y);
public:
    Board();
    void update() override;
    void process_input(SDL_Event *) override;
    void init() override;
};
