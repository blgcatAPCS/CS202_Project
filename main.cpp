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
                        newGame();
                        g.newGame();
                        g.startGame();
                        break;
                    case 1:
                        loadGame();
                        g.startGame();
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