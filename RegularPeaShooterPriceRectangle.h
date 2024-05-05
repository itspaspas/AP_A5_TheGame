#include <SFML/Graphics.hpp>
#include <string>

#ifndef RegularPeaShooterPriceRectangle_H
#define RegularPeaShooterPriceRectangle_H

class RegularPeaShooterPriceRectangle{
private:
    int collDownTime;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:
    RegularPeaShooterPriceRectangle();
    void render(sf::RenderTarget& target);
};



#endif