#include "Plants.hpp"

Plant::Plant(int _damage, int _health, float _activationTime,const std::string& texturePath ,float _scale) 
    : damage(_damage), health(_health), activationTime(_activationTime),scale(_scale){
    initTexture(texturePath);
    initSprite();
    HaveRegularPea = false;
    HaveSnowPea = false;
    HaveSun = false;
}

void Plant::initTexture(const std::string& texturePath) {
    this->texture.loadFromFile(texturePath);
}

void Plant::initSprite() {
    this->sprite.setTexture(texture);
    this->sprite.scale(scale , scale);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Plant::render(sf::RenderTarget& target) {
    target.draw(sprite);
}

void Plant::setPosition(sf::Vector2f addr){
    this->sprite.setPosition(addr);
}

sf::Sprite Plant::getSprite(){
    return this->sprite;
}

bool Plant::isDead(){
    return this->health <= 0;
}

void Plant::getDamage(int damage){
    this->health -= damage;
}

bool Plant::isHaveRegularPea(){
    return HaveRegularPea;
}

bool Plant::isHaveSnowPea(){
    return HaveSnowPea;
}

bool Plant::isHaveSun(){
    return HaveSun;
}

sf::Vector2f Plant::getPeaAddr(){
    sf::Vector2f addr;
    addr = this->sprite.getPosition();
    addr.x += 20;
    addr.y -= 14;
    return addr;
}

sf::Vector2f Plant::getSunPos(){
    sf::Vector2f addr;
    addr = this->sprite.getPosition();
    addr.x += 15;
    addr.y += 30;
    return addr;
}

void Plant::assignCell(Cell* cell){
    this->cell = cell;
}

void Plant::makeCellEmpty(){
    this->cell->getEmpty();
}