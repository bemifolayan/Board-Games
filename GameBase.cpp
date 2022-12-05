//
// Created by Regan Williamson on 11/16/22.
//
#include "GameBase.h"
#include "CommonFunctions.h"
#include "TicTacToeGame.h"
#include "GomokuGame.h"
#include <iomanip>

GameBase::GameBase(): width(0), height(0), maxlength(0), trn(0), playCount(0), p(""){
    for(unsigned int i = 0; i < width*height; i++){
        game_piece g = game_piece(noName, "", " ", 1,1);
        pieces.push_back(g);
    }
}

int GameBase:: play(){
    print();
    int t = turn();
    bool d = done();
    bool dr = draw();
    while(t != QuitGame && !d  && !dr){
        t = turn();
        d = done();
        dr = draw();
    }

    if(d){
        cout << "Player " << p << " won the game!" << endl;
        return Success;
    }
    else if (t == QuitGame){
        cout << "Player has quit. " << trn << " turns were made." << endl;
        return QuitGame;
    }
    else {
        cout << "Draw." << trn << " moves were played and no winning moves remain." << endl;
        return Draw;
    }
}

int GameBase :: prompt( unsigned int &j, unsigned int &k) {
    while (true) {
        string x;
        cout << "Input Coordinate or quit";
        cin >> x;
        if (x == "quit") {
            return QuitGame;
        }
        else {
            bool comma = false;
            char c = ',';
            int f = x.find(c);
            if(f != -1)
                comma = true;

            if (comma) {
                x[f] = ' ';
                istringstream iss(x);
                if (iss >> j && iss >> k) {
                    if (j < height - 1 && j > colZero && k < width - 1 && k > rowZero) { //are 19th row and col allowed???? if use,change
                        if(pieces.at(width* k + j).display_ == " ")
                            return Success;
                    }
                }
                else{
                    return FailedtoExtractDimensions;
                }
            }
        }
    }
}

GameBase* GameBase::obj(int a, char* arr[]){
    // YL - game could potentially be uninitiailized
    GameBase* game = NULL;
    if(a == expectedCommandLineNum){
        string s = arr[inputFileName];
        if(s == "TicTacToe"){

            game = new TicTacToeGame();

        }
        else if(s == "Gomoku"){
            game = new GomokuGame();
        }
    }
    // YL - what if a != expectedCommandLineNum? What do you return then?
    return game;
}


//if there is no piece, print out " " equivalent to maxlength
//if there is a piece whose display is < maxlength, add " " until it = maxlength

