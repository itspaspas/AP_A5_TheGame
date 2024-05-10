#ifndef REGULARPEA_HPP
#define REGULARPEA_HPP

#include "Projectiles.hpp"
#include <SFML/Graphics.hpp>

class RegularPea : public Projectile {
public:
    RegularPea() : Projectile("extrafile/pea.png", 7 , 0.05 ,5 ,0) {}
};

#endif