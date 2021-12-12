#include "header.h"

void clear(){
    system("cls");
    textColor(255);
    gotoXY(0,0);
    for(int i = 0; i < 120*32; ++i){
        cout << ".";
    }
}

void drawMenu(int choice){
    textColor(241);
    system("cls");
    
    cout << "\n";
    cout << "\n";
    string title[6][23] = {
    {"  ","  ___  "," ","       "," ","       "," ","       "," ","       "," ","  _  _ "," ","       "," ","  ___  "," ","       "," ","       "," ","    _  "," \n"},
    {"  "," / __| "," ","   _ _ "," ","  ___  "," ","  ___  "," ","  ___  "," "," | || |"," ","  ___  "," "," | _ \\ "," ","  ___  "," "," __ _  "," "," __| | "," \n"},
    {"  ","| (__  "," ","  | '_|"," "," / _ \\ "," "," (_-<  "," "," (_-<  "," ","  \\_, |"," "," |___| "," "," |   / "," "," / _ \\ "," ","/ _` | "," ","/ _` | "," \n"},
    {"  "," \\___| "," "," _|_|_ "," "," \\___/ "," "," /__/_ "," "," /__/_ "," "," _|__/ "," "," _____ "," "," |_|_\\ "," "," \\___/ "," ","\\__,_| "," ","\\__,_| "," \n"},
    {" _","|\"\"\"\"\"|","_","|\"\"\"\"\"|","_","|\"\"\"\"\"|","_","|\"\"\"\"\"|","_","|\"\"\"\"\"|","_","| \"\"\"\"|","_","|     |","_","|\"\"\"\"\"|","_","|\"\"\"\"\"|","_","|\"\"\"\"\"|","_","|\"\"\"\"\"|"," \n"}, 
    {" \"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'","\"","`-0-0-'"," \n"}
    };
    
    for(int i = 0; i < 92; ++i){
        gotoXY(15 + i, 2);
        cout << (char) 220;
    }

    for(int i = 0; i < 6; ++i){
        gotoXY(15, 3 + i);
        cout << (char) 219;
    }

    for(int i = 0; i < 6; ++i){
        gotoXY(106, 3 + i);
        cout << (char) 219;
    }

    for(int i = 0; i < 92; ++i){
        gotoXY(15 + i, 9);
        cout << (char) 223;
    }

    for(int i = 0; i < 6; ++i){
        int y = 3 + i;
        gotoXY(16, y);

        textColor(240);
        cout << title[i][0];
        textColor(252);
        cout << title[i][1];

        textColor(240);
        cout << title[i][2];
        textColor(253);
        cout << title[i][3];

        textColor(240);
        cout << title[i][4];
        textColor(249);
        cout << title[i][5];

        textColor(240);
        cout << title[i][6];
        textColor(242);
        cout << title[i][7];

        textColor(240);
        cout << title[i][8];
        textColor(253);
        cout << title[i][9];

        textColor(240);
        cout << title[i][10];
        textColor(252);
        cout << title[i][11];

        textColor(240);
        cout << title[i][12];
        textColor(249);
        cout << title[i][13];

        textColor(240);
        cout << title[i][14];
        textColor(252);
        cout << title[i][15];

        textColor(240);
        cout << title[i][16];
        textColor(253);
        cout << title[i][17];

        textColor(240);
        cout << title[i][18];
        textColor(249);
        cout << title[i][19];

        textColor(240);
        cout << title[i][20];
        textColor(242);
        cout << title[i][21];

        textColor(240);
        cout << title[i][22];
    }

    textColor(241);
    if(choice != 0){
        gotoXY(56,15);
        cout << "NEW GAME" << endl;
    }
    else{
        string newGame[4] = {   
            "  _      ____  _           __     __    _      ____ ",
            " | |\\ | | |_  \\ \\    /    / /`_  / /\\  | |\\/| | |_  ",
            " |_| \\| |_|__  \\_\\/\\/     \\_\\_/ /_/--\\ |_|  | |_|__ ",
            "                                                    "
        };
        for(int i = 0; i < 4; ++i){
            int y = 13 + i;
            gotoXY(35, y);
            cout << newGame[i];
        }
    }

    if(choice != 1){
        gotoXY(56,19);
        cout << "LOADGAME" << endl;
    }
    else{
        string loadGame[4] = {
            "  _     ___    __    ___       __     __    _      ____ ", 
            " | |   / / \\  / /\\  | | \\     / /`_  / /\\  | |\\/| | |_  ",
            " |_|__ \\_\\_/ /_/--\\ |_|_/     \\_\\_/ /_/--\\ |_|  | |_|__ ",
            "                                                        "
        };

        for(int i = 0; i < 4; ++i){
            int y = 18 + i;
            gotoXY(33, y);
            cout << loadGame[i];
        }
    }   

    if(choice != 2){
        gotoXY(56,24);
        cout << "SETTINGS" << endl;
    }
    else{
        string setting[4] = {
            "  __   ____ _____ _____  _   _      __    __  ", 
            " ( (` | |_   | |   | |  | | | |\\ | / /`_ ( (` ",
            " _)_) |_|__  |_|   |_|  |_| |_| \\| \\_\\_/ _)_) ",
            "                                              "
        };

        for(int i = 0; i < 4; ++i){
            int y = 22 + i;
            gotoXY(37, y);
            cout << setting[i];
        }
    }                                                                                                                                                                                                                                                                          
    // clear();
    // system("pause");
}

void newGameMenu(){
    clear();
    gotoXY(0,0);
    textColor(241);
    gotoXY(25,14);
    cout << "Good morning! Please enter your name to start rocking the game: ";
}

void loadGameMenu(){
    clear();
    gotoXY(0,0);
    textColor(241);
    gotoXY(20,5);
    vector<string>names;
    cout << "No\t\t\tName\t\t\t\tLevel\t\tHP\t\tState";
    //for (const auto & entry : directory_iterator(dataroot))
      //  cout << entry.path() << endl;
    _getch();
}

void settingsMenu(){
    clear();
    gotoXY(0,0);
    textColor(241);
    gotoXY(34,14);
    cout << "Request not yet processed! Enter to return to the menu";
    _getch();
}
void resetMenu(){
    clear();
    gotoXY(0,0);
    textColor(241);
    gotoXY(25,14);
    cout << "Do you really want to reset all the data? (y/n): ";
}
void pauseMenu(){
    clear();
    gotoXY(0,0);
    textColor(241);
    gotoXY(25,14);
    cout << "Do you want to exit? (y/n): ";
}
void saveGameMenu(){
    clear();
    gotoXY(0,0);
    textColor(241);
    gotoXY(25,14);
    cout << "Save your process? (y/n): ";
}