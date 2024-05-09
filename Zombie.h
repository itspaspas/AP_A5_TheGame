#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>
#include"Plants.hpp"

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Plant;

class Zombie{

private:
    int damage;
    int maxHealth;
    int health;
    int hitRate;
    float movementSpeed;
    bool eating;
    bool freezing;
	int freezing_time;
	int freezing_counter;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock hitRateClock;
    void initTexture(std::string textureFilePath);
    void initSprite(float scale);
    void setPosition(float x, float y);
public:
    Zombie(std::string textureFilePath, float scale ,float _movementSpeed, int maxHealth , int damage , int hiRate);
    bool hasArrivedHome();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
    bool isEating();
    sf::Sprite getSprite();
    void startEating(Plant* plant);
    void isNotEating();
};

float getRandomPosition();

#endif