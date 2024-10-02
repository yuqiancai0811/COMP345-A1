#include "GameEngine.h"
#include <iostream>

int main() {
    GameEngine gameEngine;

    std::string command;
    while (gameEngine.getCurrentState() != "END") {
        std::cout << "Current game state: " << gameEngine.getCurrentState() << std::endl;
        std::cout << "Enter command (start/play/end): ";
        std::cin >> command;
        gameEngine.handleUserCommand(command);
    }

    return 0;
}
