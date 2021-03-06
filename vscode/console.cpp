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

void boardGame(vector<LANE*> lanes) {
    textColor(0);
    system("cls");

    for (auto lane : lanes){
        OBSTACLE* obs=lane->getObstacles()[0];
        textColor(obs->getColor());
        gotoXY(0,obs->getPosY());
        for (int i=0;i<120*obs->getHeight();++i){
            cout << " ";
        }
    }

    //draw bottom
    textColor(224);
    gotoXY(0,26);
    for (int i=0;i<consoleWidth*(consoleHeight-26);++i){
        cout << " ";
    }

    //grass
    // gotoXY(0,0);
    // textColor(34);
    // for (int i = 0; i < (120 * 5); ++i) {
    //     cout << ".";
    // }

    // //road
    // textColor(0);
    // for (int i = 0; i < (120 * 6); ++i) {
    //     cout << ".";
    // }

    // //water
    // textColor(153);
    // for (int i = 0; i < (120 * 4); ++i) {
    //     cout << ".";
    // }

    // //grass
    // textColor(34);
    // for (int i = 0; i < (120 * 5); ++i) {
    //     cout << ".";
    // }
    
    // //road
    // textColor(0);
    // for (int i = 0; i < (120 * 6); ++i) {
    //     cout << ".";
    // }

    // //grass
    // textColor(238);
    // for (int i = 0; i < (120 * 4); ++i) {
    //     cout << ".";
    // }

    //startLine


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

//offset is the deviation from the original position
void drawDinosaur(int offset, int x, int y, bool isReverse){
    int height = 3;
    int width = 7;
    string* visual;
    
    //if the dinasour goes from Right -> Left = !isReverse
    //else isReverse
    if (!isReverse) {
        visual = new string[height]{
        {' ', ' ', ' ', ' ', char(219), char(219), char(223)},
        {' ', ' ', char(220), char(219), char(219), char(219), char(238)},
        {char(196), char(223), char(223), char(219), char(223), char(219)}
        };
    }
    else {
        visual = new string[height]{
            {char(223), char(219), char(219), ' ', ' ', ' ', ' '},
            {char(238), char(219), char(219), char(219), char(220), ' ', ' '},
            {' ', char(219), char(223), char(219), char(223), char(223), char(196)}
        };
    }

    if (x + offset >= consoleWidth)
        return;

    for (int i = 0; i < height; ++i) {
        gotoXY(max(x + offset, 0), y + i);

        for (int j = max(-x - offset, 0); j < width && x + offset + j < consoleWidth; ++j) {
            cout << visual[i][j];
        }
    }
}

void drawBird(int offset, int x, int y, bool isReverse){
    int height = 3;
    int width = 7;
    int frames, start;
    vector<string*> visuals;
    //if the bird goes from Right -> Left = !isReverse
    //else isReverse
    if (!isReverse) {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        " ___   ",
        "/__o\\_ ",
        "\\___/-'"
        };

        visuals[1] = new string[height]{
        " ___   ",
        "//\\o\\_ ",
        "\\___/-'"
        };

        visuals[2] = new string[height]{
        " ___   ",
        "/__o\\_ ",
        "\\___/-'"
        };
    }
    else {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        "   ___ ",
        " _/o__\\",
        "'-\\___/"
        };

        visuals[1] = new string[height]{
        "   ___ ",
        " _/o/\\\\",
        "'-\\___/"
        };

        visuals[2] = new string[height]{
        "   ___ ",
        " _/o__\\",
        "'-\\___/"
        };
    }

    string* visual = visuals[(abs(offset)) % frames];

    if (x + offset >= consoleWidth)
        return;

    for (int i = 0; i < height; ++i) {
        gotoXY(max(x + offset, 0), y + i);

        for (int j = max(-x - offset, 0); j < width && x + offset + j < consoleWidth; ++j) {
            cout << visual[i][j];
        }
    }
}

void drawCar(int offset, int x, int y, bool isReverse){
    int height = 4;
    int width = 11;
    int frames, start;
    vector<string*> visuals;
    //if the car goes from Right -> Left = !isReverse
    //else isReverse
    if (!isReverse) {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        "   _____   ",
        " ./ [ ]L\\_ ",
        "[''''\\|  =\\",
        " \"(x)--(x)\""
        };

        visuals[1] = new string[height]{
        "   _____   ",
        " ./ [ ]L\\_ ",
        "[''''\\|  =\\",
        " \"(+)--(+)\""
        };

        visuals[2] = new string[height]{
        "   _____   ",
        " ./ [ ]L\\_ ",
        "[''''\\|  =\\",
        " \"(x)--(x)\""
        };
    }
    else {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        "   _____   ",
        {' ', '_', '/', char(217), '[',' ' ,']', ' ', '\\','.', ' '},
        "/=  |/'''']",
        "\"(x)--(x)\" "
        };

        visuals[1] = new string[height]{
        "   _____   ",
        {' ', '_', '/', char(217), '[',' ' ,']', ' ', '\\','.', ' '},
        "/=  |/'''']",
        "\"(+)--(+)\" "
        };

        visuals[2] = new string[height]{
        "   _____   ",
        {' ', '_', '/', char(217), '[',' ' ,']', ' ', '\\','.', ' '},
        "/=  |/'''']",
        "\"(x)--(x)\" "
        };
    }

    string* visual = visuals[(abs(offset)) % frames];

    if (x + offset >= consoleWidth)
        return;

    for (int i = 0; i < height; ++i) {
        gotoXY(max(x + offset, 0), y + i);

        for (int j = max(-x - offset, 0); j < width && x + offset + j < consoleWidth; ++j) {
            cout << visual[i][j];
        }
    }
}

void drawTruck(int offset, int x, int y, bool isReverse){
    int height = 4;
    int width = 16;
    int frames, start;
    vector<string*> visuals;
    //if the truck goes from Right -> Left = !isReverse
    //else isReverse
    if (!isReverse) {
        frames = 3;
        visuals.assign(frames, nullptr);
        
        visuals[0] = new string[height]{
        "        ______  ",
        " ______||__||_\\ ",
        "| - - -| _,= + ]",
        " ``(@)-----(@)``"
        };

        visuals[1] = new string[height]{
        "        ______  ",
        " ______||__||_\\ ",
        "| - - -| _,= + ]",
        " ``(0)-----(0)``"
        };

        visuals[2] = new string[height]{
        "        ______  ",
        " ______||__||_\\ ",
        "| - - -| _,= + ]",
        " ``(@)-----(@)``"
        };
        
    }
    else {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        "  ______        ",
        " /_||__||______ ",
        "[ + =,_ |- - - |",
        " ``(@)-----(@)``"
        };

        visuals[1] = new string[height]{
        "  ______        ",
        " /_||__||______ ",
        "[ + =,_ |- - - |",
        " ``(0)-----(0)``"
        };

        visuals[2] = new string[height]{
        "  ______        ",
        " /_||__||______ ",
        "[ + =,_ |- - - |",
        " ``(@)-----(@)``"
        };
    }

    string* visual = visuals[(abs(offset)) % frames];

    if (x + offset >= consoleWidth)
        return;

    for (int i = 0; i < height; ++i) {
        gotoXY(max(x + offset, 0), y + i);

        for (int j = max(-x - offset, 0); j < width && x + offset + j < consoleWidth; ++j) {
            cout << visual[i][j];
        }
    }
}

void drawDuck(int offset, int x, int y, bool isReverse) {
    int height = 3;
    int width = 7;
    int frames, start;
    vector<string*> visuals;
    //if the dinasour goes from Right -> Left = !isReverse
    //else isReverse
    if (!isReverse) {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        "    _  ",
        " __(o)=",
        "\\____) "
        };

        visuals[1] = new string[height]{
        "    _  ",
        " __(*)>",
        "\\____) "
        };

        visuals[2] = new string[height]{
        "    _  ",
        " __(o)<",
        "\\____) "
        };
    }
    else {
        frames = 3;
        visuals.assign(frames, nullptr);

        visuals[0] = new string[height]{
        "  _    ",
        "=(o)__ ",
        " (____/"
        };

        visuals[1] = new string[height]{
        "  _    ",
        "<(o)__ ",
        " (____/"
        };

        visuals[2] = new string[height]{
        "  _    ",
        ">(o)__ ",
        " (____/"
        };
    }

    string* visual = visuals[(abs(offset)) % frames];

    if (x + offset >= consoleWidth)
        return;

    for (int i = 0; i < height; ++i) {
        gotoXY(max(x + offset, 0), y + i);

        for (int j = max(-x - offset, 0); j < width && x + offset + j < consoleWidth; ++j) {
            cout << visual[i][j];
        }
    }
}

bool isInConsoleWidth(int x) {
    return 0 <= x && x < consoleWidth;
}

//clear each column - not clear full object
//as when u move the car toward 1 unit
//the last column of the past car must be deleted and rewrite the object
void clear(int offset, bool isReverse, int height, int width, int x, int y) {
    if (!isReverse) {
        if (isInConsoleWidth(y + offset)) {
            for (int i = 0; i < height; ++i) {
                gotoXY(x + offset, y + i);
                cout << ' ';
            }
        }
    }
    else {
        if (isInConsoleWidth(y + offset + width - 1)) {
            for (int i = 0; i < height; ++i) {
                gotoXY(x + offset + width - 1, y + i);
                cout << ' ';
            }
        }
    }
}

void clear_all(int offset, int height, int width, int x, int y){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            gotoXY(x + offset + j, y + i);
            cout << ' ';
        }
    }
}