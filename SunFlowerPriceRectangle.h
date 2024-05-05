#include <SFML/Graphics.hpp>
#include <string>

#ifndef SunFlowerPriceRectangle_H
#define SunFlowerPriceRectangle_H

class SunFlowerPriceRectangle{
private:
    int collDownTime;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:
    SunFlowerPriceRectangle();
    void render(sf::RenderTarget& target);
};



#endif