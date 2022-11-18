//
// Created by Regan Williamson on 11/16/22.
//

#ifndef LAB4_FOLAYAN_WILLIAMSON_LAB4_HEADER_H
#define LAB4_FOLAYAN_WILLIAMSON_LAB4_HEADER_H

#endif //LAB4_FOLAYAN_WILLIAMSON_LAB4_HEADER_H
#pragma once
enum names {
    programName,
    inputFileName,
    expectedCommandLineNum
};
enum errs {
    Success,
    FileFailedtoOpen,
    FailedtoExtractDimensions,
    FailedTurn,
    WrongNumCommandArgs,
    FailedToReadDefinition,
    VectorDimensionsDoNotMatch,
    QuitGame,
    Draw

};

enum row{
    rowZero,
    rowOne,
    rowTwo,
    rowThree,
    rowFour,
    rowFive,
    rowSix};

enum col{
    colZero,
    colOne,
    colTwo,
    colThree,
    colFour
};

enum player{
    O,
    X
};