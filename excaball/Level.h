#pragma once

#include <BuhaoEngine/Room.h>

union SDL_Event;

enum BlockType {
    STANDARD = 0,
    COIN = 1,
    GEM = 2,
    BUTTON = 3,
};

class Level : public Room {
private:
    int current_world;
    int current_level;
    char *level_buffer;
private:
    void reload_room();
    void load_level(int world, int level);
public:
    Level();
    ~Level();
public:
    void update() override;
    void process_input(SDL_Event *) override;
    void init() override;
};
