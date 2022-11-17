//
// Created by Regan Williamson on 11/16/22.
//

#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include "Header.h"
#include "piece.h"
using namespace std;


//constructor of the struct
game_piece::game_piece(piece_name p, string name, string display, int xcoord, int ycoord) : p_(p), name_(name), display_(display), xcoord_(xcoord), ycoord_(ycoord){}