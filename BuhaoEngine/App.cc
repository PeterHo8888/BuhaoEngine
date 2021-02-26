#include "App.h"
#include "Room.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __SWITCH__
#include <switch.h>
#endif
#include <SDL2/SDL.h>

#ifdef __SWITCH__
#define yeet (void*)
#else
#define yeet throw
#endif

App::App(const char title[], int width, int height) : MS_PER_UPDATE(16), running(false), room(nullptr)
{
#ifdef __SWITCH__
    romfsInit();
    chdir("romfs:/");
#else
    chdir("romfs/");
#endif
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width, height,
            0);
    if (!window) {
        printf("Failed to open window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    running = true;
}

void App::set_default_room(Room *room)
{
    if (!renderer)
        yeet "Renderer is not set";
    if (!room)
        yeet "Room is null";

    room->set_renderer(renderer);
    room->init();
    this->room = room;
}

void App::main()
{
    double prev = SDL_GetTicks();
    double lag = 0.0;

    while (running) {
        double current = SDL_GetTicks();
        double elapsed = current - prev;

        double time_left = MS_PER_UPDATE - elapsed;
        if (time_left > 0)
            SDL_Delay(time_left);

        prev = current;
        lag += elapsed;

        process_input();

        while (lag >= MS_PER_UPDATE) {
            update();
            lag -= MS_PER_UPDATE;
        }

        render(lag / MS_PER_UPDATE);
    }
}

void App::process_input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            room->process_input(&event);
        }
    }
}

void App::update()
{
    room->update();
}

void App::render(double lag_multiplier)
{
    SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
    SDL_RenderClear(renderer);
    room->render(renderer);
    SDL_RenderPresent(renderer);
}
