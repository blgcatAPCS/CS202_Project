#include "header/header.h"

using namespace std;
//Các hằng số và biến toàn cục cần thiết

char MOVING;
CGAME g;
bool IS_RUNNING = 1;

// void SubThread(){
//     while (IS_RUNNING) {
//         if (!g.getPeople().isDead()) //Nếu người vẫn còn sống
//         {
//             g.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
//         }
//             MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
//             g.moveObstacles();
//             g.drawGame();
//             if (g.getPeople().isImpact()){
//             // Xử lý khi đụng xe hay thú
//                 IS_RUNNING=0;
//             }
//             if (g.getPeople().isFinish()){
//             // Xử lý khi về đích
//             }
//         Sleep(100);
//     }
// }

int main()
{
    // cout<<1;
    // system("Pause");
    // // cg = new CGAME();
    int temp;
    fixConsoleWindow();
    boardGame();
    
    while (!g.getPeople().isImpact(g.getLanes())){
        g.moveObstacles();
        char c=toupper(getch());
        g.updatePosPeople(c);
    }
    
    // cg.startGame();
    // thread t1(SubThread);
    // while (1)
    // {
    //     temp = toupper(_getch());
    //     if (!g.getPeople().isDead())
    //     {
    //         if (temp == 27) {
    //             g.exitGame(t1.native_handle());
    //             return 0;
    //         }
    //         else if (temp == 'P') {
    //             g.pauseGame(t1.native_handle());
    //         }
    //         else {
    //             g.resumeGame((HANDLE)t1.native_handle());
    //             MOVING = temp; //Cập nhật bước di chuyển
    //             g.moveObstacles();
    //             char tmp=toupper(_getch());
    //             g.updatePosPeople(tmp);
    //         }
    //     }
    //     else {
    //         if (temp == 'Y') g.startGame();
    //         else {
    //             g.exitGame(t1.native_handle());
    //             exit;
    //         }
    //     }
    // }
    return 0;
}