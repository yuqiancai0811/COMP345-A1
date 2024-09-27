#include "GameEngine.h"
#include <iostream>
#include <string>

// This function tests the game states by allowing the user to input commands.
// It uses a loop that continues until the game reaches the "end" state.
void testGameStates() {
    GameEngine gameEngine;  // Create a GameEngine object
    std::string command;    // Variable to store user's commands

    // Loop until the game reaches the "end" state
    while (gameEngine.getCurrentState() != GameState::End) {  // Correctly compare with enum value
        // Display the current state as a string
        std::cout << "Current state: " << gameEngine.getCurrentStateAsString() << std::endl;
        
        // Prompt the user for a command
        std::cout << "Enter command: "; //Start  loadmap validatemap addplayer  assigncountries  IssueOrders  ExecuteOrders Win End
        std::cin >> command;  // Read user input
        
        // Pass the command to the game engine to handle state transitions
        gameEngine.handleCommand(command);
    }
    // Once the game reaches the "end" state, print a message
    std::cout << "The Game ended!!" << std::endl;
}

// Main function to start program
int main() {
    testGameStates();  // Call the test function to begin the state transitions
    return 0;  // Exit.
}
