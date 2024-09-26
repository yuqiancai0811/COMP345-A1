#include <string>
#include <vector>

class Territory {
    private:
    int x,y;
    int armies;
    std::string name;
    std::string owner;
    std::string continent;
    std::vector<std::string> adjacent_TerritoryNames;
    std::vector<Territory*> adjacent_Territories;


    public:

    Territory(std::string name, int x, int y, std::string continent, const std::vector<std::string>& adjNames); //Constructor(Name + X + Y + Continent + vertor (adjacentTerritoryNames) );
    ~Territory();

    void setOwner(const std::string& owner);
    void setArmies(int numArmies);
    void addAdjacentTerritory(Territory* territory);
    //Set functions;

    int getArmies() const;
    std::string getName() const;
    std::string getOwner() const;
    std::string getContinent() const;
    std::vector<std::string> getAdjacentTerritoryNames() const;
    std::vector<Territory*> getAdjacentTerritories() const;
    //Get functions;

    void printTerritoryInfo() const;  // print function

};


class Continent {
    private:
    std::string name;
    int controlValue;
    std::vector<std::string> continents_TerritoryNames;
    std::vector<Territory*> continents_Territory;
    

    public:
    Continent(std::string name, int controlValue);//Constructor(Name + controlValue );
    ~Continent();
    
    void addTerritory(Territory* territory);

    std::vector<Territory*> getTerritories() const;
    std::string getName() const;
    int getControlValue() const;
    //Get functions;

    void printContinentInfo() const;  // print function

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
    Map::Map() : author("Nan"), warn("Nan"), image("Nan"), wrap("Nan"), horizontal("Nan") {}
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
    Map testLoadMaps(std::string filename);

    bool Map::isConnectedGraph() const {
        // the map is a connected graph；
    }

    bool Map::areContinentsConnected() const {
        // continents are connected subgraphs
    }

    bool Map::territoryBelongsToOneContinentsConnected() const {
        // each country belongs to one and only one continent
    }

    bool Map::validate() const {
        return isConnectedGraph() && areContinentsConnected() && territoryBelongsToOneContinentsConnected();
    }
};