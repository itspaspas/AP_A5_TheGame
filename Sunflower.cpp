#include "Sunflower.hpp"

SunFlower::SunFlower()
    : Plant(0, 30, 5.0f,"extrafile/Sunflower.png" , .05f ,false), coolDownTime(12){
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

