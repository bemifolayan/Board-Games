//
// Created by Gbemi Folayan on 11/17/22.
//

#include "GomokuGame.h"
GomokuGame:: GomokuGame():GameBase(){
    width = 19;
    height = 19;
    maxlength = 2;
    trn = 0;
    p = "";

    for(int i = 0; i < width*height; i++){
        game_piece g = game_piece(noName, "", " ", 1,1);
        pieces.push_back(g);
    }
}

bool GomokuGame:: done(){
    //row
    int countB = 1;
    int countW = 1;
    string track = "";
    for(unsigned int i = rowOne; i <= height - 1; i++) {
        for (unsigned int j = colOne; j <= width; j++) {
            if (pieces.at(width * j + i).display_ == "B") {
                if (pieces.at(width * (j + 1) + i).display_ == "B") {
                    countB++;
                    if (countB == 5)
                        return true;
                } else
                    countB = 1;
            } else if (pieces.at(width * j + i).display_ == "W") {
                if (pieces.at(width * (j + 1) + i).display_ == "W") {
                    countW++;
                    if (countW == 5)
                        return true;
                } else
                    countW = 1;
            }
        }
    }
        //columns
        countB = 1;
        countW = 1;
        for(unsigned int i = rowOne; i <= height; i++){
            for(unsigned int j = colOne; j <= width - 1; j++){
                if(pieces.at(width* j+i).display_ == "B"){
                    if(pieces.at(width* j + (i+1) ).display_ == "B"){
                        countB++;
                        if(countB == 5)
                            return true;
                    }
                    else
                        countB = 1;
                }
                else if(pieces.at(width* j+i).display_ == "W"){
                    if(pieces.at(width* j+(i+1)).display_ == "W"){
                        countW++;
                        if(countW == 5)
                            return true;
                    }
                    else
                        countW = 1;
                }
            }
        }

        //diagonal going up to right
        for(unsigned int i = rowOne; i <= 15; i++) {
            for (unsigned int j = colOne; j <= 15; j++) {
                if(pieces.at(width*j+i).display_ == "B" && pieces.at(width*j+i+20).display_ == "B" && pieces.at(width*j+i+40).display_ == "B"
                && pieces.at(width*j+i+60).display_ == "B" && pieces.at(width*j+i+80).display_ == "B"){
                    return true;
                }
                else if(pieces.at(width*j+i).display_ == "W" && pieces.at(width*j+i+20).display_ == "W" && pieces.at(width*j+i+40).display_ == "W"
                       && pieces.at(width*j+i+60).display_ == "W" && pieces.at(width*j+i+80).display_ == "B"){
                    return true;
                }
            }
        }
        //diagonal going up to left
    for(unsigned int i = rowOne; i <= 15; i++) {
        for (unsigned int j = 5; j <= 15; j++) {
            if(pieces.at(width*j+i).display_ == "B" && pieces.at(width*j+i+18).display_ == "B" && pieces.at(width*j+i+36).display_ == "B"
               && pieces.at(width*j+i+54).display_ == "B" && pieces.at(width*j+i+72).display_ == "B"){
                return true;
            }
            else if(pieces.at(width*j+i).display_ == "W" && pieces.at(width*j+i+18).display_ == "W" && pieces.at(width*j+i+36).display_ == "W"
                    && pieces.at(width*j+i+54).display_ == "W" && pieces.at(width*j+i+72).display_ == "B"){
                return true;
            }
        }
    }
    return false;
}

bool GomokuGame:: draw(){
    for(int i = rowOne; i < height; i++){
        for(int j = colOne; j < width; j++){
            if(pieces.at(width *i + j ).display_== " " )
                return false;
        }
    }
    if(done()){
        return false;
    }
    return true;
}

int GomokuGame :: turn(){

    unsigned int xcord;
    unsigned int ycord;
    string s;

    if(playCount % 2 == 0){
        p = "B";
    }
    else{
        p = "W";
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


    GomokuGame temp;
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

void GomokuGame::print(){
    cout << *this << endl;
}

ostream& operator<<(ostream& o, const GomokuGame & t) {

    o << setw(t.maxlength);
    for (int i = t.height - 1; i >= 0; i--) {
        o << i + 1;
        for (unsigned int j = 0; j < t.width; j++) {
            o << setw(t.maxlength) << t.pieces.at(t.width * i + j).display_ << " ";
        }
        o << endl;
    }
    o << "X" ;


    for(unsigned int i = rowOne; i <= t.width; i++){
        o << setw(t.maxlength)<< i << " ";
    }
    o << endl;
    return o;
}