#ifndef cpeopleh
#define cpeopleh

#include "header.h"
#include "clane.h"

class CPEOPLE{
    int mX, mY;
    bool mState; //Trạng thái sống chết
    int velocity;
    int yFinish;
    const int width=6;
    const int height=3;
    int HP=100;
    

public:
    CPEOPLE(int x = 0, int y = 0, int v=2, int yFin=1);
    void Up(int step);
    void Left(int step);
    void Right(int step);
    
    void Down(int step);
    void setHP(int num);
    int isImpact(vector<LANE*> lanes); //return damage
    bool isFinish();
    bool isDead();
    void draw();
    void clear();
};
#endif