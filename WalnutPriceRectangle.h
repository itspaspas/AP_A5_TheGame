#include <SFML/Graphics.hpp>
#include <string>

#ifndef WalnutPriceRectangle_H
#define WalnutPriceRectangle_H

class WalnutPriceRectangle{
private:
    int collDownTime;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:
    WalnutPriceRectangle();
    void render(sf::RenderTarget& target);
};



#endif