#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombi{

private:
    int damage;
    int maxHealth;
    int health;
    int hiRate;
    float movementSpeed;
    bool eating;
    bool freezing;
	int freezing_time;
	int freezing_counter;
    sf::Sprite sprite;
    sf::Texture texture;
    void initTexture(std::string textureFilePath);
    void initSprite(float scale);
    void setPosition(float x, float y);
public:
    Zombi(std::string textureFilePath, float scale ,float _movementSpeed, int maxHealth , int damage , int hiRate);
    bool hasArrivedHome();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
};

float getRandomPosition();

#endif