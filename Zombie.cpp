
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

float Zombie::getRandomPosition(){
    int randomNumber = std::rand() % 5;
    this->row = randomNumber + 1;
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
    damage = _damage;
    hitRate = _hitRate;
    health = _maxHealth;
    eating = false;
    freezing = false;
    freezing_time = 0;


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
    if(freezing){
        this->sprite.move((this->movementSpeed/2) * dirX ,(this->movementSpeed/2) * dirY);
    }
    else{
        this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
    }
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

void Zombie::hitByPea(Projectile* pea){
    this->freezing_time += pea->getSnowTime();
    this->health -= pea->getDamage();
}

void Zombie::upDate(){
    if (freezeTimer.getElapsedTime().asSeconds() < freezing_time) {
        this->freezing = true;
    }
    else {
        this->freezing = false;
        freezing_time = 0;
        freezeTimer.restart();
    }
}

bool Zombie::isDead(){
    return this->health <= 0;
}

bool Zombie::isInSameLine(sf::Vector2f addr){
    int beginOfCell = 90 + ((row-1)*92);
    int endOfCell = 90 + (row * 92);
    return (addr.y > beginOfCell) && (addr.y < endOfCell);
}