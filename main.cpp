#include <iostream>
#include "GameBase.h"
#include "CommonFunctions.h"

int main(int argc, char* argv[]) {
    GameBase* p = GameBase :: obj(argc, argv);
    auto sh = make_shared<GameBase* >(p);
    if(p == 0){
        return usageMessage(argv[programName], "Please make the program argument TicTacToe or Gomoku");
    }
    else{
        int val = p->play();
        return val;
    }
}
