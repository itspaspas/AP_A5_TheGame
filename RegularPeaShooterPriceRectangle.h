#include <SFML/Graphics.hpp>
#include <string>

#ifndef RegularPeaShooterPriceRectangle_H
#define RegularPeaShooterPriceRectangle_H

class RegularPeaShooterPriceRectangle{
private:
    int collDownTime;
    sf::Sprite sprit;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:
    RegularPeaShooterPriceRectangle();
    bool isContains(sf::Vector2f addr);
    void render(sf::RenderTarget& target);
    void startCoolDown();
    bool isAbleToAdd();
};



#endif