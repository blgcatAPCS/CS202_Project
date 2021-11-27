#ifndef cpeopleh
#define cpeopleh
#include "header.h"
class CPEOPLE{
    int mX, mY;
    bool mState; //Trạng thái sống chết
public:
    CPEOPLE(int x = 0, int y = 0);
    void Up(int);
    void Left(int);
    void Right(int);
    void Down(int);
    bool isImpact(const OBSTACLE*&);
    bool isFinish();
    bool isDead();
    void draw();
    void clear();
};
#endif