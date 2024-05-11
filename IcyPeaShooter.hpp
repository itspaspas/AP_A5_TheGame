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
    void update() {
        if (PeaShotClock.getElapsedTime().asSeconds() >= activationTime || this->firstTime ) {
            if(!this->HaveSnowPea){
                this->HaveSnowPea = true;
                PeaShotClock.restart();
                this->firstTime = false;
            }
        }
        else{
            this->HaveSnowPea = false;
        }
    }
};

#endif