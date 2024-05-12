#ifndef Watermelon_HPP
#define Watermelon_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Watermelon {
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;
    float scale;
    int damage;
    bool hit;

public:
    Watermelon();
    void initTexture(const std::string& texturePath);
    void initSprite(float scale);
    void move(const float dirX , const float dirY);
    void render(sf::RenderTarget& target);
    void setPosition(float x, float y);
    bool isHit();
    void getHit();
    int getDamage();
    sf::Sprite getSprite();
};

#endif