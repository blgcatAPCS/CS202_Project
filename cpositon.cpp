#include "header/header.h"

int cPosition::getX()
{
	return X;
}
int cPosition::getY()
{
	return Y;
}
cPosition::cPosition()
{

}
cPosition::cPosition(const int x, const int y)
{
    X = x;
	Y = y;
}
void cPosition::setPos(int x, int y)
{
    this->X = x;
    this->Y = y;
}
cPosition::~cPosition()
{
    
}