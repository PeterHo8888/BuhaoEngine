#include "Sound.h"

#include <SDL2/SDL_mixer.h>

Sound::Sound(const char filename[], SoundType type, int vol) : type(type), vol(vol)
{
    static bool mixer_initialized = false;

    if (!mixer_initialized) {
        if (Mix_OpenAudio(FREQ, MIX_DEFAULT_FORMAT, CHAN, 2048) < 0)
            std::cout << "SDL_Mixer Error: " << SDL_GetError() << std::endl;
    }

    switch (type) {
    case SoundType::MUSIC:
        audio = Mix_LoadMUS(filename);
        break;
    default:
        audio = Mix_LoadWAV(filename);
        break;
    }

    if (!audio) // Is enum, works either way
        std::cout << "Couldn't load " << filename << ": " << Mix_GetError() << std::endl;
}

Sound::~Sound()
{
    switch (type) {
    case SoundType::MUSIC:
        Mix_FreeMusic((Mix_Music *)audio);
        audio = nullptr;
        break;
    default:
        Mix_FreeChunk((Mix_Chunk *)audio);
        audio = nullptr;
        break;
    }
}

void Sound::play()
{
    switch (type) {
    case SoundType::MUSIC:
        Sound::stop_music();
        Mix_PlayMusic((Mix_Music *)audio, -1);
        Mix_VolumeMusic(MIX_MAX_VOLUME / (vol / 100.0));
        break;
    default:
        Mix_HaltChannel(-1);
        Mix_PlayChannel(-1, (Mix_Chunk *)audio, 0);
        Mix_VolumeMusic(MIX_MAX_VOLUME / (vol / 100.0));
        break;
    }
}

void Sound::stop_music(bool fade, int ticks)
{
    if (fade)
        Mix_FadeOutMusic(ticks);
    else
        Mix_HaltMusic();
}

void Sound::pause_music()
{
    if (Mix_PlayingMusic() == 0)
        return;
    Mix_PauseMusic();
}

void Sound::resume_music()
{
    // TODO: Figure out if these checks are necessary
    if (Mix_PlayingMusic() && Mix_PausedMusic())
        Mix_ResumeMusic();
}
