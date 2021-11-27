#ifndef ctraffich
#define ctraffich
#include "header.h"
#define MAX_TIME 15

class cTraffic
{
private:
	bool m_status; //red light when true
	int m_time;
public:
	cTraffic();
	bool getStatus();
	int getTime();
	void set(bool status, int time);
	void changeStatus();
	void updateTime();
};

#endif