#include "SunFlowerPriceRectangle.h"

SunFlowerPriceRectangle::SunFlowerPriceRectangle(){
    collDownTime = 2;
    picturePath = "extrafile/1.png";
    collDownPicPath = "extrafile/1dark.png";
}


void SunFlowerPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture sunFlowerCost;
        sunFlowerCost.loadFromFile(picturePath);
        sf::Sprite sunFlowerCostSprite;
        sunFlowerCostSprite.setTexture(sunFlowerCost);
        sunFlowerCostSprite.setScale(0.9f,0.9f);
        sunFlowerCostSprite.setOrigin(sunFlowerCost.getSize().x/2 , sunFlowerCost.getSize().y/2);
        sunFlowerCostSprite.setPosition(60,80);
        this->sprit = sunFlowerCostSprite;
        target.draw(sunFlowerCostSprite);
    }
    else{
        sf::Texture sunFlowerCost;
        sunFlowerCost.loadFromFile(collDownPicPath);
        sf::Sprite sunFlowerCostSprite;
        sunFlowerCostSprite.setTexture(sunFlowerCost);
        sunFlowerCostSprite.setScale(0.9f,0.9f);
        sunFlowerCostSprite.setOrigin(sunFlowerCost.getSize().x/2 , sunFlowerCost.getSize().y/2);
        sunFlowerCostSprite.setPosition(60,80);
        target.draw(sunFlowerCostSprite);
    }
}

bool SunFlowerPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprit.getGlobalBounds().contains(addr);
}