//
// Created by Regan Williamson on 11/16/22.
//

#pragma once
#include <iostream>
#include <vector>
#include "piece.h"

class GameBase{
protected:
    unsigned int height;
    unsigned int width;
    unsigned int maxlength;
    unsigned int trn;
    unsigned int playCount;
    string p;
    vector<game_piece> pieces;
public:
    GameBase();
    virtual void print() = 0;
    virtual bool done() = 0;
    virtual bool draw() = 0;
    virtual int turn() = 0;
    int prompt(unsigned int &j,unsigned int &k);
    int play();
    static GameBase* obj(int a, char* arr[]);
};

