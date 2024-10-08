#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <iostream>
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Orders.h"
#include "Cards.h"

class GameEngine {
private:
    std::string currentState;        // The current game state (managed as a string)
    Map* selectedMap;                // The game map
    std::vector<Player*> playerList; // List of players
    Deck deck;                       // The deck of cards for the game

public:
    GameEngine();  // Constructor to initialize the game
    ~GameEngine(); // Destructor to clean up resources

    // Handles the startup phase of the game
    void handleStartup(); 

    // Processes user commands for starting the game
    void handleUserCommand(const std::string& command); 

    // Handles the gameplay phase (assigning reinforcement, issuing orders, executing orders)
    void playGame();

    // Function to draw and play cards
    void playCards(Player* player);

    // Helper function to transition between states
    void transitionTo(const std::string& newState);

    // Prints the initial welcome message
    void printWelcomeMessage() const;

    // Prompts the user for the next action after startup
    void promptNextAction() const;

    // Get the current game state as a string
    std::string getCurrentState() const;
};
#endif // GAMEENGINE_H
