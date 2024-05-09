#ifndef ICYPEA_HPP
#define ICYPEA_HPP

#include "Projectiles.hpp"
#include <SFML/Graphics.hpp>

class IcyPea : public Projectile {
public:
    IcyPea(sf::Vector2f position) : Projectile("extrafile/bullet.PNG", position, sf::Vector2f(5.0f, 0.0f), 0.01) {}

    virtual ~IcyPea() {}
};

#endif