#include "Map.h"  
#include "Player.h"
#include <iostream>

void testPlayers() {
    // Create some territories
    std::vector<std::string> adjTerritoryNames1 = {"Territory 2", "Territory 3"};
    Territory* territory1 = new Territory("Territory 1", 0, 0, "Continent 1", adjTerritoryNames1);
    
    std::vector<std::string> adjTerritoryNames2 = {"Territory 1", "Territory 3"};
    Territory* territory2 = new Territory("Territory 2", 1, 1, "Continent 1", adjTerritoryNames2);

    std::vector<std::string> adjTerritoryNames3 = {"Territory 1", "Territory 2"};
    Territory* territory3 = new Territory("Territory 3", 2, 2, "Continent 2", adjTerritoryNames3);

    // Create a player and assign territories to the player
    Player player1("Player 1");
    player1.addTerritory(territory1);
    player1.addTerritory(territory2);
    
    // Print player information
    std::cout << "=== Player 1 Information ===" << std::endl;
    player1.printPlayerInfo();
    
    // Test issuing orders
    std::cout << "\nIssuing orders for Player 1..." << std::endl;
    player1.issueOrder("Attack Territory 3");
    player1.issueOrder("Defend Territory 1");

    // Print orders issued by the player
    std::cout << "\n=== Orders issued by Player 1 ===" << std::endl;
    for (const std::string& order : player1.getOrders()) {
        std::cout << "Order: " << order << std::endl;
    }

    // Test toDefend and toAttack functions
    std::cout << "\n=== Territories Player 1 will defend ===" << std::endl;
    for (Territory* t : player1.toDefend()) {
        std::cout << t->getName() << std::endl;
    }

    std::cout << "\n=== Territories Player 1 will attack ===" << std::endl;
    for (Territory* t : player1.toAttack()) {
        std::cout << t->getName() << std::endl;
    }

    // Cleanup dynamically allocated memory
    delete territory1;
    delete territory2;
    delete territory3;
}

int main() {
    // Run the test
    testPlayers();
    return 0;
}
