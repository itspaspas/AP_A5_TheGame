#include "WatermelonShooter.hpp"

WatermelonShooter::WatermelonShooter()
    : Plant(15, 20, 8 ,"extrafile/Melonpult.png" , .25f ,true){
        this->firstTime = true ;
}

void WatermelonShooter::update() {
    if (WatermelonShotClock.getElapsedTime().asSeconds() >= activationTime || this->firstTime ) {
        if(!this->HaveWatermelon){
            this->HaveWatermelon = true;
            WatermelonShotClock.restart();
            this->firstTime = false;
        }
    }
    else{
        this->HaveWatermelon = false;
    }
}