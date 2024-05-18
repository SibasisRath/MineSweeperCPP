// Box.cpp
#include "Box.h"

// Default constructor
Box::Box()
    : isOpen(false), isBomb(false), numberOfNearByBombs(0), displayValue("-"), position(0, 0) {
    positionEnum = PositionUtils::GetPositionEnum(0, 0);
    possibleMovements = PositionUtils::GetPossibleDirections(positionEnum);
}

Box::Box(int row, int col)
    : isOpen(false), isBomb(false), numberOfNearByBombs(0), displayValue("-") {
    position = std::pair<int, int>(row, col);
    positionEnum = PositionUtils::GetPositionEnum(position.first, position.second);
    possibleMovements = PositionUtils::GetPossibleDirections(positionEnum);
}

PositionEnum Box::GetPositionEnum() const { return positionEnum; }

void Box::UpdatePossibleMovements(Direction directionToRemove) {
    auto it = std::find(possibleMovements.begin(), possibleMovements.end(), directionToRemove);
    if (it != possibleMovements.end()) {
        possibleMovements.erase(it);
    }
}

std::vector<Direction> Box::GetPossibleMovements() const { return possibleMovements; }

void Box::OpenBox() { isOpen = true; }

bool Box::GetBoxStatus() const { return isOpen; }

void Box::MakeItBomb() { isBomb = true; }

bool Box::CheckBombPresence() const { return isBomb; }

void Box::SetNumberOfNearByBombs(int val) { numberOfNearByBombs += val; }

int Box::GetNumberOfNearByBombs() const { return numberOfNearByBombs; }

std::pair<int, int> Box::GetPosition() const { return position; }

std::string Box::GetDisplayValue() const {
    if (!isOpen) {
        return "-";
    }
    else {
        return std::to_string(numberOfNearByBombs);
    }
}