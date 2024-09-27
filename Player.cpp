#include "Player.h"
#include <iostream>

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

std::vector<std::string> Player::getHandOfCards() const {
    return handOfCards;
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

void Player::addCardToHand(const std::string& card) {
    handOfCards.push_back(card);
}

// Method to decide where to defend
std::vector<Territory*> Player::toDefend() const {
    // For now, return all owned territories; 
    return ownedTerritories;
}

// Method to decide where to attack
std::vector<Territory*> Player::toAttack() const {
    // Simple logic: find neighboring territories not owned by the player
    std::vector<Territory*> attackTargets;

    for (Territory* territory : ownedTerritories) {
        for (Territory* adj : territory->getAdjacentTerritories()) {
            if (std::find(ownedTerritories.begin(), ownedTerritories.end(), adj) == ownedTerritories.end()) {
                attackTargets.push_back(adj);
            }
        }
    }

    return attackTargets;
}

// Method to issue orders
void Player::issueOrder(const std::string& order) {
    orderList.push_back(order);
}

// Get the list of issued orders
std::vector<std::string> Player::getOrders() const {
    return orderList;
}

// Print Player info
void Player::printPlayerInfo() const {
    std::cout << "Player: " << playerName << "\n";
    std::cout << "Owned Territories: \n";
    for (Territory* territory : ownedTerritories) {
        territory->printTerritoryInfo();
    }

    std::cout << "Hand of Cards: \n";
    for (const std::string& card : handOfCards) {
        std::cout << card << " ";
    }
    std::cout << "\n";

    std::cout << "Orders: \n";
    for (const std::string& order : orderList) {
        std::cout << order << "\n";
    }
}
