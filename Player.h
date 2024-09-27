#include <vector>
#include <string>
#include "Map.h"  // Include Map.h where Territory class is defined

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    std::string playerName;  // Name of the player
    std::vector<Territory*> ownedTerritories;  // List of territories owned by the player
    std::vector<std::string> handOfCards;  // Hand of cards (simplified as strings)
    std::vector<std::string> orderList;  // Orders issued by the player

public:
    // Constructor
    Player(std::string name);

    // Destructor
    ~Player();

    // Getters
    std::string getName() const;
    std::vector<Territory*> getOwnedTerritories() const;
    std::vector<std::string> getHandOfCards() const;

    // Setters
    void setName(const std::string& name);
    void addTerritory(Territory* territory);  // Add a territory to the player's control
    void removeTerritory(Territory* territory);  // Remove a territory from player's control
    void addCardToHand(const std::string& card);  // Add a card to player's hand

    // Methods to decide where to defend and attack
    std::vector<Territory*> toDefend() const;  // Returns a list of territories the player will defend
    std::vector<Territory*> toAttack() const;  // Returns a list of territories the player will attack

    // Methods for issuing orders
    void issueOrder(const std::string& order);  // Issues an order and adds it to the order list
    std::vector<std::string> getOrders() const;  // Returns the list of orders issued by the player

    // Print Player's info
    void printPlayerInfo() const;
};

#endif // PLAYER_H
