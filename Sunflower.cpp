#include "Sunflower.hpp"

SunFlower::SunFlower()
    : Plant(0, 100, 5.0f,"extrafile/Sunflower.png" , .05f), coolDownTime(10){
    // Initialization of other Sunflower-specific members
}

void SunFlower::update(){
    if (coolDownClock.getElapsedTime().asSeconds() >= coolDownTime) {
        if(!this->HaveSun){
            this->HaveSun = true;
            coolDownClock.restart();
        }
    }
    else{
        this->HaveSun = false;
    }

}

