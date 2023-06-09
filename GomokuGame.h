//
// Created by Gbemi Folayan on 11/17/22.
//

#pragma once
#include "GameBase.h"
class GomokuGame : public GameBase{
public:
    GomokuGame();
    bool done() override;
    bool draw() override;
    int turn() override;

    friend ostream& operator<<(ostream& o, const GomokuGame& t);
    void print() override;
};