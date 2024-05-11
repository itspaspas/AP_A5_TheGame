#include "Plants.hpp"
#include "RegularPea.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class RegularPeaShooter : public Plant {
private:
    sf::Clock PeaShotClock;
    bool firstTime;

public:
    RegularPeaShooter();
    void update() {
        if (PeaShotClock.getElapsedTime().asSeconds() >= activationTime || this->firstTime ) {
            if(!this->HaveRegularPea){
                this->HaveRegularPea = true;
                PeaShotClock.restart();
                this->firstTime = false;
            }
        }
        else{
            this->HaveRegularPea = false;
        }
    }
};
