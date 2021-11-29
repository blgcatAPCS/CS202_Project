#include "header/header.h"

using namespace std;
//Các hằng số và biến toàn cục cần thiết
// CGAME cg;
int main()
{
    // cout<<1;
    // system("Pause");
    // // cg = new CGAME();
    int temp;
    fixConsoleWindow();
    boardGame();
    
    // CTRUCK t(20,20);
    // CPEOPLE p(30,30);
    // t.draw(0);
    // p.draw();
    // while (!p.isImpact(&t)){
    //     char c=toupper(getch());
    //     switch (c){
    //     case 'A':
    //         p.Left(1);
    //         break;

    //     case 'W':
    //         p.Up(1);
    //         break;
        
    //     case 'S':
    //         p.Down(1);
    //         break;

    //     case 'D':
    //         p.Right(1);
    //         break;

    //     default:
    //         break;
    //     }

    //     p.draw();
    // }
    
    while(1){
    }
    // cg.startGame();
    thread t1(SubThread);
    while (1)
    {
        temp = toupper(getch());
        if (!g.getPeople().isDead())
        {
            if (temp == 27) {
                g.exitGame(t1.native_handle());
                return;
            }
            else if (temp == 'P') {
                g.pauseGame(t1.native_handle());
            }
            else {
                g.resumeGame((HANDLE)t1.native_handle());
                MOVING = temp; //Cập nhật bước di chuyển
                g.moveObstacles();
                char tmp=toupper(getch());
                g.updatePosPeople(tmp);
            }
        }
        else {
            if (temp == 'Y') g.startGame();
            else {
                g.exitGame(t1.native_handle());
                return;
            }
        }
    }
}