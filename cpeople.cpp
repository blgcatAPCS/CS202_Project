#include "header/header.h"

CPEOPLE::CPEOPLE(int x, int y, int v, int yFin)
: mX(x), mY(y), mState(1), velocity(v), yFinish(yFin){
    draw();
}

void CPEOPLE::draw(){
    gotoXY(mX, mY); cout << " ('') ";
    gotoXY(mX, mY + 1); cout << "/[  ]\\";
    gotoXY(mX, mY + 2); cout << "  UU  ";
}

void CPEOPLE::clear() {
    gotoXY(mX, mY); cout << "      ";
    gotoXY(mX, mY + 1); cout << "      ";
    gotoXY(mX, mY + 2); cout << "      ";
}

void CPEOPLE::Up(int step){
    mY-=step*velocity;
}

void CPEOPLE::Left(int step){
    mX-= step*velocity;
}

void CPEOPLE::Right(int step){
    mX+=step*velocity;
}

void CPEOPLE::Down(int step){
    mY+=step*velocity;
}

bool CPEOPLE::isFinish(){
    return mY<=yFinish;
}

bool CPEOPLE::isDead(){
    return !mState;
}

bool CPEOPLE::isImpact(OBSTACLE *obj){
    int objLeftbound=obj->getPosX();
    int objRightbound=objLeftbound+obj->getWidth();
    
    int objUpperbound=obj->getPosY();
    int objLowebound=objUpperbound+obj->getHeight();

    return ((objUpperbound<=mY && mY<=objLowebound) || (objUpperbound<=mY+height && mY+height<=objLowebound)) 
            && ((objLeftbound<=mX && mX<=objRightbound) || (objLeftbound<=mX+width && mX+width<=objRightbound));
}