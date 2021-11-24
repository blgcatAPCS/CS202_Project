#include "header/header.h"

cPosition CANIMAL::getPos()
{
    return point;
}
int CANIMAL::getX()
{
    return point.getX();
}
int CANIMAL::getY()
{
    return point.getY();
}
CANIMAL::CANIMAL() : outMap(false)
{

}
CANIMAL::CANIMAL(cPosition po) : point(po), outMap(false)
{

}
void CANIMAL::updatePosition(int dx, int dy)
{
    point.setPos(point.getX()+dx, point.getY()+dy);
}
bool CANIMAL::isOutOfMap()
{
    return outMap;
}
void CANIMAL::goOutMap()
{
    outMap = true;
}
int CANIMAL::getWidth()
{
    return 7;
}
int CANIMAL::getHeight()
{
    return 3;
}
void CANIMAL::Tell()
{

}
void CANIMAL::draw(int offset, int x, int y, bool isReverse)
{

}

void CDINOSAUR::draw(int offset, int x, int y, bool isReverse)
{
    drawDinasour(offset, x, y, isReverse);
}
void CDINOSAUR::Tell()
{
    PlaySound ( TEXT ( ".mav" ) , NULL , SND_SYNC );
}
int CDINOSAUR::getHeight()
{
    return 3;
}
int CDINOSAUR::getWidth()
{
    return 7;
}
int CDINOSAUR::getType()
{
    return 2;
}
CDINOSAUR::~CDINOSAUR()
{

}

void CBIRD::draw(int offset, int x, int y, bool isReverse)
{
    drawBird(offset, x, y, isReverse);
}
void CBIRD::Tell()
{
    PlaySound ( TEXT ( ".mav" ) , NULL , SND_SYNC );
}
int CBIRD::getHeight()
{
    return 3;
}
int CBIRD::getWidth()
{
    return 7;
}
int CBIRD::getType()
{
    return 0;
}
CBIRD::~CBIRD()
{
    
}

void CDUCK::draw(int offset, int x, int y, bool isReverse)
{
    drawDuck(offset, x, y, isReverse);
}
void CDUCK::Tell()
{
    PlaySound ( TEXT ( ".mav" ) , NULL , SND_SYNC );
}
int CDUCK::getHeight()
{
    return 3;
}
int CDUCK::getWidth()
{
    return 7;
}
int CDUCK::getType()
{
    return 0;
}
CDUCK::~CDUCK()
{
    
}