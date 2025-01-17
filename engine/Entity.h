#ifndef ENTITY_H
#define ENTITY_H

#include "Map.h"

extern unsigned int currentID;

class Entity {
    public:
        Entity(int posx, int posy, bool colCircle, int radius);
        ~Entity();
        void setTexture(char *texturePath);
        void setPosition(int posx, int posy);
        void setTile(Tile* tile);
        void move(int movex, int movey);
        void movef(int numx, int denx, int numy, int deny);

        Tile* tile;
        friend class Map;
        float x;
        float y;
        unsigned int id;
        int radius;
        char *texture;
        bool colCircle;
};

int createEntity(int posx, int posy, int radius);
void move(int id, int posx, int posy);
void movef(int id, int numx, int denx, int numy, int deny);
void setTexture(unsigned int id, char *texturePath);
int getEntityPositionX(int entID);
int getEntityPositionY(int entID);

#else
class Entity;
#endif
