#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"
#include <string>

class MapDriver {
public:
    static Map* loadMapFromFile(const std::string& filename);
};

#endif