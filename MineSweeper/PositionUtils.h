#pragma once
// PositionUtils.h
#ifndef POSITIONUTILS_H
#define POSITIONUTILS_H

#include <vector>
#include "Direction.h"
#include "PositionEnum.h"

class PositionUtils {
public:
    static PositionEnum GetPositionEnum(int row, int col);
    static std::vector<Direction> GetPossibleDirections(PositionEnum pos);
};

#endif // POSITIONUTILS_H