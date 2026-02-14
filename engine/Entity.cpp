#include "Entity.h"

// Reference global objects
extern Map demoMap;
unsigned int currentID;

// Create an Entity with position and radius, default shape as a circle
Entity::Entity(int posx, int posy, bool colCircle, int radius) {
    // Convert to floats for precision
    x = (float) posx;
    y = (float) posy;
    this->colCircle = colCircle;
    this->radius = radius;
    // Add Entity to global entityList
    demoMap.addEntity(this);
}

// Associate an Entity with a texture
void Entity::setTexture(char *texturePath) {
    texture = texturePath;
}

// Set the Entity's position
void Entity::setPosition(int posx, int posy) {
    x = (float) posx;
    y = (float) posy;
}

// Set the Entity's tile it's located in
void Entity::setTile(Tile* tile) {
    this->tile = tile;
}

// Move the Entity an X and a Y direction
void Entity::move(int movex, int movey) {
    x += (float) movex;
    y += (float) movey;
}

// Move the Entity an X and a Y direction precisely
void Entity::movef(int numx, int denx, int numy, int deny) {
    x += (float) numx / (float) denx;
    y += (float) numy / (float) deny;
}

// C++ wrappers
int createEntity(int posx, int posy, int radius) {
    Entity *entity = new Entity(posx, posy, true, radius);
    entity->id = currentID;
    return currentID++;
}

void move(int id, int posx, int posy) {
    Entity *tmp = demoMap.getEntityByID(id);
    tmp->move(posx, posy);
}

void movef(int id, int numx, int denx, int numy, int deny) {
    Entity *tmp = demoMap.getEntityByID(id);
    tmp->movef(numx, denx, numy, deny);
}

void setTexture(unsigned int id, char *texturePath) {
    Entity *tmp = demoMap.getEntityByID(id);
    tmp->setTexture(texturePath);
}

// Get Entity's X position
int getEntityPositionX(int entID) {
    Entity *tmp = demoMap.getEntityByID(entID);
    return tmp->x;
}

// Get Entity's Y position
int getEntityPositionY(int entID) {
    Entity *tmp = demoMap.getEntityByID(entID);
    return tmp->y;
}