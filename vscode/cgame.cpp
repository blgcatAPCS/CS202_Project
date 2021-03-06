#include "header/header.h"

CGAME::CGAME(){
    
    // cn = new CPEOPLE(60,26);
    
}
void CGAME::initiateHard()
{
    traffic = new cTraffic();
    OBSTACLE* truck = new CTRUCK();
    OBSTACLE* car = new CCAR();
    // OBSTACLE* duck = new CDUCK();
    // OBSTACLE* bird = new CBIRD();
    OBSTACLE* dinosaur = new CDINOSAUR();

    lanes.emplace_back(new LANE(dinosaur, 21, 20, 8, 0));
    lanes.emplace_back(new LANE(car, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(truck, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(car, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(dinosaur, 1, 20, 2, 1));

    delete truck;
    delete car;
    // delete duck;
    // delete bird;
    delete dinosaur;
}
void CGAME::initiateEasy()
{
    traffic = new cTraffic();
    // OBSTACLE* truck = new CTRUCK();
    // OBSTACLE* car = new CCAR();
    OBSTACLE* duck = new CDUCK();
    OBSTACLE* bird = new CBIRD();
    OBSTACLE* dinosaur = new CDINOSAUR();

    lanes.emplace_back(new LANE(duck, 21, 20, 8, 0));
    lanes.emplace_back(new LANE(dinosaur, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(duck, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(bird, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(dinosaur, 1, 20, 2, 1));

    // delete truck;
    // delete car;
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
    lanes.emplace_back(new LANE(car, 6, 20, 3, 1));
    lanes.emplace_back(new LANE(dinosaur, 11, 20, 8, 0));
    lanes.emplace_back(new LANE(bird, 16, 20, 10, 1));
    lanes.emplace_back(new LANE(truck, 1, 20, 2, 1));

    delete truck;
    delete car;
    delete duck;
    delete bird;
    delete dinosaur;
}

CGAME::~CGAME(){
    terminate(1);
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
    cn->draw(lanes);

    char c;
   
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
    }
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

    if (!checkNameIsExist(cn->getName())){
        ofstream f(dataroot+dataFile,ios::app);
        f<<cn->getName()<<endl;
        f.close();
    }

    ofstream ofs(dataroot+cn->getName()+".txt",ios::trunc);
    ofs<<level<<endl;
    cn->save(ofs);
    ofs.close();
}
void CGAME::loadGame(){
    loadGameMenu();
    terminate(1);
    string name=getSaveGame(getSaveNames());
    // ifstream ifs(dataroot+name+".txt");
    ifstream ifs(dataroot+name+".txt");
    ifs>>level;
    cn=new CPEOPLE(name);
    cn->load(ifs);
    ifs.close();
}
void CGAME::newGame(){ 
    vector<string> names=getSaveNames();
    string name;
    while (1){
        clear();
        newGameMenu();
        fflush(stdin);
        getline(cin,name);
        if (checkNameIsExist(name)){
            gotoXY(25,15);
            if (name=="dataFile"){
                cout << "This name is invalid! Press any key to get another one.";
                _getch();
            }
            else {
                cout << "This name is already created!";
                gotoXY(25,16);
                cout << "Do you want to keep this name? (we will override save file if you keep this) (y/n):";
                char choice;
                cin >> choice;
                if (choice=='y') break;                
            }
        }
        else break;
    }
    // cin.ignore();
    cn=new CPEOPLE(name,60,26);
    // level=1;
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
    
    saveGame();
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
    if (deleteCPEOPLE){
        delete cn;
        cn=0;
    }
    delete traffic;
    traffic=0;
}