#ifndef cpeopleh
#define cpeopleh

#include "header.h"
#include "clane.h"

class CPEOPLE{
    int mX, mY;
<<<<<<< Updated upstream
=======
    int velocity;

    vector<string> image={" ('') ","/[  ]\\","  UU  "};

>>>>>>> Stashed changes
    bool mState; //Trạng thái sống chết
    int velocity;
    int yFinish;
<<<<<<< Updated upstream
    const int width=6;
    const int height=3;

=======

    int width;
    int height;

    const int topBorder=1;
    const int botBorder=30;
    const int leftBorder=0;
    const int rightBorder=120;

    const int trafficHeight=3;
    const int trafficWidth=9;
    
    int HP=100;
    
    bool isXInsideTrafficLight();

>>>>>>> Stashed changes
public:
    CPEOPLE(int x = 0, int y = 0, int v=2, int yFin=1);
    void Up(int step);
    void Left(int step);
    void Right(int step);
    void Down(int step);
<<<<<<< Updated upstream
    bool isImpact(vector<LANE*> lanes);
    bool isFinish();
    bool isDead();
    void draw();
    void clear();
=======
    void resetPos();

    void setHP(int num);

    int isImpact(vector<LANE*> lanes); //return damage
    bool isFinish();
    bool isDead();

    void draw(vector<LANE*> lanes);
    void clear(vector<LANE*> lanes);
    void save(ofstream &ofs);
    void load(ifstream &ifs);
    string getName();
    
>>>>>>> Stashed changes
};
#endif