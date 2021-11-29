#include "header/header.h"

CDINOSAUR::CDINOSAUR(int x, int y, bool isReverse)
: OBSTACLE(x, y, isReverse, height, width){
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
}

OBSTACLE* CDINOSAUR::create(int x, int y, bool isReverse){
    return new CDINOSAUR(x, y, isReverse);
}

void CDINOSAUR::draw(const int &offset){
    textColor(47);
    OBSTACLE::draw(offset);
}

void CDINOSAUR::clear(const int &offset){
    textColor(34);
    OBSTACLE::clear(offset);
}

CBIRD::CBIRD(int x, int y, bool isReverse)
: OBSTACLE(x, y, isReverse, height, width){
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
}

OBSTACLE* CBIRD::create(int x, int y, bool isReverse){
    return new CBIRD(x, y, isReverse);
}

void CBIRD::draw(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(47);
    OBSTACLE::draw(offset);
}

void CBIRD::clear(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(34);
    OBSTACLE::clear(offset);
}

CBIRD::~CBIRD(){
    for (string*& visual : visuals)
        delete[] visual;
}

CDUCK::CDUCK(int x, int y, bool isReverse)
: OBSTACLE(x, y, isReverse, height, width){
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
        " __(o)>",
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
}

OBSTACLE* CDUCK::create(int x, int y, bool isReverse){
    return new CDUCK(x, y, isReverse);
}

void CDUCK::draw(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(158);
    OBSTACLE::draw(offset);
}

void CDUCK::clear(const int &offset){
    visual = visuals[abs(offset) % frames];
    textColor(153);
    OBSTACLE::clear(offset);
}

CDUCK::~CDUCK(){
    for (string*& visual : visuals)
        delete[] visual;
}
