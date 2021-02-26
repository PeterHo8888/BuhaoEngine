#pragma once

struct SDL_Renderer;
struct SDL_Window;
struct Room;

class App {
private:
    const double MS_PER_UPDATE;
    bool running;
    SDL_Renderer *renderer;
    SDL_Window *window;
    Room *room;
private:
    void process_input();
    void update();
    void render(double);
public:
    App(const char title[], int width, int height);
    void main();
    void set_default_room(Room *);
};
