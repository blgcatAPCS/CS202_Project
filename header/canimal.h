#ifndef canimalh
#define canimalh
#include "header.h"
class CANIMAL{
    cPosition point;
    bool outMap;
public:
    cPosition getPos();
	int getX();
	int getY();
	CANIMAL();
	CANIMAL(cPosition st); // create new enemy with starting position
	virtual ~CANIMAL() = default;
	virtual int getType() = 0;
	void updatePosition(int dx, int dy);
	bool isOutOfMap();
	void goOutMap();
	virtual int getWidth();
	virtual int getHeight();
    //virtual void Move(int, int); //speed and direction control
    virtual void Tell();
    virtual void draw(int offset, int x, int y, bool isReverse);
};
class CDINOSAUR: public CANIMAL{
public:
    void draw(int offset, int x, int y, bool isReverse);
	void Tell();
    int getHeight();
	int getWidth();
	int getType();
	~CDINOSAUR();
};
class CBIRD: public CANIMAL{
public:
    void draw(int offset, int x, int y, bool isReverse);
	void Tell();
    int getHeight();
	int getWidth();
	int getType();
	~CBIRD();
};
class CDUCK: public CANIMAL{
public:
	void draw(int offset, int x, int y, bool isReverse);
	void Tell();
    int getHeight();
	int getWidth();
	int getType();
	~CDUCK();
};
#endif 