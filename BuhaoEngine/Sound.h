#pragma once

#include <SDL2/SDL_mixer.h>
#include <iostream>

enum SoundType {
    MUSIC = 0,
    SCRATCH = 1
};

class Sound {
private:
    static constexpr int FREQ = 44100;
    static constexpr int CHAN = 2;
private:
    /*
    enum {
        Mix_Music *music,
        Mix_Chunk *chunk
    } audio;
    */
    void *audio;
    SoundType type;
    int vol;
public:
    Sound(const char filename[], SoundType type = SoundType::SCRATCH, int vol = 100);
    ~Sound();
    void play();

    static void pause_music();
    static void resume_music();
    static void stop_music(bool fade = true, int ticks = 1000);
};
