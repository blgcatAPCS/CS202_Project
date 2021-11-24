#ifndef cPosition_h
#define cPosition_h

class cPosition {
private:
	int X, Y;
public:
	int getX();
	int getY();
	cPosition();
	cPosition(const int x, const int y);
	void setPos(int x, int y);
	~cPosition();

};


#endif // cPosition