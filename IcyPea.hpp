#ifndef ICYPEA_HPP
#define ICYPEA_HPP

#include "Projectiles.hpp"
#include <SFML/Graphics.hpp>

class IcyPea : public Projectile {
public:
    IcyPea() : Projectile("extrafile/snowpea.png", 5, 0.08){}
};

#endif