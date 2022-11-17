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
    vector<game_piece> pieces;
    void updatelength(game_piece x);
public:
    GameBase();
    class TicTacToeGame;
    virtual void print() = 0;
    virtual bool done() = 0;
    virtual bool draw() = 0;
    virtual int turn() = 0;
    int prompt(unsigned int &j,unsigned int &k);
    int play();
    static GameBase* obj(int a, char* arr[]);
};

class TicTacToeGame: public GameBase{
    public:
        TicTacToeGame();
        virtual bool done();
        virtual bool draw();
        virtual int turn();

        int trn;
        string p;
        int playCount;
        friend ostream& operator<<(ostream& o, const TicTacToeGame& t);
        void print();
};