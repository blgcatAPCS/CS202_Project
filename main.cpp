#include "header/header.h"

using namespace std;
//Các hằng số và biến toàn cục cần thiết
char MOVING;
// CGAME cg;
int main()
{
    // cout<<1;
    // system("Pause");
    // // cg = new CGAME();
    // int temp;
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
    
    CGAME g;
    while(1){
        g.moveObstacles();
        char tmp=toupper(getch());
        g.updatePosPeople(tmp);
    }
    // cg.startGame();
    // thread t1(SubThread);
    // while (1)
    // {
    //     temp = toupper(getch());
    //     if (!cg.getPeople().isDead())
    //     {
    //         if (temp == 27) {
    //         cg.exitGame(t1.native_handle());
    //         return;
    //     }
    //     else if (temp == 'P') {
    //         cg.pauseGame(t1.native_handle());
    //     }
    //     else {
    //         cg.resumeGame((HANDLE)t1.native_handle());
    //         MOVING = temp; //Cập nhật bước di chuyển
    //         }
    //     }
    //     else
    //     {
    //         if (temp == 'Y') cg.startGame();
    //         else {
    //             cg.exitGame(t1.native_handle());
    //             return;
    //         }
    //     }
    // }
}