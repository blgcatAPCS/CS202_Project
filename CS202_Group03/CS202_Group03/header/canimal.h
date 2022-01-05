#ifndef canimalh
#define canimalh
#include "header.h"

using namespace std;

class CDINOSAUR: public OBSTACLE{
public:
	static const int height = 3;
    static const int width = 7;
	static const int damage = 5;

	void sound() { Dinosaur(); };
	CDINOSAUR(int x = 0, int y = 0, bool isReverse = false);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();

	int getColor();
};

class CBIRD: public OBSTACLE{
private:
    int frames;
    vector<string*> visuals;
public:
	static const int height = 3;
    static const int width = 7;
	static const int damage = 2;

	void sound() { Bird(); };
	CBIRD(int x = 0, int y = 0, bool isReverse = false);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
	~CBIRD();

	int getColor();
};

class CDUCK: public OBSTACLE{
private:
    int frames;
    vector<string*> visuals;
public:
	static const int height = 3;
    static const int width = 7;
	static const int damage = 2;

	void sound() { Duck(); };
	CDUCK(int x = 0, int y = 0, bool isReverse = false);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
	~CDUCK();

	int getColor();
};

#endif 