//
// Created by Gbemi Folayan on 11/17/22.
//

#include "GomokuGame.h"
GomokuGame:: GomokuGame():GameBase(){
    width = 21;
    height = 21;
    maxlength = 2;
    trn = 0;
    p = "";

    for(int i = 0; i < width*height; i++){
        game_piece g = game_piece(noName, "", " ", 1,1);
        pieces.push_back(g);
    }
}

bool GomokuGame:: done() {
    //row
    int countB = 1;
    int countW = 1;

    for (unsigned int i = rowOne; i <= height - 3; i++) {
        for (unsigned int j = colOne; j <= width - 2; j++) {
            if (pieces.at(width * j + i).display_ == "B") {
                if (pieces.at(width * j + (i + 1)).display_ == "B") {
                    countB++;
                    if (countB == 5)
                        return true;
                } else
                    countB = 1;
            } else if (pieces.at(width * j + i).display_ == "W") {
                if (pieces.at(width * j + (1 + i)).display_ == "W") {
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
    for (unsigned int i = rowOne; i <= height - 2; i++) {
        for (unsigned int j = colOne; j < width - 3; j++) {
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

    //diagonal going left

    countB  = 1;
    countW = 1;

    for(unsigned int i = rowOne; i< width - 6; i++) {
        for (unsigned int j = colOne; j < height - 6; j++) {
            if(pieces.at(width *j + i).display_ == "B"){
                for(unsigned int k = 1; k < 5; k++){
                    if(pieces.at(width *(j+k) + (i+k) ).display_ == "B")
                        countB++;
                    else
                        countB = 1;
                }
                if(countB == 5)
                    return true;
            }
            if(pieces.at(width *i + j ).display_ == "W"){
                for(unsigned int k = 1; k < 5; k++){
                    if(pieces.at(width *(j+k) + (i+k) ).display_ == "W")
                        countW++;
                    else
                        countW = 1;
                }
                if(countW == 5)
                    return true;
            }
        }
    }
    countB = 1;
    countW = 1;

    for(unsigned int i = width-1; i > rowFour; i--){
        for(unsigned int j = colOne; j < height-6; j++){
            if(pieces.at(width *j + i ).display_ == "B"){
                for(unsigned int k = 1;k < 5; k++){
                        if(pieces.at(width *(j+k) + (i-k) ).display_ == "B") {
                            countB++;
                        }
                        else
                            countB = 1;
                    if(countB == 5)
                        return true;
                }
            }
            if(pieces.at(width *i + j ).display_ == "W"){
                for(unsigned int k = 1; k < 5; k++){
                    if(pieces.at(width *(j+k) + (i-k) ).display_ == "W")
                        countW++;
                    else
                        countW = 1;
                }
                if(countW == 5)
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
        pieces.at(width* (ycord) + (xcord)).display_ = p;
        pieces.at(width* (ycord) + (xcord)).xcoord_= xcord;
        pieces.at(width* (ycord) + (xcord)).ycoord_ = ycord;
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
    for (unsigned int i = t.height - 2; i >= 1; i--) {
        o << i;
        for (unsigned int j = 1; j <= t.width - 2; j++) {
            o << setw(t.maxlength) << t.pieces.at(t.width * i + j).display_ << " ";
        }
        o << endl;
    }
    o << "X" ;


    for(unsigned int i = rowOne; i <= t.width - 2; i++){
        o << setw(t.maxlength)<< i << " ";
    }
    o << endl;
    return o;
}