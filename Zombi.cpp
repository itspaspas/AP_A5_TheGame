
#include "Zombi.h"
#include <cstdlib>
#include <ctime> 

void Zombi::initTexture(){
    this->texture.loadFromFile("extrafile/Zombi.png");
}

bool Zombi::hasArrivedHome(){
    return this->sprite.getPosition().x < 350.f ;
}

float getRandomPosition(){

    
    int randomNumber = std::rand() % 5;

    float possiblePosition[5] = {230.f,380.f,550.f,710.f,890.f};

    return possiblePosition[randomNumber];
}

void Zombi::initSprite(){
    this->sprite.setTexture(this->texture);
    //resize the sprite
    this->sprite.scale(0.18f,0.18f);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    this->sprite.setPosition(1919.f,getRandomPosition());
}

Zombi::Zombi(){
    this->movementSpeed = .6f;
    this->initTexture();
    this->initSprite();
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

