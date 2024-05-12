#include "Watermelon.hpp"

Watermelon::Watermelon(){
    initTexture("extrafile/watermelon.png");
    initSprite(.3f);
    movementSpeed = 1;
    damage = 15;
    hit = false;
}

void Watermelon::initTexture(const std::string& texturePath){
    this->texture.loadFromFile(texturePath);
}

void Watermelon::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void Watermelon::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Watermelon::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Watermelon::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

sf::Sprite Watermelon::getSprite(){
    return this->sprite;
}

bool Watermelon::isHit(){
    return hit;
}

void Watermelon::getHit(){
    this->hit = true;
}

int Watermelon::getDamage(){
    return this->damage;
}
