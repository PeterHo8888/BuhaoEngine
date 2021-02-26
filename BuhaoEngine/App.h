#pragma once

struct SDL_Renderer;
struct SDL_Window;
struct Room;

class App {
private:
    const double MS_PER_UPDATE;
    bool running;
    static SDL_Renderer *renderer;
    static SDL_Window *window;
    Room *room;
private:
    void process_input();
    void update();
    void render(double);
public:
    App(const char title[], int width, int height);
    void main();
    void set_default_room(Room *);
    static SDL_Renderer *get_renderer() { return renderer; }
};
