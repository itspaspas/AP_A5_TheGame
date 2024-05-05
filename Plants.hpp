#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifndef PLANTS_HPP
#define PLANTS_HPP

class Plant {
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    std::string texturePath;
    int health;
    int maxHealth;

    void loadTexture() {
        if (!texture.loadFromFile(texturePath)) {
            // Handle error
            std::cerr << "Failed to load texture from path: " << texturePath << std::endl;
        }
        sprite.setTexture(texture);
    }

public:
    Plant(const std::string& path, int hp) : texturePath(path), health(hp), maxHealth(hp) {
        loadTexture();
    }

    virtual void act() = 0; // Perform the plant's action (e.g., shoot, produce sun)
    virtual void update() = 0; // Update method for animations or state changes
    virtual void render(sf::RenderTarget& target) {
        target.draw(sprite);
    }
};

#endif