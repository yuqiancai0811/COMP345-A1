#include <fstream>
#include <vector>
#include <iostream>
#include "MapDriver.h"
#include <sstream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include "Map.h"



bool testLoadMaps(){
    std::vector<std::string> filename;
    filename.push_back("USA.map");
    bool result = true;
    


    for(const std::string& filename : filename){
        Map* loadmap= loadmap ->loadMapFromFile(filename);
        bool result = result && loadmap ->validate();
    }

    return result;
} 

int main() {
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

    bool mapTestResult = testLoadMaps();
    std::cout << mapTestResult << std::endl;
    



    return 0;
}