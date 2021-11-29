#include "header/header.h"

using namespace std;

void subThread(){
    while (IS_RUNNING) {
        if (!g.getPeople().isDead()) //Nếu người vẫn còn sống
        {
            g.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
        }
            MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
            g.moveObstacles();
            g.drawGame();
            if (g.getPeople().isImpact(g.getLanes())){
            // Xử lý khi đụng xe hay thú
            }
            if (g.getPeople().isFinish()){
            // Xử lý khi về đích
            }
        Sleep(100);
    }
}