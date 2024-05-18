#pragma once
// DirectionUtils.h
#ifndef DIRECTIONUTILS_H
#define DIRECTIONUTILS_H

#include <utility> // For std::pair
#include "Direction.h" // Include the Direction.h header file

class DirectionUtils {
public:
    static std::pair<int, int> GetDirectionOffset(Direction dir);
    static Direction GetOppositeDirection(Direction dir);
    static std::pair<int, int> GetOppositeDirectionOffset(Direction dir);
};

#endif // DIRECTIONUTILS_H