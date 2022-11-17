#include <iostream>
#include "GameBase.h"
#include "CommonFunctions.h"

int main(int argc, char* argv[]) {
    GameBase base;
    GameBase* poin = base.obj(argc, argv);
    shared_ptr<GameBase> p = make_shared<GameBase>(*poin);
    if(poin == 0){
        return usageMessage(argv[programName], "TicTacToeGame");
    }
    else{
        int val = poin->play();
        return val;
    }
}
