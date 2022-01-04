#include "header/header.h"

using namespace std;


char MOVING;
bool IS_RUNNING = 1;

bool checkSound = false;

int main()
{
    int temp;
    hidePointer();
    fixConsoleWindow();
    int choice = 0, c;
    CGAME g;
    while(1){
        drawMenu(choice);
        switch (c = _getch()) {
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
                        g.terminate(1);
                        break;
                    case 1:
                        try{
                            g.loadGame();
                            g.startGame();
                            g.terminate(1);
                        }
                        catch(...){
                            clrscr();
                            gotoXY(25,11);
                            cout << "Press any key to go back to the main menu";
                            _getch();
                        }
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