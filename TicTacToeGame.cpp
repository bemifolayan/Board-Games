//
// Created by Gbemi Folayan on 11/17/22.
//

#include "TicTacToeGame.h"
#include "GameBase.h"

TicTacToeGame::TicTacToeGame():GameBase(){
    width = 5;
    height = 5;
    maxlength = 1;
    trn = 0;
    for(unsigned int i = 0; i < width*height; i++){
        game_piece g = game_piece(noName, "", " ", 1,1);
        pieces.push_back(g);
    }
}

bool TicTacToeGame :: done(){
    //checking vertical
    int count = 0;
    for(unsigned int i = rowOne; i < rowFour; i++){
        for(unsigned int j = colOne; j < colFour; j++){
            if(pieces.at(width* j+i).display_ == "X")
                count++;
            else if(pieces.at(width* j + i).display_ == "O")
                count--;
        }
        if(abs(count) == rowThree)
            return true;
        else
            count = 0;
    }

    //checking horizontal
    for(unsigned int i = colOne; i < colFour; i++){
        for(unsigned int j = rowOne; j < rowFour; j++){
            if(pieces.at(width*i + j).display_ == "X")
                count++;
            else if(pieces.at(width * i + j).display_ == "0")
                count--;
        }
        if(abs(count) == colThree)
            return true;
        else
            count = 0;
    }


    //checking for diagonal
    if(pieces.at(width* rowTwo + colTwo).display_ != " "){
        if(pieces.at(width* rowOne + colOne).display_ == pieces.at(width* rowTwo + colTwo).display_ ){
            if(pieces.at(width* rowTwo + colTwo).display_ == pieces.at(width* rowThree + colThree).display_ )
                return true;
        }

        if(pieces.at(width* rowOne + colThree).display_ == pieces.at(width* rowTwo + colTwo).display_){
            if(pieces.at(width* rowTwo + colTwo).display_ == pieces.at(width* rowThree + colOne).display_ )
                return true;
        }
    }

    return false;
}
//checks to see if the players had a draw
bool TicTacToeGame :: draw(){
    for(unsigned int i = rowOne; i < colFour; i++){
        for(unsigned int j = colOne; j < colFour; j++){
            if(pieces.at(width *i + j ).display_== " " )
                return false;
        }
    }
    if(done()){
        return false;
    }
    return true;
}
//asks the player to input a coordinate or quit

//keeps track of who's turn it is and changed the display to reflect what the player played
int TicTacToeGame :: turn(){


    unsigned int xcord;
    unsigned int ycord;
    string s;

    if(playCount % 2 == 0){
        p = "X";
    }
    else{
        p = "O";
    }
    int promptVal = prompt( xcord, ycord);
    if(promptVal == Success){
        playCount++;
        pieces.at(width* ycord + xcord).display_ = p;
        pieces.at(width* ycord + xcord).xcoord_= xcord;
        pieces.at(width* ycord + xcord).ycoord_ = ycord;
    }
    else if(promptVal == QuitGame){
        return QuitGame;
    }
    else{
        return FailedTurn;
    }


    TicTacToeGame temp;
    temp.pieces = pieces;
    cout << temp << endl;
    cout << "Player " << p << endl;
    for(int i = 0; i < pieces.size(); i++){
        if(pieces.at(i).display_ == p ){
            cout << pieces.at(i).xcoord_ << " " << pieces.at(i).ycoord_ << ";" << endl;
        }
    }
    trn++;
    return Success;
}

void TicTacToeGame::print(){
    cout << *this << endl;
}

ostream& operator<<(ostream& o, const TicTacToeGame & t) {

    o << setw(t.maxlength);
    for (int i = t.height - 1; i >= 0; i--) {
        o << i ;
        for (unsigned int j = 0; j < t.width; j++) {
            o << setw(t.maxlength) << t.pieces.at(t.width * i + j).display_ << " ";
        }
        o << endl;
    }
    o << " " ;


    for(unsigned int i = rowZero; i < rowFive; i++){
        o << setw(t.maxlength)<< i << " ";
    }
    o << endl;
    return o;
}