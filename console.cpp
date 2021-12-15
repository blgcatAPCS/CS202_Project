#include "header/header.h"
void fixConsoleWindow() 
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void setConsoleWindow(int w, int h)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, w, h, TRUE);
}
int wherex()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}
int wherey()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
    HANDLE	hConsoleOut;
    COORD	Home = { 0,0 };
    DWORD	dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void hidePointer()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
} 
void unhidePointer()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void boardGameEasy(){
    gotoXY(0,0);

    textColor(34);
    for (int i = 0; i < (120 * 10); ++i)
        cout << ".";

    textColor(153);
    for(int i = 0; i < (120* 6); ++i)
        cout << ".";

    textColor(34);
    for (int i = 0; i < (120 * 4); ++i)
        cout << ".";
    
    textColor(153);
    for(int i = 0; i < (120* 5); ++i)
        cout << ".";

    //border
    textColor(0);
    gotoXY(5, 29);
    cout << char(219);

    gotoXY(5, 28);
    cout << char(219);

    gotoXY(8, 29);
    cout << char(219);
    
    gotoXY(8, 28);
    cout << char(219);

    textColor(224);
    gotoXY(5, 27);
    cout << char(220);

    gotoXY(6, 27);
    cout << char(220);

    gotoXY(7, 27);
    cout << char(220);

    gotoXY(8, 27);
    cout << char(220);

    textColor(254);
    for(int i = 0; i < 2; ++i){
        gotoXY(6 + i, 28);
        cout << char(219);
    }
    textColor(170);
    for(int i = 0; i < 2; ++i){
        gotoXY(6 + i, 29);
        cout << char(219);
    }

    textColor(224);
}

void boardGameMedium(){
    gotoXY(0,0);

    textColor(0);
    for (int i = 0; i < (120 * 11); ++i)
        cout << ".";

    textColor(34);
    for(int i = 0; i < (120* 10); ++i)
        cout << ".";

    textColor(153);
    for (int i = 0; i < (120 * 5); ++i)
        cout << ".";

    //border
    textColor(0);
    gotoXY(5, 29);
    cout << char(219);

    gotoXY(5, 28);
    cout << char(219);

    gotoXY(8, 29);
    cout << char(219);
    
    gotoXY(8, 28);
    cout << char(219);

    textColor(224);
    gotoXY(5, 27);
    cout << char(220);

    gotoXY(6, 27);
    cout << char(220);

    gotoXY(7, 27);
    cout << char(220);

    gotoXY(8, 27);
    cout << char(220);

    textColor(254);
    for(int i = 0; i < 2; ++i){
        gotoXY(6 + i, 28);
        cout << char(219);
    }
    textColor(170);
    for(int i = 0; i < 2; ++i){
        gotoXY(6 + i, 29);
        cout << char(219);
    }

    textColor(224);
}

void boardGameHard() {
    gotoXY(0,0);

    textColor(34);
    for (int i = 0; i < (120 * 5); ++i)
        cout << ".";

    textColor(0);
    for(int i = 0; i < (120* 16); ++i)
        cout << ".";

    textColor(34);
    for (int i = 0; i < (120 * 5); ++i)
        cout << ".";

    //border
    textColor(0);
    gotoXY(5, 29);
    cout << char(219);

    gotoXY(5, 28);
    cout << char(219);

    gotoXY(8, 29);
    cout << char(219);
    
    gotoXY(8, 28);
    cout << char(219);

    textColor(224);
    gotoXY(5, 27);
    cout << char(220);

    gotoXY(6, 27);
    cout << char(220);

    gotoXY(7, 27);
    cout << char(220);

    gotoXY(8, 27);
    cout << char(220);

    textColor(254);
    for(int i = 0; i < 2; ++i){
        gotoXY(6 + i, 28);
        cout << char(219);
    }
    textColor(170);
    for(int i = 0; i < 2; ++i){
        gotoXY(6 + i, 29);
        cout << char(219);
    }

    textColor(224);
}

bool isInConsoleWidth(int x) {
    return 0 <= x && x < consoleWidth;
}