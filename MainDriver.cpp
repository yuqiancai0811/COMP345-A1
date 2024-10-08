#include "Map.h"
#include "Player.h"
#include "Orders.h"
#include "Cards.h"
#include "GameEngine.h"

// Declaration of the test functions from each driver file
void testLoadMaps();
void testPlayers();
void testOrdersLists();
void testCards();
void testGameStates();

int main() {
    // Part 1: Test loading and validating maps
    testLoadMaps();   // test load USA.map and Europe.map, and print both loading result and validation result

    // test load USA.map, and print map detail.
    Map* map = map->loadMapFromFile("USA.map");
    
    std::vector<Continent*> continentsList;
    std::vector<Territory*> territoriesList;

    continentsList=map ->getContinents();
    for(Continent* continent : continentsList){
        continent->printContinentInfo();
    }

    territoriesList=map ->getTerritories();
    for(Territory* territory : territoriesList){
        territory ->printTerritoryInfo();
    }
    

    // Part 2: Test creating players and demonstrating their features
    testPlayers();

    // Part 3: Test creating and manipulating orders in an OrdersList
    testOrdersLists();

    // Part 4: Test creating a deck of cards and drawing/playing them
    testCards();

    // Part 5: Test navigating game states through console commands
    testGameStates();

    return 0;
}
