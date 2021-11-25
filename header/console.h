#ifndef consoleh
#define consoleh
#include "header.h"
void fixConsoleWindow();
void setConsoleWindow(int w, int h);
int wherex();
int wherey();
void gotoXY(int column, int line);
void textColor(int color);
void clrscr();
void hidePointer();
void unhidePointer();
void boardGame();
void drawDinasour(int offset, int x, int y, bool isReverse);
void drawBird(int offset, int x, int y, bool isReverse);
void drawCar(int offset, int x, int y, bool isReverse);
void drawTruck(int offset, int x, int y, bool isReverse);
void drawDuck(int offset, int x, int y, bool isReverse);
bool isInConsoleWidth(int y);
void clear(int offset, bool isReverse, int height, int width, int x, int y);
void clear_all(int offset, int height, int width, int x, int y);
#endif