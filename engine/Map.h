#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Tile.h"
#include "Entity.h"
#include "Sound.h"
#include "Music.h"

class Map {
    public:
        Map(int tileSize = 0, int tileX = 0, int tileY = 0);
        void addEntity(Entity* entity);
        void addEntity(Entity* entity, Tile* tile);
        void removeEntity(Entity* entity);
        int entityListSize();
        Tile* accessTile(int x, int y);
        Entity* getEntityByID(unsigned int entityID);

        std::vector<Tile*> tileList;
        std::list<Entity*> entityList;
        int tileSize;
        int tileX;
        int tileY;
        char *background;
};

void remEntity(int entID);
void createMap(int tileSize, int tileX, int tileY);

#else
class Map;
#endif
