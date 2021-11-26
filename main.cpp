#include "header/header.h"
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
    CGAME g;
    while(1){
        g.moveObstacles();
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