#pragma once

// GameLoop.h
#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>
#include <stack>
#include "Board.h"
#include "InputManager.h"
#include "DirectionUtils.h"
#include "Constants.h"

class GameLoop {
private:
    Board board;
    InputManager inputManager;
    std::pair<int, int> rowAndColNum;
    int totalNumberOfBoxes;
    int numberOfOpenedBoxes;

    void PlantBomb(std::pair<int, int> firstInput);
    void MarkBombSurroundings(Box* box);
    void FirstIteration();
    void InGameDisplay();
    void OpeningAllSafeBoxes(Box& box);

public:
    GameLoop();
    void StartMainGameLoop();
};

#endif // GAMELOOP_H