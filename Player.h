#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Map.h"    // For Territory class
#include "Orders.h" // For Order and OrderList classes
#include "Cards.h"  // For Hand, Deck, and Card classes

class Player {
private:
    std::string playerName;  // Name of the player
    // Use std::vector because its dynamic sizing, efficient access, and easy management
    std::vector<Territory*> ownedTerritories;  // List of territories owned by the player
    // std::vector<std::string> handOfCards;  // Hand of cards (simplified as strings)
    // std::vector<std::string> orderList;  // Orders issued by the player
    Hand playerHand;                          // Hand of cards for the player
    orderList playerOrders;                   // List of orders issued by the player


public:
    // Constructor
    Player(std::string name);

    // Destructor
    ~Player();

    // Getters
    std::string getName() const;
    std::vector<Territory*> getOwnedTerritories() const;
    Hand& getHand();  // Return reference to player's hand of cards

    // Setters
    void setName(const std::string& name);
    void addTerritory(Territory* territory);  // Add a territory to the player's control
    void removeTerritory(Territory* territory);  // Remove a territory from player's control

    // Methods to decide where to defend and attack
    std::vector<Territory*> toDefend() const;  // Returns a list of territories the player will defend
    std::vector<Territory*> toAttack() const;  // Returns a list of territories the player will attack

    // Methods for issuing orders
    void issueOrder(Order* order);  // Issues an order and adds it to the player's order list
    orderList& getOrders();  // Returns the list of orders issued by the player

    // Print Player's info
    void printPlayerInfo() const;
};

#endif // PLAYER_H
