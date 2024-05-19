// Board.cpp
#include "Board.h"
#include "Constants.h"

void Board::InitiateBoard(int row, int column) {

    allBoxes.resize(row, std::vector<Box>(column));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            allBoxes[i][j] = Box(i, j);
        }
    }
}

Board::Board() {
    InitiateBoard(ROW, COLUMN);
}

Box& Board::GetBox(int row, int col) {
    return allBoxes[row][col];
}

std::vector<Box*> Board::GetRandomBoxes(int numBoxes, std::pair<int,int> firstInput) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distRow(0, ROW - 1);
    std::uniform_int_distribution<> distCol(0, COLUMN - 1);

    std::vector<Box*> randomBoxes;
    while (randomBoxes.size() < numBoxes) {
        int randomRow = distRow(gen);
        int randomCol = distCol(gen);
        // Check if the random position matches firstInput
        if (randomRow == firstInput.first && randomCol == firstInput.second) {
            continue; // Skip this iteration
        }

        Box& box = allBoxes[randomRow][randomCol];

        // Check if the box is already in the vector
        bool isDuplicate = std::any_of(randomBoxes.begin(), randomBoxes.end(), [&](Box* b) {
            return b->GetPosition().first == box.GetPosition().first && b->GetPosition().second == box.GetPosition().second;
            });

        if (!isDuplicate) {
            randomBoxes.push_back(&box);
            //std::cout << box.GetPosition().first << ", " << box.GetPosition().second << "\n";
        }
    }

    return randomBoxes;
}

void Board::PrintBoard() {

    int rowCounter = 0;
    int columnCounter = 0;

    std::cout << " ";
    while (columnCounter < COLUMN) {
        std::cout << " " << columnCounter;
        columnCounter++;
    }
    std::cout << std::endl;

    for (const auto& row : allBoxes) {
        std::cout << rowCounter << " ";
        rowCounter++;
        for (const auto& box : row) {
            std::cout << box.GetDisplayValue() << " ";
        }
        std::cout << std::endl;
    }
}