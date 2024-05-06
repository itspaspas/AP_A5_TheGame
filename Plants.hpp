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
    float scale;

    void loadTexture() {
        if (!texture.loadFromFile(texturePath)) {
            std::cerr << "Failed to load texture from path: " << texturePath << std::endl;
        }
        sprite.setTexture(texture);
        this->sprite.scale(scale, scale);
        this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    }

public:

    Plant(const std::string& path, int hp ,float _scale) : texturePath(path), health(hp), maxHealth(hp) , scale(_scale){
        loadTexture();
    }

    void setPosition(sf::Vector2f addr){
        this->sprite.setPosition(addr);
    }

    virtual void act() = 0; // Perform the plant's action (e.g., shoot, produce sun)
    virtual void update() = 0; // Update method for animations or state changes
    virtual void render(sf::RenderTarget& target) {
        target.draw(sprite);
    }
};

#endif