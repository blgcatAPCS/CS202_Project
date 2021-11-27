#include "header/header.h"

CGAME::CGAME(){
    cn = new CPEOPLE(60,26);
    OBSTACLE* truck = new CTRUCK();
    OBSTACLE* car = new CCAR();
    OBSTACLE* duck = new CDUCK();
    OBSTACLE* bird = new CBIRD();
    OBSTACLE* dinosaur = new CDINOSAUR();

    lanes.emplace_back(new LANE(truck, 21, 20, 1000000, 0));
    lanes.emplace_back(new LANE(car, 6, 20, 700000, 1));
    lanes.emplace_back(new LANE(duck, 11, 20, 1000000, 0));
    lanes.emplace_back(new LANE(bird, 16, 20, 900000, 1));
    lanes.emplace_back(new LANE(dinosaur, 1, 20, 3000000, 1));

    delete truck;
    delete car;
    delete duck;
    delete bird;
    delete dinosaur;
}

CGAME::~CGAME(){
    
}

void CGAME::moveObstacles(){
    for (LANE*& lane : lanes)
        lane -> move();
}