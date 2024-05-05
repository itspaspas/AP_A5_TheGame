
#include "Zombie.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>

void Zombie::initTexture(std::string textureFilePath){
    this->texture.loadFromFile(textureFilePath);
}

bool Zombie::hasArrivedHome(){
    return this->sprite.getPosition().x < 350.f ;
}

float getRandomPosition(){
    int randomNumber = std::rand() % 5;
    //TODO: Set positions based on window size
    float possiblePosition[5] = {230.f,380.f,550.f,710.f,890.f};

    return possiblePosition[randomNumber];
}

void Zombie::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    this->sprite.setPosition(1919.f,getRandomPosition());
}

Zombie::Zombie(std::string textureFilePath, float scale , float _movementSpeed, int _maxHealth , int _damage , int _hiRate){
    movementSpeed = _movementSpeed;
    maxHealth = _maxHealth;
    maxHealth = _maxHealth;
    damage = _damage;
    hiRate = _hiRate;
    health = _maxHealth;
    eating = false;
    freezing = false;
    freezing_counter = 0;
    freezing_time = 5;


    Zombie::initTexture(textureFilePath);
    initSprite(scale);
}

void Zombie::setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
}


void Zombie::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Zombie::render(sf::RenderTarget& target){
    target.draw(this->sprite);
}

