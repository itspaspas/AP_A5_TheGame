#ifndef REGULARPEA_HPP
#define REGULARPEA_HPP

#include "Projectiles.hpp"
#include <SFML/Graphics.hpp>

class RegularPea : public Projectile {
public:
    RegularPea(sf::Vector2f position) : Projectile("extrafile/bullet.png", position, sf::Vector2f(5.0f, 0.0f)) {}

    virtual ~RegularPea() {}
};

#endif