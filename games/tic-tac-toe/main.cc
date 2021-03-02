#include <BuhaoEngine/App.h>
#include "Menu.h"
#include "Board.h"
int main(int, char **)
{
    App app("Tic Tac Toe", 1280, 720);

    Menu menu(&app);
    app.add_room("Main Menu", &menu);

    app.change_room("Main Menu");

    app.run();
}
