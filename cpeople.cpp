#include "header/header.h"

void CPEOPLE::Up(int step){
    mY-=step*velocity;
}

void CPEOPLE::Left(int step){
    mX-=step*velocity;
}

void CPEOPLE::Right(int step){
    mX+=step*velocity;
}

void CPEOPLE::Down(int step){
    mY+=step*velocity;
}

bool CPEOPLE::isDead(){
    return mState;
}