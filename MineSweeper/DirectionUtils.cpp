// DirectionUtils.cpp
#include "DirectionUtils.h"

std::pair<int, int> DirectionUtils::GetDirectionOffset(Direction dir) {
    switch (dir) {
    case North:
        return std::make_pair(-1, 0);
    case NorthEast:
        return std::make_pair(-1, 1);
    case East:
        return std::make_pair(0, 1);
    case SouthEast:
        return std::make_pair(1, 1);
    case South:
        return std::make_pair(1, 0);
    case SouthWest:
        return std::make_pair(1, -1);
    case West:
        return std::make_pair(0, -1);
    case NorthWest:
        return std::make_pair(-1, -1);
    default:
        return std::make_pair(0, 0);
    }
}

Direction DirectionUtils::GetOppositeDirection(Direction dir) {
    switch (dir) {
    case North:
        return South;
    case NorthEast:
        return SouthWest;
    case East:
        return West;
    case SouthEast:
        return NorthWest;
    case South:
        return North;
    case SouthWest:
        return NorthEast;
    case West:
        return East;
    case NorthWest:
        return SouthEast;
    default:
        return North;
    }
}

std::pair<int, int> DirectionUtils::GetOppositeDirectionOffset(Direction dir) {
    return GetDirectionOffset(GetOppositeDirection(dir));
}