#ifndef cpeopleh
#define cpeopleh
#include "header.h"
class CPEOPLE{
private:
    int mX, mY;
    bool mState; //Trạng thái sống chết
<<<<<<< Updated upstream
    const unsigned int velocity = 5;
public:
    //CPEOPLE();
    void Up(int step);
    void Left(int step);
    void Right(int step);
    void Down(int step);
=======
    int velocity;

public:
    CPEOPLE(int x = 0, int y = 0, int v=5);
    void Up(int);
    void Left(int);
    void Right(int);
    void Down(int);
>>>>>>> Stashed changes
    bool isImpact(const OBSTACLE*&);
    bool isFinish();
    bool isDead();
};
#endif