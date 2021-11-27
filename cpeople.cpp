#include "header/header.h"

CPEOPLE::CPEOPLE(int x, int y)
: mX(x), mY(y), mState(1){
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