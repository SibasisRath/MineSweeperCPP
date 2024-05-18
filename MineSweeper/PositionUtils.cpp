// PositionUtils.cpp
#include "PositionUtils.h"
#include "Constants.h"

PositionEnum PositionUtils::GetPositionEnum(int row, int col) {

    if (row == 0 && col == 0) {
        return NorthWestCorner;
    }
    else if (row == 0 && col == COLUMN - 1) {
        return NorthEastCorner;
    }
    else if (row == ROW - 1 && col == 0) {
        return SouthWestCorner;
    }
    else if (row == ROW - 1 && col == COLUMN - 1) {
        return SouthEastCorner;
    }
    else if (row == 0) {
        return NorthBorder;
    }
    else if (row == ROW - 1) {
        return SouthBorder;
    }
    else if (col == 0) {
        return WestBorder;
    }
    else if (col == COLUMN - 1) {
        return EastBorder;
    }
    else {
        return Middle;
    }
}

std::vector<Direction> PositionUtils::GetPossibleDirections(PositionEnum pos) {
    std::vector<Direction> possibleDirections;

    switch (pos) {
    case NorthWestCorner:
        possibleDirections = { East, SouthEast, South };
        break;
    case NorthEastCorner:
        possibleDirections = { West, SouthWest, South };
        break;
    case SouthWestCorner:
        possibleDirections = { East, NorthEast, North };
        break;
    case SouthEastCorner:
        possibleDirections = { West, NorthWest, North };
        break;
    case NorthBorder:
        possibleDirections = { East, West, South, SouthEast, SouthWest };
        break;
    case SouthBorder:
        possibleDirections = { East, West, North, NorthEast, NorthWest };
        break;
    case EastBorder:
        possibleDirections = { North, South, NorthWest, SouthWest, West };
        break;
    case WestBorder:
        possibleDirections = { North, South, NorthEast, SouthEast, East };
        break;
    case Middle:
        possibleDirections = { North, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest };
        break;
    }

    return possibleDirections;
}