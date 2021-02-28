#include <BuhaoEngine/App.h>
#include "Board.h"
int main(int, char **)
{
    App app("Tic Tac Toe", 600, 600);

    Board room;
    app.set_default_room(&room);
    app.main();
}
