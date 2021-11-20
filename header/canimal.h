#ifndef canimalh
#define canimalh
#include "header.h"
class CANIMAL{
int mX, mY;
public:
    virtual void Move(int, int);
    virtual void Tell();
};
class CDINAUSOR: public CANIMAL{
public:
//...
};
class CBIRD: public CANIMAL{
public:
//...
};
#endif canimalh