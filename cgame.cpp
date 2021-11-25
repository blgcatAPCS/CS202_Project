#include "header/header.h"

void CGAME::updatePosVehicle(int type, int y, int v, bool isReverse)
{
    if (type == 1)
    {
        if (isReverse == true)
        {
            int a = 119;
            while (a > 0)
            {
                drawCar(0, a, y, true);
                Sleep(100);
                clear_all(0, 4, 11, a, y);
                Sleep(100);
                a -= v;
            }
        }
        else
        {
            int a = 0;
            while (a <120)
            {
                drawCar(0, a, y, false);
                Sleep(100);
                clear_all(0, 4, 11, a, y);
                Sleep(100);
                a += v;
            }
        }
    }
    if (type == 4)
    {
        if (isReverse == true)
        {
            int a = 119;
            while (a > 0)
            {
                drawTruck(0, a, y, true);
                Sleep(100);
                clear_all(0, 4, 16, a, y);
                Sleep(100);
                a -= v;
            }
        }
        else
        {
            int a = 0;
            while (a <120)
            {
                drawTruck(0, a, y, false);
                Sleep(100);
                clear_all(0, 4, 16, a, y);
                Sleep(100);
                a += v;
            }
        }
    }
}

void CGAME::updatePosAnimal(int type, int y, int v, bool isReverse)
{
    if (type == 2)
    {
        if (isReverse == true)
        {
            int a = 119;
            while (a > 0)
            {
                drawDinosaur(0, a, y, true);
                Sleep(100);
                clear_all(0, 3, 7, a, y);
                Sleep(100);
                a -= v;
            }
        }
        else
        {
            int a = 0;
            while (a <120)
            {
                drawDinosaur(0, a, y, false);
                Sleep(100);
                clear_all(0, 3, 7, a, y);
                Sleep(100);
                a += v;
            }
        }
    }
    if (type == 0)
    {
        if (isReverse == true)
        {
            int a = 119;
            while (a > 0)
            {
                drawBird(0, a, y, true);
                Sleep(100);
                clear_all(0, 3, 7, a, y);
                Sleep(100);
                a -= v;
            }
        }
        else
        {
            int a = 0;
            while (a <120)
            {
                drawBird(0, a, y, false);
                Sleep(100);
                clear_all(0, 3, 7, a, y);
                Sleep(100);
                a += v;
            }
        }
    }
    if (type == 3)
    {
        if (isReverse == true)
        {
            int a = 119;
            while (a > 0)
            {
                drawDuck(0, a, y, true);
                Sleep(100);
                clear_all(0, 3, 7, a, y);
                Sleep(100);
                a -= v;
            }
        }
        else
        {
            int a = 0;
            while (a <120)
            {
                drawDuck(0, a, y, false);
                Sleep(100);
                clear_all(0, 3, 7, a, y);
                Sleep(100);
                a += v;
            }
        }
    }
}