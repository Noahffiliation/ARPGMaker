#include "Map.h"

// Create a Map object
Map::Map(int tileSize, int tileX, int tileY) {
    this->tileSize = tileSize;
    this->tileX = tileX;
    this->tileY = tileY;
    // Add tiles to Map object
    for (int y = 0; y < tileY; y++) {
        for (int x = 0; x < tileX; x++) {
            tileList.push_back(new Tile(tileSize, y * tileX + x));
        }
    }
}

// Add an Entity to the Map object
void Map::addEntity(Entity* entity) {
    int tempX = entity->x / tileSize;
    int tempY = entity->y / tileSize;
    // Associate an Entity with a Tile
    Tile* tile = this->accessTile(tempX, tempY);
    this->addEntity(entity, tile);
}

// Add an Entity to the Map's entityList
void Map::addEntity(Entity* entity, Tile* tile) {
    entity->setTile(tile);
    this->entityList.push_back(entity);
}

// Remove an Entity from the Map's entityList
void Map::removeEntity(Entity* entity) {
    this->entityList.remove(entity);
}

// Get entityList size
int Map::entityListSize() {
    return this->entityList.size();
}

// Access a specific tile by position
Tile* Map::accessTile(int x, int y) {
    return tileList[y*(this->tileX) + x];
}

// Get an Entity by ID
Entity* Map::getEntityByID(unsigned int entityID) {
    for (std::list<Entity*>::iterator it=entityList.begin(); it != entityList.end(); ++it) {
        if ((*it)->id == entityID) {
            return *it;
        }
    }

    return NULL;
}

// C++ wrappers
// Remove an Entity from the Map's entityList
void remEntity(int entID) {
    Entity *tmp = demoMap.getEntityByID(entID);
    demoMap.removeEntity(tmp);
}

void createMap(int tileSize, int tileX, int tileY) {
    Map *map = new Map(tileSize, tileX, tileY);
    demoMap = *map;
}

Map demoMap;
