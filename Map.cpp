#include "Map.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

class Territory {
    private:
    int x,y;
    int armies;
    std::string name;
    std::string owner;
    std::string continent;
    std::vector<std::string> adjacentTerritoryNames;
    std::vector<Territory*> adjacentTerritories;


    public:

    Territory::Territory(std::string name, int x, int y, std::string continent, const std::vector<std::string>& adjNames) : name(name), x(x), y(y), continent(continent), adjacentTerritoryNames(adjNames) {}
    //Constructor(Name + X + Y + Continent + vertor (adjacentTerritoryNames) );

    Territory::~Territory() {}

    void setOwner(const std::string& newOwner){owner=newOwner;};
    void setArmies(int numArmies){armies=numArmies;};
    void Territory::addAdjacentTerritory(Territory* territory) {adjacentTerritories.push_back(territory);}
    //Set method;

    int getArmies() const {return armies;};
    std::string getName() const {return name;};
    std::string getOwner() const {return owner;};
    std::string getContinent() const {return continent;};
    std::vector<std::string> getAdjacentTerritoryNames() const {return adjacentTerritoryNames;};
    std::vector<Territory*> getAdjacentTerritories() const {return adjacentTerritories;};
    //Get method;

    void Territory::printTerritoryInfo() const {
    std::cout << "Territory: " << name << " (" << x << ", " << y << ") in " << continent
              << ". Adjacent territories: ";
    for (Territory* adj : adjacentTerritories) {
        std::cout << adj->getName() << " ";
    }
    std::cout << std::endl;
}

};

class Continent{
    
    private:
    std::string name;
    int controlValue;
    std::vector<std::string> continents_TerritoryNames;
    std::vector<Territory*> continents_Territory;

    public:
    Continent::Continent(std::string name, int controlValue) 
        : name(name), controlValue(controlValue) {}

    Continent::~Continent() {}

    // Add Territory to Continent
    void Continent::addTerritory(Territory* territory) {
        continents_Territory.push_back(territory);
    }

    // Return all the Territory(Territory pointer) in Continent
    std::vector<Territory*> Continent::getTerritories() const {
        return continents_Territory;
    }

    // Return all the Territory's name in Continent
    std::string Continent::getName() const {return name;}


    int Continent::getControlValue() const {return controlValue;}

    // Print function
    void Continent::printContinentInfo() const {
        std::cout << "Continent: " << name << " with control value: " << controlValue << std::endl;
        std::cout << "Territories in " << name << ": ";
        
        for (Territory* territory : continents_Territory) {
            std::cout << territory->getName() << " ";
        }
        
        std::cout << std::endl;}

};


class Map {
private:
    std::string author;
    std::string warn;
    std::string image;
    std::string wrap;
    std::string horizontal;

    std::vector<Territory*> territories;
    std::vector<Continent*> continents;

    bool isConnectedGraph() const;
    bool areContinentsConnected() const;

public:
    Map() : author("Nan"), warn("Nan"), image("Nan"), wrap("Nan"), horizontal("Nan") {};
    ~Map();

    // Set functions
    void setAuthor(const std::string& newAuthor) { author = newAuthor; }
    void setWarn(const std::string& newWarn) { warn = newWarn; }
    void setImage(const std::string& newImage) { image = newImage; }
    void setWrap(const std::string& newWrap) { wrap = newWrap; }
    void setHorizontal(const std::string& newHorizontal) { horizontal = newHorizontal; }

    // Get functions
    std::string getAuthor() const { return author; }
    std::string getWarn() const { return warn; }
    std::string getImage() const { return image; }
    std::string getWrap() const { return wrap; }
    std::string getHorizontal() const { return horizontal; }

    void addTerritory(Territory* territory);
    void addContinent(Continent* continent);

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

    }

    bool Map::territoryBelongsToOneContinentsConnected() const {
        // each country belongs to one and only one continent
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

};