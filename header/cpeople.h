#ifndef cpeopleh
#define cpeopleh
#include "header.h"
class CPEOPLE{
    int mX, mY;
    bool mState; //Trạng thái sống chết
    const unsigned int velocity = 5;
public:
    //CPEOPLE();
    void Up(int step);
    void Left(int step);
    void Right(int step);
    void Down(int step);
    bool isImpact(const OBSTACLE*&);
    bool isFinish();
    bool isDead();
};
#endif