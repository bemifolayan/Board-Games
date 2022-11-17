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

/*
 * prints out the error message and what to do to fix it
 */
int usageMessage(char* c, string s) {
    errs e2 = WrongNumCommandArgs;
    cout << c << endl;
    cout << s << endl;
    return e2;
}