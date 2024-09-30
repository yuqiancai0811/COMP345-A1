#include "Player.h"
#include "Orders.h"
#include "Map.h"
#include <iostream>

void testPlayers() {
    // Step 1: Create some territories
    std::vector<std::string> adjTerritoryNames1 = {"Territory 2", "Territory 3"};
    Territory* territory1 = new Territory("Territory 1", 0, 0, "Continent 1", adjTerritoryNames1);

    std::vector<std::string> adjTerritoryNames2 = {"Territory 1", "Territory 3"};
    Territory* territory2 = new Territory("Territory 2", 1, 1, "Continent 1", adjTerritoryNames2);

    std::vector<std::string> adjTerritoryNames3 = {"Territory 1", "Territory 2"};
    Territory* territory3 = new Territory("Territory 3", 2, 2, "Continent 2", adjTerritoryNames3);

    // Step 2: Create a player and assign territories to the player
    Player player1("Player 1");
    player1.addTerritory(territory1);
    player1.addTerritory(territory2);

    // Step 3: Demonstrate `toDefend()`
    std::cout << "== Territories Player 1 will defend ==" << std::endl;
    for (Territory* defendTerritory : player1.toDefend()) {
        defendTerritory->printTerritoryInfo();
    }

    // Step 4: Demonstrate `toAttack()`
    std::cout << "\n== Territories Player 1 will attack ==" << std::endl;
    for (Territory* attackTerritory : player1.toAttack()) {
        attackTerritory->printTerritoryInfo();
    }

    // // Step 5: Player draws some cards (optional, if needed)
    // // For simplicity, we simulate that the player draws cards from a deck
    // Deck gameDeck;
    // player1.getHand().addCard(gameDeck.draw());
    // player1.getHand().addCard(gameDeck.draw());

    // Show the hand of cards after drawing
    std::cout << "\n== Player 1's Hand after drawing ==" << std::endl;
    std::cout << player1.getHand();

    // Step 6: Issue orders
    std::cout << "\n== Issuing orders for Player 1 ==" << std::endl;
    Order* attackOrder = new advanceOrder();  // Create an advance order
    player1.issueOrder(attackOrder);  // Player issues the advance order

    Order* defendOrder = new deployOrder();  // Create a deploy order
    player1.issueOrder(defendOrder);  // Player issues the deploy order

    // Step 7: Display the player's orders
    std::cout << "\n== Orders issued by Player 1 ==" << std::endl;
    player1.getOrders().showAllOrders();

    // Step 8: Print Player info (final check)
    std::cout << "\n== Final Player Info ==" << std::endl;
    player1.printPlayerInfo();

    // Clean up dynamically allocated memory
    delete attackOrder;
    delete defendOrder;
    delete territory1;
    delete territory2;
    delete territory3;
}

int main() {
    testPlayers();  // Call the test function
    return 0;
}
