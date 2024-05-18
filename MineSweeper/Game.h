#pragma once
// Game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameLoop.h"

class Game {
private:
    GameLoop gameLoop;

public:
    Game() {}
    void StartGame();
    void DisplayBanner();
    void DisplayRules();
};

#endif // GAME_H