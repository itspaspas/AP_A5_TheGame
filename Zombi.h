#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombi{

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;

    void initTexture(std::string textureFilePath);
    void initSprite(float scale);
    void setPosition(float x, float y);
public:
    Zombi(std::string textureFilePath, float scale);

    bool hasArrivedHome();
    void update();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
};

float getRandomPosition();

#endif