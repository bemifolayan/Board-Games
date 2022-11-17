//
// Created by Regan Williamson on 11/16/22.
//
#include "GameBase.h"
#include "CommonFunctions.h"

GameBase::GameBase(){
    width = 0;
    height = 0;
    maxlength = 0;
    for(int i = 0; i < width*height; i++){
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
        cout << "Player has quit" << trn << "turn were made" << endl;
        return QuitGame;
    }
    else if(dr) {
        cout << "Draw." << trn << " moves were played and no winning moves remain" << endl;
        return Draw;
    }
}
GameBase* GameBase::obj(int a, char* arr[]){
    if(a == expectedCommandLineNum){
        string s = arr[inputFileName];
        if(s == "TicTacToe"){
            TicTacToeGame *game = new TicTacToeGame;
            return &game;
        }
    }
    GameBase* p;
    return p;
}
TicTacToeGame::TicTacToeGame():GameBase(){
    width = 5;
    height = 5;
    maxlength = 0;
    playCount = 0;
    trn = 0;
    p;
    for(int i = 0; i < width*height; i++){
        game_piece g = game_piece(noName, "", " ", 1,1);
        pieces.push_back(g);
    }
}
void GameBase::updatelength(game_piece x){
    if(x.display_.size() > maxlength)
        maxlength = x.display_.size();
}

void TicTacToeGame::print(){
    cout << *this << endl;
}

//if there is no piece, print out " " equivalent to maxlength
//if there is a piece whose display is < maxlength, add " " until it = maxlength

ostream& operator<<(ostream& o, const TicTacToeGame & t) {
    cout << setw(t.maxlength);
    for (int i = t.height - 1; i >= 0; i--) {
        cout << i<< " ";
        for (int j = 0; j < t.width; j++) {
            cout << t.pieces.at(t.width * i + j).display_ << " ";
        }
        cout << endl;
    }
    cout << "  0 1 2 3 4" << endl;
    return o;
}