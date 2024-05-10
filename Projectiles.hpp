#ifndef PROJECTILES_HPP
#define PROJECTILES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Projectile {
protected:
    sf::Sprite sprite;
    sf::Texture texture;  // Texture needs to be a member to ensure it persists
    float movementSpeed;
    float scale;

public:
    Projectile(const std::string& texturePath, float _movementSpeed, float scale){
        initTexture(texturePath);
        initSprite(scale);
        movementSpeed = _movementSpeed;
    }

    void initTexture(const std::string& texturePath){
        this->texture.loadFromFile(texturePath);
    }

    void initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

    void move(const float dirX , const float dirY){
        this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
    }

    void render(sf::RenderTarget& target) {
        target.draw(this->sprite);
    }

    void setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
    }

    bool isOffScreen(int screenWidth) {
        return sprite.getPosition().x > screenWidth || sprite.getPosition().x < 0;
    }
};

#endif