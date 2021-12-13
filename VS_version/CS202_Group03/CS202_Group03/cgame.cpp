#include "header.h"

CGAME::CGAME(){
    
    // cn = new CPEOPLE(60,26);
    
}
void CGAME::initiateEasy()
{
    traffic = new cTraffic();
    OBSTACLE* duck = new CDUCK();
    OBSTACLE* bird = new CBIRD();
    OBSTACLE* dinosaur = new CDINOSAUR();

    lanes.emplace_back(new LANE(bird, 21, 20, 8, 0));
    lanes.emplace_back(new LANE(dinosaur, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(duck, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(bird, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(dinosaur, 1, 20, 2, 1));


    delete duck;
    delete bird;
    delete dinosaur;
}
void CGAME::initiateMedium()
{
    traffic = new cTraffic();
    OBSTACLE* truck = new CTRUCK();
    OBSTACLE* car = new CCAR();
    OBSTACLE* duck = new CDUCK();
    OBSTACLE* bird = new CBIRD();
    OBSTACLE* dinosaur = new CDINOSAUR();

    lanes.emplace_back(new LANE(duck, 21, 20, 8, 0));
    lanes.emplace_back(new LANE(dinosaur, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(bird, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(car, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(truck, 1, 20, 2, 1));

    delete truck;
    delete car;
    delete duck;
    delete bird;
    delete dinosaur;
}
void CGAME::initiateHard()
{
    traffic = new cTraffic();
    OBSTACLE* truck = new CTRUCK();
    OBSTACLE* car = new CCAR();


    lanes.emplace_back(new LANE(truck, 21, 20, 8, 0));
    lanes.emplace_back(new LANE(car, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(truck, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(car, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(truck, 1, 20, 2, 1));

    delete truck;
    delete car;

}
CGAME::~CGAME(){
    
}

void CGAME::moveObstacles(){
    traffic->updateTime(-10000);
    if (traffic->getStatus() == false)
    {
        for (LANE*& lane : lanes)
            lane->move();
    }
}

CPEOPLE CGAME::getPeople(){
    return *cn;
}

bool CGAME::updatePeople(std::chrono::high_resolution_clock::time_point &start){
    char c;
    
    
    if (_kbhit())
    {
        cn->clear();
        c=toupper(_getch());
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
        case 'P':
            return true;
            break;
        default:
            break;
        }
        cn->draw();
    }
    
    int dmg=getPeople().isImpact(getLanes());
    if (dmg)
    {
        cn->draw();
        if (!freeze)
        {
            cn->setHP(dmg);
            freezing(start);
        }
    }
    if (freeze)
        freezing(start);
    return false;
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
void CGAME::activateTraffic(std::chrono::high_resolution_clock::time_point &start){
    auto stop=high_resolution_clock::now();
    auto during=duration_cast<seconds>(stop - start);
    if (during.count()==1)
    {
        traffic->updateTime(traffic_stop);
        start=high_resolution_clock::now();
    }
}
void CGAME::saveGame(){
    saveGameMenu();
    string choice;
    cin>>choice;
    while (choice!="y"&&choice!="n")
    {
        saveGameMenu();
        cin>>choice;
    }
    if (choice=="n") return;
    ofstream ofs(dataroot+cn->getName()+".txt");
    ofs<<level<<endl;
    cn->save(ofs);
    ofs.close();
}
void CGAME::loadGame(){
    loadGameMenu();
    string name;
    // ifstream ifs(dataroot+name+".txt");
    ifstream ifs(dataroot+".txt");
    ifs>>level;
    cn=new CPEOPLE;
    cn->load(ifs);
    ifs.close();
}
void CGAME::newGame(){ 
    newGameMenu();
    string name;
    cin.ignore();
    getline(cin,name,'\n');
    cn=new CPEOPLE(name,60,26);
}
void CGAME::startGame(){
    system("cls");
    initiateEasy();
    boardGame();
    cn->draw();
    std::chrono::high_resolution_clock::time_point start;
    while (!getPeople().isDead() && !getPeople().isFinish()){      
        moveObstacles();
        bool exitChoice=updatePeople(start);
        if (exitChoice)
            if (pauseGame())
                return;
            else
                boardGame();
    }
}
bool CGAME::pauseGame(){
    pauseMenu();
    string choice;
    cin>>choice;
    while (choice!="y"&&choice!="n")
    {
        pauseMenu();
        cin>>choice;
    }
    if (choice=="n") return false;
    saveGame();
    return true;
}