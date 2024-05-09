#include "Plants.hpp"

Plant::Plant(int _damage, int _health, float _activationTime, Cell* _cell, const std::string& texturePath) 
    : damage(_damage), health(_health), activationTime(_activationTime), occupiedCell(_cell), lastAttackTime(0) {
    if (_cell != nullptr) {
            position = occupiedCell->getCellMidPosition();
    }
    initTexture(texturePath);
    initSprite();
}

Plant::~Plant() {
    // Handle any necessary cleanup
}

void Plant::initTexture(const std::string& texturePath) {
    texture.loadFromFile(texturePath);
}

void Plant::initSprite() {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

bool Plant::takeDamage(int amount) {
    health -= amount;
    (health <= 0) ? true : false;
}

void Plant::update(const sf::Time& dt) {
    lastAttackTime += dt.asSeconds();
}

void Plant::render(sf::RenderTarget& target) {
    target.draw(sprite);
}

bool Plant::canAttack() const {
    return lastAttackTime >= activationTime;
}

void Plant::setPosition(sf::Vector2f target){
    position = target;
}
