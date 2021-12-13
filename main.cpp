#include "header/header.h"

using namespace std;


char MOVING;
bool IS_RUNNING = 1;


int main()
{
    int temp;
    hidePointer();
    fixConsoleWindow();
    int choice = 0, c;
    CGAME g;
    while(1){
        drawMenu(choice);
        switch (c = getch()) {
            case UP:
                choice = (choice + 3) % 4;
                break;
            case DOWN:
                choice = (choice + 1) % 4;
                break;
            case ENTER: {
                switch (choice) {
                    case 0:
                        g.newGame();
                        g.startGame();
                        g.terminate();
                        break;
                    case 1:
                        g.loadGame();
                        g.startGame();
                        g.terminate();
                        break;
                    case 2: 
                        settingsMenu();
                        break;
                    
                    default:
                        break;
                }

            }
        }
    }
    
    return 0;
}