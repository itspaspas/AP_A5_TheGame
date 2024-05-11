#ifndef ICYPEASHOOTER_HPP
#define ICYPEASHOOTER_HPP

#include "Plants.hpp"
#include <vector>
#include "IcyPea.hpp"
#include <SFML/Graphics.hpp>

class IcyPeaShooter : public Plant {
private:
    sf::Clock PeaShotClock;
    bool firstTime;

public:
    IcyPeaShooter();
    void update();
};

#endif