#include "Map.h"
#include <queue>
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