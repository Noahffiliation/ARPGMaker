#include "render.h"

// Reference global objects
extern Map demoMap;

sf::RenderWindow window;
std::queue<sf::Sprite*> buffer;
std::unordered_map<char *, sf::Texture> textureHash;

// Displays drawn objects to the screen
void display() {
    window.display();
}

// Stores a Texture object in the global textureHash
void loadTexture(char *filePath) {
    sf::Texture tex;
    std::string fp(filePath);
    if (!tex.loadFromFile(fp)) {
        std::cout << "Error: Couldn't load file " << filePath << std::endl;
        return;
    }
    textureHash[filePath] = tex;
}

// FIXME: Doesn't work as intended
// Load multiple textures from a text file
void loadTexturesFromFile(char *filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        char *tmp = strdup(line.c_str());
        loadTexture(tmp);
    }
}

// Set the background tile texture
void setBackground(char *filePath) {
    for (int i = 0; i < (int) demoMap.tileList.size(); i++) {
        demoMap.tileList[i]->setTexture(filePath);
    }
}

// Attach each Tile texture to a Sprite and position
void renderBackground() {
    for (int i = 0; i < (int) demoMap.tileList.size(); i++) {
        sf::Sprite *tile = new sf::Sprite(textureHash[demoMap.tileList[i]->texture]);
        // Calculate tile position
        int x = demoMap.tileList[i]->ID % demoMap.tileX * demoMap.tileSize;
        int y = demoMap.tileList[i]->ID / demoMap.tileX * demoMap.tileSize;
        tile->setPosition(x, y);
        // Add to draw buffer
        buffer.push(tile);
    }
}

// Attach a texture to a Sprite and add to draw buffer
void renderImage(char *filePath) {
    buffer.push(new sf::Sprite(textureHash[filePath]));
}

// Attach the Entity's texture to a Sprite, set its position, and add to draw buffer
void renderEntity(unsigned int id) {
    Entity *tmp = demoMap.getEntityByID(id);
    sf::Sprite *entity = new sf::Sprite(textureHash[tmp->texture]);
    entity->setPosition(tmp->x, tmp->y);
    buffer.push(entity);
}

// Attach each Entity's texture to a Sprite, set their positions, and add them to draw buffer
void renderEntities() {
    for (std::list<Entity*>::iterator it = demoMap.entityList.begin(); it != demoMap.entityList.end(); ++it) {
        sf::Sprite *entity = new sf::Sprite(textureHash[(*it)->texture]);
        entity->setPosition((*it)->x, (*it)->y);
        buffer.push(entity);
    }
}

// Draw everything in the draw buffer
void draw() {
    while (!buffer.empty()) {
        window.draw(*buffer.front());
        delete buffer.front();
        buffer.pop();
    }
}

// Clear all drawn objects
void clear() {
    window.clear(sf::Color::Black);
}