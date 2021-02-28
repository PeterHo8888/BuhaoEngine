#include "Level.h"
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Level::Level() : current_world(0), current_level(0), level_buffer(new char[220])
{}

Level::~Level()
{
    delete[] level_buffer;
}

void Level::init()
{
    load_level(1, 1);
}

void Level::reload_room()
{
    game_objs.clear();
    cout << "World " << current_world << " Level " << current_level << '\n';
    for (size_t i = 0; i < 220; ++i) {
        if (i && i % 20 == 0)
            cout << '\n';
        cout << level_buffer[i] << " ";

        switch (level_buffer[i]) {
        case STANDARD:
            break;
        case COIN:
            break;
        case GEM:
            break;
        case BUTTON:
            break;
        default:
            break;
        }
    }
    cout << endl;
}

void Level::load_level(int world, int level)
{
    current_world = world;
    current_level = level;

    stringstream path;
    path << "excaball/levels/world_" << world;
    path << "/level" << level << ".txt";

    ifstream file(path.str());

    char block;
    for (size_t i = 0; i < 220 && file >> block; ++i)
        level_buffer[i] = block;

    file.close();

    reload_room();
}

void Level::update()
{}

void Level::process_input(SDL_Event *e)
{
    switch (e->type) {
    }
}
