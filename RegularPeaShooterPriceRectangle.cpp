#include "RegularPeaShooterPriceRectangle.h"

RegularPeaShooterPriceRectangle::RegularPeaShooterPriceRectangle(){
    coolDownTime = 5;
    picturePath = "extrafile/3.png";
    coolDownPicPath = "extrafile/3dark.png";
}

void RegularPeaShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= coolDownTime){
        sf::Texture RegularPeaShooterCost;
        RegularPeaShooterCost.loadFromFile(picturePath);
        sf::Sprite RegularPeaShooterCostSprite;
        RegularPeaShooterCostSprite.setTexture(RegularPeaShooterCost);
        RegularPeaShooterCostSprite.setScale(.9f,.9f);
        RegularPeaShooterCostSprite.setOrigin(RegularPeaShooterCost.getSize().x/2 , RegularPeaShooterCost.getSize().y/2);
        RegularPeaShooterCostSprite.setPosition(60,80 + 2*RegularPeaShooterCost.getSize().y);
        this->sprite = RegularPeaShooterCostSprite;
        target.draw(RegularPeaShooterCostSprite);
    }
    else{
        sf::Texture RegularPeaShooterCost;
        RegularPeaShooterCost.loadFromFile(coolDownPicPath);
        sf::Sprite RegularPeaShooterCostSprite;
        RegularPeaShooterCostSprite.setTexture(RegularPeaShooterCost);
        RegularPeaShooterCostSprite.setScale(.9f,.9f);
        RegularPeaShooterCostSprite.setOrigin(RegularPeaShooterCost.getSize().x/2 , RegularPeaShooterCost.getSize().y/2);
        RegularPeaShooterCostSprite.setPosition(60,80 + 2*RegularPeaShooterCost.getSize().y);
        target.draw(RegularPeaShooterCostSprite);
    }
}

bool RegularPeaShooterPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= coolDownTime;
}

void RegularPeaShooterPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool RegularPeaShooterPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprite.getGlobalBounds().contains(addr);
}