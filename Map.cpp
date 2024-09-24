#include "Map.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>

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
    Map();
    ~Map();

    void addTerritory(Territory* territory);
    void addContinent(Continent* continent);

    bool validate() const;

};