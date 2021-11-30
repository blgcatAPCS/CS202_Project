#include "header/header.h"

CGAME::CGAME(){
    cn = new CPEOPLE(60,26);
    traffic = new cTraffic();
    OBSTACLE* truck = new CTRUCK();
    OBSTACLE* car = new CCAR();
    OBSTACLE* duck = new CDUCK();
    OBSTACLE* bird = new CBIRD();
    OBSTACLE* dinosaur = new CDINOSAUR();

    lanes.emplace_back(new LANE(truck, 21, 20, 8, 0));
    lanes.emplace_back(new LANE(car, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(duck, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(bird, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(dinosaur, 1, 20, 2, 1));

    delete truck;
    delete car;
    delete duck;
    delete bird;
    delete dinosaur;
}

CGAME::~CGAME(){
    
}

void CGAME::moveObstacles(){
    traffic->updateTime(1000000);
    if (traffic->getStatus() == false)
    {
        for (LANE*& lane : lanes)
            lane->move();
    }
}

CPEOPLE CGAME::getPeople(){
    return *cn;
}

void CGAME::updatePosPeople(char c){
    cn->clear();
    c=toupper(c);
    switch (c){
    case 'A':
        cn->Left(1);
        break;

    case 'W':
        cn->Up(1);
        break;
    
    case 'S':
        cn->Down(1);
        break;

    case 'D':
        cn->Right(1);
        break;

    default:
        break;
    }

    cn->draw();
}

vector<LANE*> CGAME::getLanes(){
    return lanes;
}