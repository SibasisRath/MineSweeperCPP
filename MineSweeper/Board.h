#pragma once
// Board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "Box.h" 

class Board {
private:
    std::vector<std::vector<Box>> allBoxes;
    void InitiateBoard(int row, int column);

public:
    Board();
    Box& GetBox(int row, int col);
    std::vector<Box*> GetRandomBoxes(int numBoxes, std::pair<int,int> firstInput);
    void PrintBoard();
};

#endif // BOARD_H