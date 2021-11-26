#include "header/header.h"


OBSTACLE::OBSTACLE(int x, int y, bool isReverse, int height, int width )
: x(x), y(y), isReverse(isReverse), height(height), width(width), visual(nullptr) {

}

OBSTACLE:: ~OBSTACLE() {
    if (visual) delete[] visual;
}

int OBSTACLE::getWidth() { 
    return width; 
}

int OBSTACLE::getHeight() {
    return height;
}

void OBSTACLE::clear(const int& offset){
    if (!isReverse) {
        if (isInConsoleWidth(x + offset)) {
            for (int i = 0; i < height; ++i) {
                gotoXY(x + offset, y + i);
                cout << ' ';
            }
        }
    }
    else {
        if (isInConsoleWidth(x + offset + width - 1)) {
            for (int i = 0; i < height; ++i) {
                gotoXY(x + offset + width - 1, y + i);
                cout << ' ';
            }
        }
    }
}

void OBSTACLE::draw(const int &offset){
    if (x + offset >= consoleWidth)
        return;

    for (int i = 0; i < height; ++i) {
        gotoXY(max(x + offset, 0), y + i);

        for (int j = max(-x - offset, 0); j < width && x + offset + j < consoleWidth; ++j) {
            cout << visual[i][j];
        }
    }
}