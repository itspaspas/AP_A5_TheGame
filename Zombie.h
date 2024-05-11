#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>
#include"Plants.hpp"
#include "Projectiles.hpp"

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Plant;

class Zombie{

private:
    int damage;
    int maxHealth;
    int health;
    int hitRate;
    int row;
    float movementSpeed;
    bool eating;
    bool freezing;
	int freezing_time;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock hitRateClock;
    sf::Clock freezeTimer;
    // int numRow;
    void initTexture(std::string textureFilePath);
    void initSprite(float scale);
    void setPosition(float x, float y);
    float getRandomPosition();
public:
    Zombie(std::string textureFilePath, float scale ,float _movementSpeed, int maxHealth , int damage , int hiRate);
    bool hasArrivedHome();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
    bool isEating();
    sf::Sprite getSprite();
    void startEating(Plant* plant);
    void isNotEating();
    void hitByPea(Projectile* pea);
    void upDate();
    bool isDead();
    bool isInSameLine(sf::Vector2f addr);
};

float getRandomPosition();

#endif