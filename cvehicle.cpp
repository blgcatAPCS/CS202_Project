#include "header/header.h"

cPosition CVEHICLE::getPos()
{
    return point;
}
int CVEHICLE::getX()
{
    return point.getX();
}
int CVEHICLE::getY()
{
    return point.getY();
}
CVEHICLE::CVEHICLE() : outMap(false)
{

}
CVEHICLE::CVEHICLE(cPosition po) : point(po), outMap(false)
{

}
void CVEHICLE::updatePosition(int dx, int dy)
{
    point.setPos(point.getX()+dx, point.getY()+dy);
}
bool CVEHICLE::isOutOfMap()
{
    return outMap;
}
void CVEHICLE::goOutMap()
{
    outMap = true;
}
int CVEHICLE::getWidth()
{
    return 11;
}
int CVEHICLE::getHeight()
{
    return 4;
}
void CVEHICLE::draw(int offset, int x, int y, bool isReverse)
{

}

void CTRUCK::draw(int offset, int x, int y, bool isReverse)
{
    drawTruck(offset, x, y, isReverse);
}
int CTRUCK::getHeight()
{
    return 4;
}
int CTRUCK::getWidth()
{
    return 16;
}
int CTRUCK::getType()
{
    return 4;
}
CTRUCK::~CTRUCK()
{

}

void CCAR::draw(int offset, int x, int y, bool isReverse)
{
    drawCar(offset, x, y, isReverse);
}
int CCAR::getHeight()
{
    return 4;
}
int CCAR::getWidth()
{
    return 11;
}
int CCAR::getType()
{
    return 1;
}
CCAR::~CCAR()
{
    
}