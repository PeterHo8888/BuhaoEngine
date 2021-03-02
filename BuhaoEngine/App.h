#pragma once

#include <string>
#include <unordered_map>

struct SDL_Renderer;
struct SDL_Window;
struct Room;

class App {
private:
    const double MS_PER_UPDATE;
    bool running;
    static SDL_Renderer *renderer;
    static SDL_Window *window;
    Room *current_room;
    std::unordered_map<std::string, Room *> room_map;
private:
    void process_input();
    void update();
    void render(double);
public:
    App(const char title[], int width, int height);
    void main();
    void add_room(std::string, Room *);
    void change_room(std::string);
    static SDL_Renderer *get_renderer() { return renderer; }
};
