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

void CGAME::updatePeople(std::chrono::high_resolution_clock::time_point &start){
    cn->clear();
    char c;
    if (_kbhit())
    {
        c=toupper(getch());
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
    }
    int dmg=getPeople().isImpact(getLanes());
    if (dmg)
    {
        if (!freeze)
        {
            cn->setHP(dmg);
            freezing(start);
        }
    }
    if (freeze)
        freezing(start);
    cn->draw();
}

vector<LANE*> CGAME::getLanes(){
    return lanes;
}

void CGAME::freezing(std::chrono::high_resolution_clock::time_point &start){
    if (!freeze) 
    {
        freeze=true;
        start = high_resolution_clock::now();
    }
    auto stop= high_resolution_clock::now();
    auto duration=duration_cast<seconds>(stop - start);
    if (duration.count()>3)
        freeze=false;

    
}
// void CGAME::activateTraffic(std::chrono::high_resolution_clock::time_point &start){
//     auto stop=high_resolution_clock::now();
//     auto during=duration_cast<seconds>(stop - start);
//     if (during.count()==1)
//     {
//         traffic->updateTime(traffic_stop);
//         start=high_resolution_clock::now();
//     }
// }
