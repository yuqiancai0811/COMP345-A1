#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <iostream>
#include <string>
#include <iostream>
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
#include "Player.h"
#include <vector>
// Enum class to represent different game states
enum class GameState {
    Start,
    MapLoaded,
    MapValidated,
    PlayersAdded,
    AssignReinforcement,
    IssueOrders,
    ExecuteOrders,
    Win,
    End
};

class GameEngine {
public:
    // Constructor initializes the game engine with the initial state
    GameEngine();
    // Destructor (using default as there is no dynamic memory to clean up)
    ~GameEngine() = default;
    // Processes the command input by the user and transitions between states
    void handleCommand(const std::string& command);// Handles user commands
    // Returns the current game state as an enum

    GameState getCurrentState() const; //getter function for the current state.
    // Converts the enum state to a string.
    std::string getCurrentStateAsString() const;


private:
    GameState currentState;  // Stores the current state of the game
    // Helper methods for state transitions  ---8
    void transitionToMapLoaded();
    void transitionToMapValidated();
    void transitionToPlayersAdded();
    void transitionToAssignReinforcement();
    void transitionToIssueOrders();
    void transitionToExecuteOrders();
    void transitionToWin();
    void transitionToEnd();
    

    // Helper methods for handling different game states
    void handleStartState(const std::string& command);
    void handleMapLoadedState(const std::string& command);
    void handleMapValidatedState(const std::string& command);
    void handlePlayersAddedState(const std::string& command);
    
    void handleAssignReinforcementState(const std::string& command);
    void handleIssueOrdersState(const std::string& command);
    void handleExecuteOrdersState(const std::string& command);

    void handleWinState(const std::string& command);
    void handleEndState(const std::string& command);


    // Centralized function to print an error message for invalid commands
    void printInvalidCommand(const std::string& expectedCommand) const;
};

#endif // GAMEENGINE_H
