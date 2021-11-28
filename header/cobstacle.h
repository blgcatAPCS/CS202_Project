#ifndef cobstacleh
#define cobstacleh

#include "header.h"

using namespace std;
class OBSTACLE{
protected:
    int x, y;
    bool isReverse;

    int height, width;
    string* visual;
public:
	OBSTACLE(int x = 0, int y = 0, bool isReverse = false, int height = 10, int width = 10);

	virtual ~OBSTACLE();

    virtual int getPosX();

    virtual int getPosY();

	virtual int getWidth();

    virtual int getHeight();

	virtual OBSTACLE* create(int x, int y, bool isReverse) = 0;

    //virtual void Move(int, int); //speed and direction control

    //virtual void Tell() = 0;

	virtual void clear(const int& offset);

    virtual void draw(const int &offset);
};

#endif