#include "GameEngine.h"
#include <iostream>

// Constructor initializes the game state to "Start"
GameEngine::GameEngine() : currentState(GameState::Start) {}

// Returns the current state of the game as an enum value
GameState GameEngine::getCurrentState() const {
    return currentState;
}

// Converts the current state to a string for display purposes
std::string GameEngine::getCurrentStateAsString() const {
    switch (currentState) {
        // Based on the current state, return the corresponding string
        case GameState::Start: return "start";
        case GameState::MapLoaded: return "map loaded";
        case GameState::MapValidated: return "map validated";
        case GameState::PlayersAdded: return "players added";
        case GameState::AssignReinforcement: return "assign reinforcement";
        case GameState::IssueOrders: return "issue orders";
        case GameState::ExecuteOrders: return "execute orders";
        case GameState::Win: return "win";
        case GameState::End: return "end";
        default: return "unknown state";  // Default case for an invalid state
    }
}

// Handles user commands and transitions between states based on the current state
void GameEngine::handleCommand(const std::string& command) {
    switch (currentState) {
        case GameState::Start:
            handleStartState(command);
            break;
        case GameState::MapLoaded:
            handleMapLoadedState(command);
            break;
        case GameState::MapValidated:
            handleMapValidatedState(command);
            break;
        case GameState::PlayersAdded:
            handlePlayersAddedState(command);
            break;
        case GameState::AssignReinforcement:
            handleAssignReinforcementState(command);
            break;
        case GameState::IssueOrders:
            handleIssueOrdersState(command);
            break;
        case GameState::ExecuteOrders:
            handleExecuteOrdersState(command);
            break;
        case GameState::Win:
            handleWinState(command);
            break;
        case GameState::End:
            handleEndState(command);
            break;
        default:
            std::cout << "Invalid state." << std::endl;  // Catch-all for invalid states
    }
}

// Handles commands specific to the "Start" state
void GameEngine::handleStartState(const std::string& command) {
    if (command == "loadmap") {
        // Transition to the "MapLoaded" state if the command is "loadmap"
        transitionToMapLoaded();
    } else {
        // Print an error message if the command is invalid
        printInvalidCommand("loadmap");
    }
}

// Handles commands specific to the "MapLoaded" state
void GameEngine::handleMapLoadedState(const std::string& command) {
    if (command == "validatemap") {
        // Transition to the "MapValidated" state if the command is "validatemap"
        transitionToMapValidated();
    } else {
        printInvalidCommand("validatemap");
    }
}

// Handles commands specific to the "MapValidated" state
void GameEngine::handleMapValidatedState(const std::string& command) {
    if (command == "addplayer") {
        // Transition to the "PlayersAdded" state if the command is "addplayer"
        transitionToPlayersAdded();
    } else {
        printInvalidCommand("addplayer");
    }
}

// Handles commands specific to the "PlayersAdded" state
void GameEngine::handlePlayersAddedState(const std::string& command) {
    if (command == "assigncountries") {
        // Transition to the "AssignReinforcement" state if the command is "assigncountries"
        transitionToAssignReinforcement();
    } else {
        printInvalidCommand("assigncountries");
    }
}

// Handles commands specific to the "AssignReinforcement" state
void GameEngine::handleAssignReinforcementState(const std::string& command) {
    if (command == "issueorder") {
        // Transition to the "IssueOrders" state if the command is "issueorder"
        transitionToIssueOrders();
    } else if (command == "execorder") {
        // Transition to the "ExecuteOrders" state if the command is "execorder"
        transitionToExecuteOrders();
    } else {
        printInvalidCommand("issueorder or execorder");
    }
}

// Handles commands specific to the "IssueOrders" state
void GameEngine::handleIssueOrdersState(const std::string& command) {
    if (command == "endissueorders") {
        // Transition to the "ExecuteOrders" state if the command is "endissueorders"
        transitionToExecuteOrders();
    } else {
        printInvalidCommand("endissueorders");
    }
}

// Handles commands specific to the "ExecuteOrders" state
void GameEngine::handleExecuteOrdersState(const std::string& command) {
    if (command == "win") {
        // Transition to the "Win" state if the command is "win"
        transitionToWin();
    } else {
        printInvalidCommand("win");
    }
}

// Handles commands specific to the "Win" state
void GameEngine::handleWinState(const std::string& command) {
    if (command == "end") {
        // Transition to the "End" state if the command is "end"
        transitionToEnd();
    } else {
        printInvalidCommand("end");
    }
}

// Handles commands specific to the "End" state (no more transitions allowed)
void GameEngine::handleEndState(const std::string& command) {
    std::cout << "Game has already ended." << std::endl;  // Once in the "End" state, no more commands are accepted
}

// Centralized function to print an error message for invalid commands
void GameEngine::printInvalidCommand(const std::string& expectedCommand) const {
    std::cout << "Invalid command. Expected '" << expectedCommand << "'." << std::endl;
}

// Transitions to the "MapLoaded" state and prints the new state
void GameEngine::transitionToMapLoaded() {
    currentState = GameState::MapLoaded;
    std::cout << "State changed to: map loaded" << std::endl;
}

// Transitions to the "MapValidated" state and prints the new state
void GameEngine::transitionToMapValidated() {
    currentState = GameState::MapValidated;
    std::cout << "State changed to: map validated" << std::endl;
}

// Transitions to the "PlayersAdded" state and prints the new state
void GameEngine::transitionToPlayersAdded() {
    currentState = GameState::PlayersAdded;
    std::cout << "State changed to: players added" << std::endl;
}

// Transitions to the "AssignReinforcement" state and prints the new state
void GameEngine::transitionToAssignReinforcement() {
    currentState = GameState::AssignReinforcement;
    std::cout << "State changed to: assign reinforcement" << std::endl;
}

// Transitions to the "IssueOrders" state and prints the new state
void GameEngine::transitionToIssueOrders() {
    currentState = GameState::IssueOrders;
    std::cout << "State changed to: issue orders" << std::endl;
}

// Transitions to the "ExecuteOrders" state and prints the new state
void GameEngine::transitionToExecuteOrders() {
    currentState = GameState::ExecuteOrders;
    std::cout << "State changed to: execute orders" << std::endl;
}

// Transitions to the "Win" state and prints the new state
void GameEngine::transitionToWin() {
    currentState = GameState::Win;
    std::cout << "State changed to: win" << std::endl;
}

// Transitions to the "End" state and prints the final message
void GameEngine::transitionToEnd() {
    currentState = GameState::End;
    std::cout << "Game has ended." << std::endl;
}
