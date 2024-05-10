#include "Plants.hpp"
#include "RegularPea.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class RegularPeaShooter : public Plant {
private:
    sf::Clock PeaShotClock;

public:
    RegularPeaShooter();
    void update() {
        if (PeaShotClock.getElapsedTime().asSeconds() >= activationTime) {
            if(!this->HaveRegularPea){
                this->HaveRegularPea = true;
                PeaShotClock.restart();
            }
        }
        else{
            this->HaveRegularPea = false;
        }
    }
};
