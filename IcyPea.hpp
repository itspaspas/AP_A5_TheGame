#ifndef ICYPEA_HPP
#define ICYPEA_HPP

#include "Projectiles.hpp"
#include <SFML/Graphics.hpp>

class IcyPea : public Projectile {
public:
    IcyPea(sf::Vector2f position) : Projectile("extrafile/bullet.PNG", 1.5, 0.01){}
};

#endif