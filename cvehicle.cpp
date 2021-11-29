#include "header/header.h"

CTRUCK::CTRUCK(int x, int y, bool isReverse)
: OBSTACLE(x, y, isReverse, height, width){
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
}

OBSTACLE* CTRUCK::create(int x, int y, bool isReverse){
    return new CTRUCK(x, y, isReverse);
}

void CTRUCK::draw(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(15);
    OBSTACLE::draw(offset);
}

void CTRUCK::clear(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(0);
    OBSTACLE::clear(offset);
}

CTRUCK::~CTRUCK(){
    for (string*& visual : visuals)
        delete[] visual;
}

CCAR::CCAR(int x, int y, bool isReverse)
: OBSTACLE(x, y, isReverse, height, width){
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
}

OBSTACLE* CCAR::create(int x, int y, bool isReverse){
    return new CCAR(x, y, isReverse);
}

void CCAR::draw(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(15);
    OBSTACLE::draw(offset);
}

void CCAR::clear(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(0);
    OBSTACLE::clear(offset);
}

CCAR::~CCAR(){
    for (string*& visual : visuals)
        delete[] visual;
}
