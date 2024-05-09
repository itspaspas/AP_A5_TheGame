#include <SFML/Graphics.hpp>
#include <string>

#ifndef icyPeaShooterPriceRectangle_H
#define icyPeaShooterPriceRectangle_H

class IcyPeaShooterPriceRectangle{
private:
    int collDownTime;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:
    IcyPeaShooterPriceRectangle();
    void render(sf::RenderTarget& target);
    void startCoolDown();
    bool isAbleToAdd();
};



#endif