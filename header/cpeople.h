#ifndef cpeopleh
#define cpeopleh
#include "header.h"
class CPEOPLE{
    int mX, mY;
    bool mState; //Trạng thái sống chết
    int velocity;
    int yFinish;
    const int width=6;
    const int height=3;

public:
    CPEOPLE(int x = 0, int y = 0, int v=2, int yFin=0);
    void Up(int step);
    void Left(int step);
    void Right(int step);
    void Down(int step);
    bool isImpact(vector<LANE*> lanes);
    bool isFinish();
    bool isDead();
    void draw();
    void clear();
};
#endif