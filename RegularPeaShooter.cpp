#include "RegularPeaShooter.hpp"

RegularPeaShooter::RegularPeaShooter()
    : Plant(5, 40, 5 ,"extrafile/peashooter.png" , .12f){
        this->firstTime = true ;
}

void RegularPeaShooter::update() {
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