#include "WalnutPriceRectangle.h"

WalnutPriceRectangle::WalnutPriceRectangle(){
    collDownTime = 10;
    picturePath = "extrafile/2.png";
    collDownPicPath = "extrafile/2dark.png";
}

void WalnutPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture WalnutCost;
        WalnutCost.loadFromFile(picturePath);
        sf::Sprite WalnutCostSprite;
        WalnutCostSprite.setTexture(WalnutCost);
        WalnutCostSprite.setScale(.9f,.9f);
        WalnutCostSprite.setOrigin(WalnutCost.getSize().x/2 , WalnutCost.getSize().y/2);
        WalnutCostSprite.setPosition(60,80 + WalnutCost.getSize().y);
        target.draw(WalnutCostSprite);
    }
    else{
        sf::Texture WalnutCost;
        WalnutCost.loadFromFile(collDownPicPath);
        sf::Sprite WalnutCostSprite;
        WalnutCostSprite.setTexture(WalnutCost);
        WalnutCostSprite.setScale(.9f,.9f);
        WalnutCostSprite.setOrigin(WalnutCost.getSize().x/2 , WalnutCost.getSize().y/2);
        WalnutCostSprite.setPosition(60,80 + WalnutCost.getSize().y);
        target.draw(WalnutCostSprite);
    }
}