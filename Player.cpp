#include "Player.h"
#include <iostream>
#include <algorithm>  // Needed for std::remove

// Constructor
Player::Player(std::string name) : playerName(name) {}

// Destructor
Player::~Player() {}

// Getters
std::string Player::getName() const {
    return playerName;
}

std::vector<Territory*> Player::getOwnedTerritories() const {
    return ownedTerritories;
}

// Setters
void Player::setName(const std::string& name) {
    playerName = name;
}

void Player::addTerritory(Territory* territory) {
    ownedTerritories.push_back(territory);
}

void Player::removeTerritory(Territory* territory) {
    ownedTerritories.erase(std::remove(ownedTerritories.begin(), ownedTerritories.end(), territory), ownedTerritories.end());
}

// Method to decide where to defend
std::vector<Territory*> Player::toDefend() const {
    // For now, return the player's owned territories (arbitrary choice)
    return ownedTerritories;
}

// Method to decide where to attack
std::vector<Territory*> Player::toAttack() const {
    std::vector<Territory*> attackTargets;

    // For now, arbitrarily choose some adjacent territories that are not owned by the player
    for (Territory* territory : ownedTerritories) {
        for (Territory* adj : territory->getAdjacentTerritories()) {
            // Check if the adjacent territory is not owned by the player
            if (std::find(ownedTerritories.begin(), ownedTerritories.end(), adj) == ownedTerritories.end()) {
                attackTargets.push_back(adj);
            }
        }
    }

    return attackTargets;
}

// Method to issue orders
void Player::issueOrder(Order* order) {
    playerOrders.addOrder(order);
}

// Get the list of issued orders
orderList& Player::getOrders() {
    return playerOrders;
}

// Print Player info
void Player::printPlayerInfo() const {
    std::cout << "Player: " << playerName << "\n";
    std::cout << "Owned Territories: \n";
    for (Territory* territory : ownedTerritories) {
        territory->printTerritoryInfo();
    }

    std::cout << "Orders: \n";
    playerOrders.showAllOrders();  // Show all the orders in the orderList
}
