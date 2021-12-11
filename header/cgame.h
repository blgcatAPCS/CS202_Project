#ifndef cgameh
#define cgameh
#include "header.h"
class CGAME{
    vector<LANE*> lanes;
    CPEOPLE *cn;
    cTraffic *traffic;
    int level;
    bool freeze=false; //unharmed after impacted
public:
    void freezing(std::chrono::high_resolution_clock::time_point &start);
    CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
    void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
    ~CGAME(); // Hủy tài nguyên đã cấp phát
    CPEOPLE getPeople();//Lấy thông tin người
    vector<LANE*> getLanes();
    //CVEHICLE* getVehicle();//Lấy danh sách các xe
    //CANIMAL* getAnimal(); //Lấy danh sách các thú
    void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
    void exitGame(HANDLE); // Thực hiện thoát Thread
    void startGame(); // Thực hiện bắt đầu vào trò chơi
    void newGame();
    void loadGame(); // Thực hiện tải lại trò chơi đã lưu
    void saveGame(); // Thực hiện lưu lại dữ liệu trò chơi
    void pauseGame(HANDLE); // Tạm dừng Thread
    void resumeGame(HANDLE); //Quay lai Thread
    void updatePeople(std::chrono::high_resolution_clock::time_point &start); //Thực hiện điều khiển di chuyển của CPEOPLE // Cat in charge
    void moveObstacles();
    void activateTraffic(std::chrono::high_resolution_clock::time_point &start);
    void initiate();
};
#endif 