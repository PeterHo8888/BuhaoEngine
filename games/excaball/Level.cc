#include "Level.h"
#include "Block.h"
#include <BuhaoEngine/Sound.h>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Level::Level() : current_world(0), current_level(0), level_buffer(new char[Level::SIZE]), bgm(nullptr)
{}

Level::~Level()
{
    delete[] level_buffer;
    delete[] bgm;
}

void Level::init()
{
    load_level(1, 1);
}

void Level::reload_room()
{
    game_objs.clear();
    cout << "World " << current_world << " Level " << current_level << '\n';
    for (size_t i = 0; i < Level::SIZE; ++i) {
        GameObject *obj;
        switch (level_buffer[i]) {
        case BlockType::BLOCK:
            obj = new Block;
            obj->set_pos((Block::WIDTH * i) % (Block::WIDTH * Level::WIDTH), i / Level::WIDTH * Block::WIDTH);
            game_objs.push_back(obj);
            break;
        case BlockType::COIN:
            break;
        case BlockType::GEM:
            break;
        case BlockType::BUTTON:
            break;
        default:
            break;
        }
    }
    cout << endl;

    if (bgm)
        delete[] bgm;
    bgm = new Sound("excaball/audio/Sound_Intro.ogg", SoundType::MUSIC);
    bgm->play();
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
    for (size_t i = 0; i < Level::SIZE && file >> block; ++i)
        level_buffer[i] = block - '0';

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
