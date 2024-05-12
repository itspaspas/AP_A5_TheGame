#include "WatermelonShooterPriceRectangle.h"

WatermelonShooterPriceRectangle::WatermelonShooterPriceRectangle(){
    coolDownTime = 10;
    picturePath = "extrafile/5.png";
    coolDownPicPath = "extrafile/5dark.png";
}

void WatermelonShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= coolDownTime){
        sf::Texture watermelonShooterCost;
        watermelonShooterCost.loadFromFile(picturePath);
        sf::Sprite watermelonShooterCostSprite;
        watermelonShooterCostSprite.setTexture(watermelonShooterCost);
        watermelonShooterCostSprite.setScale(.9f,.9f);
        watermelonShooterCostSprite.setOrigin(watermelonShooterCost.getSize().x/2 , watermelonShooterCost.getSize().y/2);
        watermelonShooterCostSprite.setPosition(60,80 + 4*watermelonShooterCost.getSize().y);
        this->sprite = watermelonShooterCostSprite;
        target.draw(watermelonShooterCostSprite);
    }
    else{
        sf::Texture watermelonShooterCost;
        watermelonShooterCost.loadFromFile(coolDownPicPath);
        sf::Sprite watermelonShooterCostSprite;
        watermelonShooterCostSprite.setTexture(watermelonShooterCost);
        watermelonShooterCostSprite.setScale(.9f,.9f);
        watermelonShooterCostSprite.setOrigin(watermelonShooterCost.getSize().x/2 , watermelonShooterCost.getSize().y/2);
        watermelonShooterCostSprite.setPosition(60,80 + 4*watermelonShooterCost.getSize().y);
        target.draw(watermelonShooterCostSprite);
    }
}

bool WatermelonShooterPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= coolDownTime;
}

void WatermelonShooterPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool WatermelonShooterPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprite.getGlobalBounds().contains(addr);
}