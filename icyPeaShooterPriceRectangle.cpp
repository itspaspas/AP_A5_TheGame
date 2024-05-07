#include "icyPeaShooterPriceRectangle.h"

IcyPeaShooterPriceRectangle::IcyPeaShooterPriceRectangle(){
    collDownTime = 9;
    picturePath = "extrafile/4.png";
    collDownPicPath = "extrafile/4dark.png";
}

void IcyPeaShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture icyPeaShooterCost;
        icyPeaShooterCost.loadFromFile(picturePath);
        sf::Sprite icyPeaShooterCostSprite;
        icyPeaShooterCostSprite.setTexture(icyPeaShooterCost);
        icyPeaShooterCostSprite.setScale(.9f,.9f);
        icyPeaShooterCostSprite.setOrigin(icyPeaShooterCost.getSize().x/2 , icyPeaShooterCost.getSize().y/2);
        icyPeaShooterCostSprite.setPosition(60 ,80 + 3*icyPeaShooterCost.getSize().y);
        target.draw(icyPeaShooterCostSprite);
    }
    else{
        sf::Texture icyPeaShooterCost;
        icyPeaShooterCost.loadFromFile(collDownPicPath);
        sf::Sprite icyPeaShooterCostSprite;
        icyPeaShooterCostSprite.setTexture(icyPeaShooterCost);
        icyPeaShooterCostSprite.setScale(.9f,.9f);
        icyPeaShooterCostSprite.setOrigin(icyPeaShooterCost.getSize().x/2 , icyPeaShooterCost.getSize().y/2);
        icyPeaShooterCostSprite.setPosition(60,80 + 3*icyPeaShooterCost.getSize().y);
        target.draw(icyPeaShooterCostSprite);
    }
}