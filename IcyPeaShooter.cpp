#include "IcyPeaShooter.hpp"

IcyPeaShooter::IcyPeaShooter()
    : Plant(8, 30, 5 ,"extrafile/icypeashooter.png" , .055f){
        this->firstTime = true ;
    }

void IcyPeaShooter::update() {
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