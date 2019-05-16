#include "inputs.h"

// Check if a specified key is pressed
int isKeyPressed(char *key) {
    if (strcmp(key, "W") == 0 || strcmp(key, "w") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            return 1;
    }

    if (strcmp(key, "S") == 0 || strcmp(key, "s") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            return 1;
    }

    if (strcmp(key, "D") == 0 || strcmp(key, "d") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            return 1;
    }

    if (strcmp(key, "A") == 0 || strcmp(key, "a") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            return 1;
    }

    if (strcmp(key, "P") == 0 || strcmp(key, "p") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            return 1;
    }

    return 0;
}

// Get the mouse's current X position
int mousePositionX() {
    sf::Vector2i moVec = sf::Mouse::getPosition(window);
    return moVec.x;
}

// Get the mouse's current Y position
int mousePositionY() {
    sf::Vector2i moVec = sf::Mouse::getPosition(window);
    return moVec.y;
}

// Check if the mouse left click is pressed
bool mouseLeftClick() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
