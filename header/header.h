#ifndef headerh
#define headerh
//Library
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
//Local header file
#include "config.h"
#include "console.h"
#include "ctraffic.h"
#include "cobstacle.h"
#include "canimal.h"
#include "cvehicle.h"
#include "cpeople.h"
#include "clane.h"
#include "cgame.h"
#include "menu.h"
	
using namespace std;

char MOVING;
CGAME g;
bool IS_RUNNING=1;

void SubThread();

#endif 