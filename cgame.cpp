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
<<<<<<< Updated upstream
    
=======
    terminate(1);
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
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
=======
bool CGAME::updatePeople(std::chrono::high_resolution_clock::time_point &start){
    char c;
    
    
    if (_kbhit())
    {
        cn->clear(lanes);
        c=toupper(getch());
        switch (c){
        case 'A':
            cn->Left(1);
            break;

        case 'W':
            cn->Up(1);
            break;

        case 'D':
            cn->Right(1);
            break;

        case 'S':
            cn->Down(1);
            break;

        case 'P':
            return true;
            break;

        default:
            break;
        }
        cn->draw(lanes);
    }
    
    int dmg=getPeople().isImpact(getLanes());
    if (dmg)
    {
        cn->draw(lanes);
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
>>>>>>> Stashed changes

    case 'D':
        cn->Right(1);
        break;

    default:
        break;
    }

<<<<<<< Updated upstream
    cn->draw();
}

vector<LANE*> CGAME::getLanes(){
    return lanes;
=======
    
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
    ofstream f(dataroot+dataFile,ios::app);
    f<<cn->getName()<<endl;
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
    getline(cin,name,'\n');
    // cin.ignore();
    cn=new CPEOPLE(name,60,26);
}
void CGAME::startGame(){
    while (!getPeople().isDead() && level<=3){
        textColor(0);
        system("cls");
        terminate(0);
        cn->resetPos();
        switch (level)
        {
        case 1:
            initiateEasy();
            break;

        case 2:
            initiateMedium();
            break;

        case 3:
            initiateHard();
            break;
        
        default:
            return;
        }
        boardGame(lanes);
        cn->draw(lanes);
        std::chrono::high_resolution_clock::time_point start;

        while (!getPeople().isDead() && !getPeople().isFinish()){
            moveObstacles();
            bool exitChoice=updatePeople(start);
            if (exitChoice)
                if (pauseGame())
                    return;
                else
                    boardGame(lanes);
        }

        level+=!(getPeople().isDead());
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

void CGAME::terminate(bool deleteCPEOPLE){
    lanes.clear();
    if (deleteCPEOPLE) delete cn;
    delete traffic;
>>>>>>> Stashed changes
}