#ifndef consoleh
#define consoleh
#include "header.h"
void fixConsoleWindow();
void setConsoleWindow(int w, int h);
int wherex();
int wherey();
void gotoXY(int column, int line);
void Textcolor(int color);
void clrscr();
void hidePointer();
void unhidePointer();
#endif