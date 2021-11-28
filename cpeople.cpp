#include "header/header.h"

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void CPEOPLE::Up(int step){
    mY-=step*velocity;
=======
CPEOPLE::CPEOPLE(int x, int y, int v)
: mX(x), mY(y), mState(1), velocity(v){
=======
CPEOPLE::CPEOPLE(int x, int y, int finY, int v)
: mX(x), mY(y), mState(1), finishedY(finY), velocity(v){
>>>>>>> Stashed changes
    draw();
>>>>>>> Stashed changes
}

void CPEOPLE::Left(int step){
    mX-=step*velocity;
}

<<<<<<< Updated upstream
void CPEOPLE::Right(int step){
    mX+=step*velocity;
}

void CPEOPLE::Down(int step){
    mY+=step*velocity;
=======
void CPEOPLE::clear() {
    gotoXY(mX, mY); cout << "      ";
    gotoXY(mX, mY + 1); cout << "      ";
    gotoXY(mX, mY + 2); cout << "      ";
}

void CPEOPLE::Up(int step){
<<<<<<< Updated upstream
    mX -= step*velocity;
=======
    mX-=step*velocity;
>>>>>>> Stashed changes
}

void CPEOPLE::Left(int step){
    mY-= step*velocity;
}

void CPEOPLE::Right(int step){
<<<<<<< Updated upstream
    mY+= step*velocity;
}

void CPEOPLE::Down(int step){
    mX += step*velocity;
>>>>>>> Stashed changes
}

bool CPEOPLE::isDead(){
    return mState;
}
=======
    mY+=step*velocity;
}

void CPEOPLE::Down(int step){
    mX+=step*velocity;
}

bool 
>>>>>>> Stashed changes
