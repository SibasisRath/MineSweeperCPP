// Game.cpp
#include "Game.h"

void Game::StartGame() {
    DisplayBanner();
    DisplayRules();
    gameLoop.StartMainGameLoop();
    std::cout << "Game Over!\n";
    std::cout << "Thank you for playing!\n";
    std::cout << "Press any key to exit...\n";  
    //system("pause");
    std::cin.get();

}

void Game::DisplayBanner() {
    std::cout << R"(
8888ba.88ba  oo                   .d88888b                                                          
88  `8b  `8b                      88.    "'                                                         
88   88   88 dP 88d888b. .d8888b. `Y88888b. dP  dP  dP .d8888b. .d8888b. 88d888b. .d8888b. 88d888b. 
88   88   88 88 88'  `88 88ooood8       `8b 88  88  88 88ooood8 88ooood8 88'  `88 88ooood8 88'  `88 
88   88   88 88 88    88 88.  ... d8'   .8P 88.88b.88' 88.  ... 88.  ... 88.  .88 88.  ... 88       
dP   dP   dP dP dP    dP `88888P'  Y88888P  8888P Y8P  `88888P' `88888P' 88Y888P' `88888P' dP       
                                                                         88                         
                                                                         dP                                
)" << '\n';
}

void Game::DisplayRules() {
    std::cout << "Rules:\n"
        << "1. The board is divided into cells, with mines randomly distributed.\n"
        << "2. To win, you need to open all the cells.\n"
        << "3. The number on a cell shows the number of mines adjacent to it.Using this information, you can determine cells that are safe, and cells that contain mines.\n"
        << "4. Interact, evolve and enjoy!\n\n"
        << "How to play:\n"
        << "1. User will input x and y. (Co-ordinates where they want to click.)\n\n";
}