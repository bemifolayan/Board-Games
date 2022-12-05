//
// Created by Gbemi Folayan on 11/17/22.
//
#pragma once
#include "GameBase.h"
class TicTacToeGame: public GameBase{
public:
    TicTacToeGame();
    // YL - these should be virtual - "virtual bool done() override;".
    bool done() override;
    bool draw() override;
    int turn() override;

    int trn;
    string p;
    int playCount;
    friend ostream& operator<<(ostream& o, const TicTacToeGame& t);
    void print() override;
};

