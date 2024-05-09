
#include "sun.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>


void Sun::initTexture(){
    this->texture.loadFromFile("extrafile/sun.png");
}

bool Sun::hasArrivedToDown(){
    return this->sprite.getPosition().y > 600.f ;
}

void Sun::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(.15f, .15f);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

Sun::Sun(){
    speed = 2;
    this->initTexture();
    this->initSprite();
    this->setPosition(150 + static_cast<float>(rand() % static_cast<int>(500)) ,0.f);
}

void Sun::setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
}


void Sun::move(const float dirX , const float dirY){
    this->sprite.move(this->speed * dirX ,this->speed * dirY);
}

void Sun::render(sf::RenderTarget& target){
    target.draw(this->sprite);
}

const sf::Sprite& Sun::getSprite() const{
    return sprite;
}
