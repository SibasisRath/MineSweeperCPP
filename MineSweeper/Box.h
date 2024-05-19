#pragma once
// Box.h
#ifndef BOX_H
#define BOX_H

#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "Direction.h"
#include "PositionUtils.h"

class Box {
private:
    std::pair<int, int> position;
    PositionEnum positionEnum;
    std::vector<Direction> possibleMovements;
    bool isOpen;
    bool isBomb;
    int numberOfNearByBombs;
    std::string displayValue;

public:
    // Default constructor
    Box();
    Box(int row, int col);

    PositionEnum GetPositionEnum() const;
    void UpdatePossibleMovements(Direction directionToRemove);
    std::vector<Direction> GetPossibleMovements() const;
    void OpenBox();
    bool GetBoxStatus() const;
    void MakeItBomb();
    bool CheckBombPresence() const;
    void SetNumberOfNearByBombs(int val);
    int GetNumberOfNearByBombs() const;
    std::pair<int, int> GetPosition() const;
    std::string GetDisplayValue() const;
};

#endif // BOX_H