#pragma once
// InputManager.h
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>
#include <string>
#include <utility>
#include "Board.h" // Include the Board.h header file
#include "Constants.h" // Include the Constants.h header file

class InputManager {
public:
    static std::pair<int, int> getValidInput(Board& board);

private:
    static int validateInput(const std::string& input, int minValue, int maxValue);
};

#endif // INPUTMANAGER_H