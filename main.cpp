#include "header/header.h"
#include "header/console.h"
using namespace std;


char MOVING;
bool IS_RUNNING = 1;


int main()
{
    int temp;
    unhidePointer();
    fixConsoleWindow();
    boardGame();
    CGAME g;
    while (!g.getPeople().isImpact(g.getLanes()) && !g.getPeople().isFinish()){
        g.moveObstacles();
        char c;
        if (_kbhit())
        {
            c=toupper(getch());
            g.updatePosPeople(c);
        }
    }
    return 0;
}