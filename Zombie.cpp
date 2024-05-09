
#include "Zombie.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>

void Zombie::initTexture(std::string textureFilePath){
    this->texture.loadFromFile(textureFilePath);
}

bool Zombie::hasArrivedHome(){
    return this->sprite.getPosition().x < 150.f ;
}

float getRandomPosition(){
    int randomNumber = std::rand() % 5;
    //TODO: Set positions based on window size
    float possiblePosition[5] = {125.f,210.f,310.f,400.f,495.f};

    return possiblePosition[randomNumber];
}

void Zombie::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    this->sprite.setPosition(800.f,getRandomPosition());
}

Zombie::Zombie(std::string textureFilePath, float scale , float _movementSpeed, int _maxHealth , int _damage , int _hitRate){
    movementSpeed = _movementSpeed;
    maxHealth = _maxHealth;
    maxHealth = _maxHealth;
    damage = _damage;
    hitRate = _hitRate;
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

bool Zombie::isEating(){
    return this->eating;
}

void Zombie::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Zombie::render(sf::RenderTarget& target){
    target.draw(this->sprite);
}

sf::Sprite Zombie::getSprite(){
    return this->sprite;
}

void Zombie::startEating(Plant* plant){
    this->eating = true;
    if(hitRateClock.getElapsedTime().asSeconds() >= hitRate){
        plant->getDamage(damage);
        hitRateClock.restart();
    }

    if(plant->isDead())
        this->eating = false;

}

void Zombie::isNotEating(){
    this->eating = false;
}

