#ifndef cvehicleh
#define cvehicleh
#include "header.h"
class CVEHICLE{
    int mX, mY;
public:
    virtual void Move(int, int);
//...
};
class CTRUCK: public CVEHICLE{
public:
//...
};
class CCAR: public CVEHICLE{
public:
//...
};
#endif