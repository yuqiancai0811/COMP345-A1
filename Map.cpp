
#include "Map.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

// Territory class methods

Territory::Territory(std::string name, int x, int y, std::string continent, const std::vector<std::string>& adjNames) : name(name), x(x), y(y), continent(continent), adjacentTerritoryNames(adjNames) {}
    //Constructor(Name + X + Y + Continent + vertor (adjacentTerritoryNames) );

Territory::~Territory() {}

void Territory::addAdjacentTerritory(Territory* territory) {
    adjacentTerritories.push_back(territory);
}

std::string Territory::getName() const {return name;};
std::string Territory::getOwner() const {return owner;};
std::string Territory::getContinent() const {return continent;};
std::vector<std::string> Territory::getAdjacentTerritoryNames() const {return adjacentTerritoryNames;};
std::vector<Territory*> Territory::getAdjacentTerritories() const {return adjacentTerritories;};

void Territory::printTerritoryInfo() const {
    std::cout << "Territory: " << name << " (" << x << ", " << y << ") in " << continent
              << ". Adjacent territories: ";
    for (Territory* adj : adjacentTerritories) {
        std::cout << adj->getName() << " ";
    }
    std::cout << std::endl;
}

// Continent class methods

Continent::Continent(std::string name, int controlValue)
    : name(name), controlValue(controlValue) {}


void Continent::addTerritory(Territory* territory) {
    continents_Territory.push_back(territory);
}

std::vector<Territory*> Continent::getTerritories() const {
    return continents_Territory;
}

std::string Continent::getName() const {
    return name;
}

int Continent::getControlValue() const {
    return controlValue;
}

void Continent::printContinentInfo() const {
    std::cout << "Continent: " << name << " has control value: " << controlValue << std::endl;
    std::cout << "Territories in this continent: ";
    for (Territory* territory : continents_Territory) {
        std::cout << territory->getName() << " ";
    }
    std::cout << std::endl;
}

// Map class methods
Map::Map() : author("Nan"), warn("Nan"), image("Nan"), wrap("Nan"), horizontal("Nan") {}

Map::~Map() {}

void Map::setAuthor(const std::string& newAuthor) { author = newAuthor; }
void Map::setWarn(const std::string& newWarn) { warn = newWarn; }
void Map::setImage(const std::string& newImage) { image = newImage; }
void Map::setWrap(const std::string& newWrap) { wrap = newWrap; }
void Map::setHorizontal(const std::string& newHorizontal) { horizontal = newHorizontal; }

std::string Map::getAuthor() const { return author; }
std::string Map::getWarn() const { return warn; }
std::string Map::getImage() const { return image; }
std::string Map::getWrap() const { return wrap; }
std::string Map::getHorizontal() const { return horizontal; }

void Map::addTerritory(Territory* territory) {
    territories.push_back(territory);
}

void Map::addContinent(Continent* continent) {
    continents.push_back(continent);
}

std::vector<Continent*> Map::getContinents() const {
    return continents;
}

std::vector<Territory*> Map::getTerritories() const {
    return territories;
}

bool Map::isConnectedGraph() const {
    if (territories.empty()) return true;

    std::vector<bool> visited(territories.size(), false);
    std::vector<Territory*> stack;
    stack.push_back(territories[0]);

    // Perform DFS to check if all territories are reachable
    while (!stack.empty()) {
        Territory* current = stack.back();
        stack.pop_back();

        int index = std::distance(territories.begin(), std::find(territories.begin(), territories.end(), current));
        if (!visited[index]) {
            visited[index] = true;

            for (Territory* adj : current->getAdjacentTerritories()) {
                int adjIndex = std::distance(territories.begin(), std::find(territories.begin(), territories.end(), adj));
                if (!visited[adjIndex]) {
                    stack.push_back(adj);
                }
            }
        }
    }

    // Check if all territories are visited
    return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

bool Map::areContinentsConnected() const {
    for (const Continent* continent : continents) {
        std::vector<Territory*> territoriesInContinent = continent->getTerritories();

        if (territoriesInContinent.empty()) continue;

        std::vector<bool> visited(territoriesInContinent.size(), false);
        std::vector<Territory*> stack;
        stack.push_back(territoriesInContinent[0]);

        // Perform DFS to check if all territories in this continent are connected
        while (!stack.empty()) {
            Territory* current = stack.back();
            stack.pop_back();

            int index = std::distance(territoriesInContinent.begin(), std::find(territoriesInContinent.begin(), territoriesInContinent.end(), current));
            if (!visited[index]) {
                visited[index] = true;

                for (Territory* adj : current->getAdjacentTerritories()) {
                    if (adj->getContinent() == continent->getName()) {
                        int adjIndex = std::distance(territoriesInContinent.begin(), std::find(territoriesInContinent.begin(), territoriesInContinent.end(), adj));
                        if (!visited[adjIndex]) {
                            stack.push_back(adj);
                        }
                    }
                }
            }
        }

        // Check if all territories in the continent are visited
        if (!std::all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
            return false;
        }
    }

    return true;
}

bool Map::territoryBelongsToOneContinentsConnected() const {
    for (Territory* territory : territories) {
        int continentCount = 0;
        for (const Continent* continent : continents) {
            const std::vector<Territory*>& territoriesInContinent = continent->getTerritories();
            if (std::find(territoriesInContinent.begin(), territoriesInContinent.end(), territory) != territoriesInContinent.end()) {
                continentCount++;
            }
        }

        // If a territory belongs to more than one continent, return false
        if (continentCount != 1) {
            return false;
        }
    }

    return true;
}

bool Map::validate() const {
    return isConnectedGraph() && areContinentsConnected() && territoryBelongsToOneContinentsConnected();
}
