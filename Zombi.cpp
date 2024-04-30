
#include "Zombi.h"

void Zombi::initTexture(){
    this->texture.loadFromFile("extrafile/Zombi.png");
}

void Zombi::initSprite(){
    this->sprite.setTexture(this->texture);

    //resize the sprite
    this->sprite.scale(0.35f,0.35f);
    this->sprite.setPosition(3000,500);
}

Zombi::Zombi(){
    this->movementSpeed = 2.f;
    this->initTexture();
    this->initSprite();
}

void Zombi::setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
}

Zombi::~Zombi(){



}

void Zombi::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Zombi::update(){



}
void Zombi::render(sf::RenderTarget& target){

    target.draw(this->sprite);
}

