#ifndef RENDER_H
#define RENDER_H

#include <queue>
#include <unordered_map>
#include <string.h>
#include <fstream>
#include <iostream>

#include "Map.h"

extern sf::RenderWindow window;
extern std::queue<sf::Sprite*> buffer;
extern std::unordered_map<char *, sf::Texture> textureHash;

void display();
void loadTexture(char *filePath);
void loadTexturesFromFile(char *filePath);
void setBackground(char *filePath);
void renderBackground();
void renderImage(char *filePath);
void renderEntity(unsigned int id);
void renderEntities();
void draw();
void clear();

#endif
