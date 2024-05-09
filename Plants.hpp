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

    sf::Sprite sprite;
    sf::Texture texture;
    float scale;

    void initTexture(const std::string& texturePath);
    void initSprite();

public:
    Plant(int damage, int health, float activationTime, const std::string& texturePath ,float _scale);
    virtual ~Plant();

    // virtual void attack(std::vector<Projectile>& projectiles) = 0;  // Pure virtual function for attacking
    bool takeDamage(int amount);
    void update(const sf::Time& dt);
    void render(sf::RenderTarget& target);
    bool canAttack() const;
    void setPosition(sf::Vector2f target);
};

#endif
