#pragma once

#include <BuhaoEngine/Room.h>

union SDL_Event;
struct Sound;

enum BlockType {
    BLANK = 0,
    BLOCK = 1,
    COIN = 2,
    GEM = 3,
    BUTTON = 4,
};

class Level : public Room {
private:
    int current_world;
    int current_level;
    char *level_buffer;

    Sound *bgm;

    static constexpr int LEVEL_SIZE = 20 * 12;
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
