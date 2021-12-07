#ifndef canimalh
#define canimalh
#include "header.h"

using namespace std;

class CDINOSAUR: public OBSTACLE{
public:
	static const int height = 3;
    static const int width = 7;

	CDINOSAUR(int x = 0, int y = 0, bool isReverse = false, int damage=5);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
};

class CBIRD: public OBSTACLE{
private:
    int frames;
    vector<string*> visuals;
public:
	static const int height = 3;
    static const int width = 7;

	CBIRD(int x = 0, int y = 0, bool isReverse = false,int damage=2);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
	~CBIRD();
};

class CDUCK: public OBSTACLE{
private:
    int frames;
    vector<string*> visuals;
public:
	static const int height = 3;
    static const int width = 7;

	CDUCK(int x = 0, int y = 0, bool isReverse = false,int damage=2);
	OBSTACLE* create(int x = 0, int y = 0, bool isReverse = false);
	void draw(const int &offset);
	void clear(const int &offset);
	//void Tell();
	~CDUCK();
};

#endif 