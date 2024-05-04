#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>

#ifndef Sun_H
#define Sun_H

class Sun{
private:
    int speed;
    int interval;
    sf::Sprite sprite;
    sf::Texture texture;
    void initTexture();
    void initSprite();
    void setPosition(float x, float y);
public:
    Sun();
    bool hasArrivedToDown();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
};

// float getRandomPosition();

#endif