#ifndef PLANTS_H
#define PLANTS_H

#include <SFML/Graphics.hpp>
#include "Cell.h"  // Assuming Cell class has necessary methods and attributes
#include "Projectiles.hpp"  // Assuming a Projectile class exists

class Plant {
protected:
    int damage;
    int health;
    int activationTime;  // Time it takes to activate or recharge
    sf::Vector2f position; // Position on the board
    int lastAttackTime;  // Time since last attack
    bool HaveRegularPea;
    bool HaveSnowPea;
    bool HaveSun;

    sf::Sprite sprite;
    sf::Texture texture;
    float scale;

    void initTexture(const std::string& texturePath);
    void initSprite();

public:
    Plant(int damage, int health, float activationTime, const std::string& texturePath ,float _scale);
    // bool takeDamage(int amount);
    virtual void update() = 0;
    void render(sf::RenderTarget& target);
    // bool canAttack() const;
    void setPosition(sf::Vector2f target);
    sf::Sprite getSprite();
    bool isDead();
    void getDamage(int damage);
    bool isHaveRegularPea();
    bool isHaveSnowPea();
    bool isHaveSun();
    sf::Vector2f getPeaAddr();
    sf::Vector2f getSunPos();
};

#endif
