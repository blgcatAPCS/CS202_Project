#include "header/header.h"

using namespace std;


char MOVING;
bool IS_RUNNING = 1;


int main()
{
    int temp;
    hidePointer();
    fixConsoleWindow();
    boardGame();
    CGAME g;
    
    std::chrono::high_resolution_clock::time_point start;
    // std::chrono::high_resolution_clock::time_point start_tf=high_resolution_clock::now();
    while (!g.getPeople().isDead() && !g.getPeople().isFinish()){
        // g.activateTraffic(start_tf);
        g.moveObstacles();
        g.updatePeople(start);
    }
    return 0;
}