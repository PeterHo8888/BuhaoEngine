#include <BuhaoEngine/App.h>
#include "Level.h"
int main(int, char **)
{
    App app("Excaball", 1280, 720);

    Level level1;
    app.set_default_room(&level1);
    app.main();
}
