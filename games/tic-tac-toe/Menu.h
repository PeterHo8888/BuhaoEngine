#pragma once

#include <BuhaoEngine/Room.h>

union SDL_Event;

class Menu : public Room {
private:
    void add_player(int x, int y);
public:
    Menu(App *app) : Room(app) {}
    void update() override;
    void process_input(SDL_Event *) override;
    void init() override;
};
