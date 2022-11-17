//
// Created by Regan Williamson on 11/16/22.
//

#ifndef LAB4_FOLAYAN_WILLIAMSON_LAB4_PIECE_H
#define LAB4_FOLAYAN_WILLIAMSON_LAB4_PIECE_H

#endif //LAB4_FOLAYAN_WILLIAMSON_LAB4_PIECE_H
#pragma once
#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include "Header.h"
using namespace std;

enum piece_name{
    Y_,
    X_,
    noName
};

struct game_piece{
    game_piece(piece_name p, string name, string display, int xcoord, int ycoord);
    piece_name p_;
    string name_;
    string display_;
    int xcoord_;
    int ycoord_;
};