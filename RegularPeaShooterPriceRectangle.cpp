#include "RegularPeaShooterPriceRectangle.h"

RegularPeaShooterPriceRectangle::RegularPeaShooterPriceRectangle(){
    collDownTime = 5;
    picturePath = "extrafile/3.png";
    collDownPicPath = "extrafile/3dark.png";
}

void RegularPeaShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture RegularPeaShooterCost;
        RegularPeaShooterCost.loadFromFile(picturePath);
        sf::Sprite RegularPeaShooterCostSprite;
        RegularPeaShooterCostSprite.setTexture(RegularPeaShooterCost);
        RegularPeaShooterCostSprite.setScale(1.8f,1.8f);
        RegularPeaShooterCostSprite.setOrigin(RegularPeaShooterCost.getSize().x/2 , RegularPeaShooterCost.getSize().y/2);
        RegularPeaShooterCostSprite.setPosition(120,160 + 4*RegularPeaShooterCost.getSize().y);
        target.draw(RegularPeaShooterCostSprite);
    }
    else{
        sf::Texture RegularPeaShooterCost;
        RegularPeaShooterCost.loadFromFile(collDownPicPath);
        sf::Sprite RegularPeaShooterCostSprite;
        RegularPeaShooterCostSprite.setTexture(RegularPeaShooterCost);
        RegularPeaShooterCostSprite.setScale(1.8f,1.8f);
        RegularPeaShooterCostSprite.setOrigin(RegularPeaShooterCost.getSize().x/2 , RegularPeaShooterCost.getSize().y/2);
        RegularPeaShooterCostSprite.setPosition(120,160 + 4*RegularPeaShooterCost.getSize().y);
        target.draw(RegularPeaShooterCostSprite);
    }
}