#ifndef cvehicleh
#define cvehicleh
#include "header.h"
class CVEHICLE{
    cPosition point;
    bool outMap;
public:
    cPosition getPos();
	int getX();
	int getY();
	CVEHICLE();
	CVEHICLE(cPosition st); // create new enemy with starting position
	virtual ~CVEHICLE() = default;
	virtual int getType() = 0;
	void updatePosition(int dx, int dy);
	bool isOutOfMap();
	void goOutMap();
	virtual int getWidth();
	virtual int getHeight();
    //virtual void Move(int, int);
    virtual void draw(int offset, int x, int y, bool isReverse);
};
class CTRUCK: public CVEHICLE{
public:
    void draw(int offset, int x, int y, bool isReverse);
    int getHeight();
	int getWidth();
	int getType();
	~CTRUCK();
};
class CCAR: public CVEHICLE{
public:
    void draw(int offset, int x, int y, bool isReverse);
    int getHeight();
	int getWidth();
	int getType();
	~CCAR();
};
#endif