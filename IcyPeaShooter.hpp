#ifndef ICYPEASHOOTER_HPP
#define ICYPEASHOOTER_HPP

#include "Plants.hpp"
#include <vector>
#include "IcyPea.hpp"
#include <SFML/Graphics.hpp>

class IcyPeaShooter : public Plant {
private:
    std::vector<IcyPea*> icyPeas;
    sf::Clock clock;

public:
    IcyPeaShooter();

    void update() {
        return;
    }
};

#endif