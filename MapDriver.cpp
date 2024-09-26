
#include "Map.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "MapDriver.h"

Map* MapDriver::loadMapFromFile(const std::string& filename) {
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return nullptr;
    }

    
    
    Map* map = new Map();


    std::string line;
    std::string section;
    
    // temp Territory pointer list for Add each Adjacent Territory
    std::vector<Territory*> tempTerritories;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        // Check section part in the map file
        if (line[0] == '[') {
            section = line;
            continue;
        }

        // switch case with different secton
        
        //   MAP Section
        if (section == "[Map]") {
            std::istringstream input(line);
            if (line.find("author=") == 0) {
                map->setAuthor(line.substr(7));  // update map's author
            } else if (line.find("image=") == 0) {
                map->setImage(line.substr(6)) ;   // update map's image
            } else if (line.find("wrap=") == 0) {
                map->setWrap(line.substr(5));    // update map's wrap type
            } else if (line.find("scroll=") == 0) {
                map->setHorizontal(line.substr(7)) ;  // update map's Horizontal type
            } else if (line.find("warn=") == 0) {
                map->setWarn(line.substr(5));    // update map's warn type
            }
        }
        
        //   Continents Section
        else if (section == "[Continents]") {
            std::istringstream string(line);
            std::string name;
            int controlValue;
            
            // read what befor'=' assign to name, the rest to controlValue
            if (std::getline(string, name, '=') && string >> controlValue) {
            map->addContinent(new Continent(name, controlValue));
}
        }
        
        
        //    Territories Section
        else if (section == "[Territories]") {
            std::istringstream string(line);
            std::string name, continent, adj;
            int x, y;

            // Read input line from the file 
            if (std::getline(string, name, ',') && string >> x && string.ignore() && string >> y && string.ignore() && std::getline(string, continent, ',')) {
                std::vector<std::string> adjNames;

                // Add adjacent Territory Names
                while (std::getline(string, adj, ',')) {
                    adjNames.push_back(adj);
                }

                // creat territory and add the territory to Map. 
                Territory* territory = new Territory(name, x, y, continent, adjNames);
                map->addTerritory(territory);
                tempTerritories.push_back(territory);  //And temp store the territory.
            }
        }
    }

    // Add each Adjacent Territory's pointer to each of the Territory
    for (Territory* territory : tempTerritories) {
        std::vector<std::string> adjNames = territory->getAdjacentTerritoryNames();
        for (const std::string& adjName : adjNames) {
            for (Territory* potentialAdj : tempTerritories) {
                if (potentialAdj->getName() == adjName) {
                    territory->addAdjacentTerritory(potentialAdj);  
                    break;
                }
            }
        }
    }

    file.close();
    return map;
}