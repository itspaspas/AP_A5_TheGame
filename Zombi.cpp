
#include "Zombi.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>

void Zombi::initTexture(std::string textureFilePath){
    this->texture.loadFromFile(textureFilePath);
}

bool Zombi::hasArrivedHome(){
    return this->sprite.getPosition().x < 350.f ;
}

float getRandomPosition(){

    
    int randomNumber = std::rand() % 5;

    float possiblePosition[5] = {230.f,380.f,550.f,710.f,890.f};

    return possiblePosition[randomNumber];
}

void Zombi::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    //resize the sprite
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    this->sprite.setPosition(1919.f,getRandomPosition());
}

Zombi::Zombi(std::string textureFilePath, float scale){
    movementSpeed = .6f;
    Zombi::initTexture(textureFilePath);
    initSprite(scale);
}

void Zombi::setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
}


void Zombi::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Zombi::update(){



}
void Zombi::render(sf::RenderTarget& target){

    target.draw(this->sprite);
}

