#include "header/header.h"

using namespace std;

CPEOPLE::CPEOPLE(string n, int x, int y, int v, int yFin)
:name(n), mX(x), mY(y), mState(1), velocity(v), yFinish(yFin){
    draw();
}

void CPEOPLE::draw(){
    textColor(236);

    gotoXY(11, 29);
    cout << "LIFE (" << HP << "/100) : ";

    gotoXY(27, 29);
    for(int i = 0; i < (HP*5)/100 + 1; ++i){
        cout << char(219);
    }

    for(int i = 0; i < 5 - (HP*5)/100; ++i){
        textColor(239);
        cout << char(219);
    }

    textColor(224);
    if(mY >= 26 && mY <= consoleHeight){
        textColor(224);
    }
    else if(mY == 24){
        textColor(15);
        gotoXY(mX, mY); cout << " ('') ";
        gotoXY(mX, mY + 1); cout << "/[  ]\\";
        textColor(224);
        gotoXY(mX, mY + 2); cout << "  UU  ";

        return;
    }
    else if(mY >= 20){
        textColor(15);
    }
    else if(mY == 18){
        textColor(47);
        gotoXY(mX, mY); cout << " ('') ";
        gotoXY(mX, mY + 1); cout << "/[  ]\\";
        textColor(15);
        gotoXY(mX, mY + 2); cout << "  UU  ";

        return;
    }
    else if(mY > 15){
        textColor(47);
    }
    else if(mY == 14){
        textColor(159);
        gotoXY(mX, mY); cout << " ('') ";
        textColor(47);
        gotoXY(mX, mY + 1); cout << "/[  ]\\";
        gotoXY(mX, mY + 2); cout << "  UU  ";
        return;
    }
    else if(mY > 11){
        textColor(159);
    }
    else if(mY == 10){
        textColor(15);
        gotoXY(mX, mY); cout << " ('') ";
        textColor(159);
        gotoXY(mX, mY + 1); cout << "/[  ]\\";
        gotoXY(mX, mY + 2); cout << "  UU  ";
        return;
    }
    else if(mY > 5){
        textColor(15);
    }
    else if(mY == 4){
        textColor(47);
        gotoXY(mX, mY); cout << " ('') ";
        textColor(15);
        gotoXY(mX, mY + 1); cout << "/[  ]\\";
        gotoXY(mX, mY + 2); cout << "  UU  ";
        return;
    }
    else if(mY >= 0){
        textColor(47);
    }
    gotoXY(mX, mY); cout << " ('') ";
    gotoXY(mX, mY + 1); cout << "/[  ]\\";
    gotoXY(mX, mY + 2); cout << "  UU  ";
}

void CPEOPLE::clear() {
    if(mY >= 26 && mY <= consoleHeight){
        textColor(224);
    }
    else if(mY == 24){
        textColor(15);
        gotoXY(mX, mY); cout << "      ";
        gotoXY(mX, mY + 1); cout << "      ";
        textColor(224);
        gotoXY(mX, mY + 2); cout << "      ";

        return;
    }
    else if(mY >= 20){
        textColor(15);
    }
    else if(mY == 18){
        textColor(47);
        gotoXY(mX, mY); cout << "      ";
        gotoXY(mX, mY + 1); cout << "      ";
        textColor(15);
        gotoXY(mX, mY + 2); cout << "      ";

        return;
    }
    else if(mY > 15){
        textColor(47);
    }
    else if(mY == 14){
        textColor(159);
        gotoXY(mX, mY); cout << "      ";
        textColor(47);
        gotoXY(mX, mY + 1); cout << "      ";
        gotoXY(mX, mY + 2); cout << "      ";
        return;
    }
    else if(mY > 11){
        textColor(159);
    }
    else if(mY == 10){
        textColor(15);
        gotoXY(mX, mY); cout << "      ";
        textColor(159);
        gotoXY(mX, mY + 1); cout << "      ";
        gotoXY(mX, mY + 2); cout << "      ";
        return;
    }
    else if(mY > 5){
        textColor(15);
    }
    else if(mY == 4){
        textColor(47);
        gotoXY(mX, mY); cout << "      ";
        textColor(15);
        gotoXY(mX, mY + 1); cout << "      ";
        gotoXY(mX, mY + 2); cout << "      ";
        return;
    }
    else if(mY >= 0){
        textColor(47);
    }

    gotoXY(mX, mY); cout << "      ";
    gotoXY(mX, mY + 1); cout << "      ";
    gotoXY(mX, mY + 2); cout << "      ";
}

void CPEOPLE::Up(int step){
    mY=max(mY-step*velocity,topBorder);
}

void CPEOPLE::Left(int step){
    mX= max(mX-step*velocity,leftBorder);
}

void CPEOPLE::Right(int step){
    mX=min(mX+step*velocity,rightBorder-width);
}

void CPEOPLE::Down(int step){
    mY=min(mY+step*velocity,botBorder);
}

bool CPEOPLE::isFinish(){
    return mY<=yFinish;
}

bool CPEOPLE::isDead(){
    return HP==0;
}

int CPEOPLE::isImpact(vector<LANE*> lanes){
    for (auto lane:lanes){
        vector<OBSTACLE*> obstacles=lane->getObstacles();
        for (auto obj:obstacles){
            int objLeftbound=obj->getPosX();
            int objRightbound=objLeftbound+obj->getWidth();
            
            int objLowerbound=obj->getPosY();
            int objUpperbound=objLowerbound+obj->getHeight();

            if (((objLowerbound<mY && mY<objUpperbound) || (objLowerbound<mY+height && mY+height<objUpperbound)) &&
                ((objLeftbound<mX && mX<objRightbound) || (objLeftbound<mX+width && mX+width<objRightbound))) return obj->getDamage();
        }
    }
    return 0;
}

void CPEOPLE::setHP(int num)
{
    HP=max(0,HP-num);
}
void CPEOPLE::save(ofstream &ofs)
{
    ofs<<mX<<" "<<mY<<endl;
    ofs<<HP<<endl;
    ofs<<mState<<endl;
    ofs<<yFinish;
}
string CPEOPLE::getName(){
    return name;
}
void CPEOPLE::load(ifstream &ifs)
{
    ifs>>mX>>mY;
    ifs>>HP;
    ifs>>mState;
    ifs>>yFinish;
}