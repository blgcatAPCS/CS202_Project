#ifndef cvehicleh
#define cvehicleh
#include "header.h"

using namespace std;

class CTRUCK: public OBSTACLE{
private:
    int frames;
    vector<string*> visuals;
public:
	static const int height = 4;
    static const int width = 16;
	void setDamage();
	CTRUCK(int x = 0, int y = 0, bool isReverse = false,int damage=0);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
	~CTRUCK();
};

class CCAR: public OBSTACLE{
private:
    int frames;
    vector<string*> visuals;
public:
	static const int height = 4;
    static const int width = 11;

	void setDamage();
	CCAR(int x = 0, int y = 0, bool isReverse = false,int damage=0);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
	~CCAR();
};
#endif