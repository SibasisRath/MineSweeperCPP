// GameLoop.cpp
#include "GameLoop.h"

GameLoop::GameLoop() {
    totalNumberOfBoxes = ROW * COLUMN;
    numberOfOpenedBoxes = 0;
    PlantBomb();
}

void GameLoop::PlantBomb() {
    std::vector<Box*> bombs = board.GetRandomBoxes(NUMBER_OF_BOMBS);

    for (Box* box : bombs) {
        box->MakeItBomb();
        MarkBombSurroundings(box);
    }
}

void GameLoop::MarkBombSurroundings(Box* box) {
    std::vector<Direction> possibleDirection = box->GetPossibleMovements();
    for (const auto it : possibleDirection) {
        std::pair<int, int> offSet = DirectionUtils::GetDirectionOffset(it);
        std::pair<int, int> newPosition;
        newPosition.first = box->GetPosition().first + offSet.first;
        newPosition.second = box->GetPosition().second + offSet.second;
        Box& box = board.GetBox(newPosition.first, newPosition.second);
        box.SetNumberOfNearByBombs(1);
    }
}

void GameLoop::StartMainGameLoop() {
    std::string rowInput;
    std::string colInput;

    while (true) {
        std::cout << "\n\n";
        board.PrintBoard();
        rowAndColNum = inputManager.getValidInput(board);
        // Open the box
        Box& box = board.GetBox(rowAndColNum.first, rowAndColNum.second);
        if (box.CheckBombPresence()) {
            std::cout << "\nYou accidentally opened a Bomb.\n";
            break;
        }
        else {
            box.OpenBox();
            numberOfOpenedBoxes++;
            OpeningAllSafeBoxes(box);
            if (totalNumberOfBoxes - numberOfOpenedBoxes == NUMBER_OF_BOMBS) {
                std::cout << "You Won. (^__^)\n";
                break;
            }
        }
    }
}

void GameLoop::OpeningAllSafeBoxes(Box& box) {
    if (box.GetNumberOfNearByBombs() != 0) {
        return;
    }
    else {
        std::stack<Box*> boxTrail;
        boxTrail.push(&box);

        while (!boxTrail.empty()) {
            Box* tempBox = boxTrail.top();
            std::vector<Direction> dir = tempBox->GetPossibleMovements();

            if (dir.empty()) {
                boxTrail.pop();
            }
            else {
                Direction tempDir = dir[0];
                std::pair<int, int> tempDirOffset = DirectionUtils::GetDirectionOffset(tempDir);
                std::pair<int, int> tempBoxPosition = tempBox->GetPosition();
                std::pair<int, int> nextBoxPosition;
                nextBoxPosition.first = tempDirOffset.first + tempBoxPosition.first;
                nextBoxPosition.second = tempDirOffset.second + tempBoxPosition.second;

                Box* nextBox = &board.GetBox(nextBoxPosition.first, nextBoxPosition.second);

                tempBox->UpdatePossibleMovements(tempDir);
                if (!nextBox->GetBoxStatus()) {
                    nextBox->OpenBox();
                    numberOfOpenedBoxes++;
                }
                if (nextBox->GetNumberOfNearByBombs() == 0) {
                    boxTrail.push(nextBox);
                    Direction oppositeDirection = DirectionUtils::GetOppositeDirection(tempDir);
                    nextBox->UpdatePossibleMovements(oppositeDirection);
                }
            }
        }
    }
}