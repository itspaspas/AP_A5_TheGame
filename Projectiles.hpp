#ifndef PROJECTILES_HPP
#define PROJECTILES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Projectile {
protected:
    sf::Sprite sprite;
    sf::Texture texture;  // Texture needs to be a member to ensure it persists
    sf::Vector2f velocity;
    float scale;

public:
    Projectile(const std::string& texturePath, sf::Vector2f position, sf::Vector2f velocity, float scale)
        : velocity(velocity) {     
        // sprite.setRadius(radius);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(scale,scale);
    }

    virtual ~Projectile() {}

    virtual void move() {
        sprite.move(velocity);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }

    sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }

    bool isOffScreen(int screenWidth) {
        return sprite.getPosition().x > screenWidth || sprite.getPosition().x < 0;
    }
};

#endif