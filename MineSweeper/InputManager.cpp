// InputManager.cpp
#include "InputManager.h"

std::pair<int, int> InputManager::getValidInput(Board& board) {
    int row, col;
    std::pair<int, int> validInput;

    while (true) {
        // Get valid row input
        std::string rowInput;
        do {
            std::cout << "Enter row value (0 - " << ROW - 1 << "): ";
            std::getline(std::cin, rowInput);
            row = validateInput(rowInput, 0, ROW - 1);
        } while (row == -1);

        // Get valid column input
        std::string colInput;
        do {
            std::cout << "Enter column value (0 - " << COLUMN - 1 << "): ";
            std::getline(std::cin, colInput);
            col = validateInput(colInput, 0, COLUMN - 1);
        } while (col == -1);

        // Check if the input box is valid and open
        Box box = board.GetBox(row, col);
        if (box.GetBoxStatus()) {
            std::cout << "The selected box is already opened. Please try again." << std::endl;
        }
        else {
            validInput = std::make_pair(row, col);
            break;
        }
    }

    return validInput;
}

int InputManager::validateInput(const std::string& input, int minValue, int maxValue) {
    try {
        int value = std::stoi(input);
        if (value >= minValue && value <= maxValue) {
            return value;
        }
    }
    catch (const std::invalid_argument& e) {
        // Invalid input
        std::cerr << "Invalid input. Please enter a valid number." << std::endl;
    }
    catch (const std::out_of_range& e) {
        // Input out of range
        std::cerr << "Input is out of range." << std::endl;
    }

    return -1;
}