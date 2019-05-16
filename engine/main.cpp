#include "main.h"

extern Map demoMap;

// Initialize the game engine with resolution, tile size, and window title
void init(int resX, int resY, int tileSize, char *title) {
    window.create(sf::VideoMode(resX, resY), title);
    currentID = 0;
    int tileX = ceil((float) resX / tileSize);
    int tileY = ceil((float) resY / tileSize);
    demoMap = *(new Map(tileSize, tileX, tileY));
}

// Close the window
void close() {
    window.close();
}

// CHeck if the window is open
bool isOpen() {
    return window.isOpen();
}

// Handle inputs
void systemEventHandler() {
    sf::Event event;
    while (window.pollEvent(event)) {
        // Close the game with ESC key
        if (event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && event.key.code == sf::Keyboard::Escape))
            close();
    }
}
