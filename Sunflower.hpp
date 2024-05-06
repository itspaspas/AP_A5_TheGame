#include "Plants.hpp"

#ifndef SunFlower_H
#define SunFlower_H

class SunFlower : public Plant {
    float scale;
    float produceInterval;
    float timeSinceLastProduction;

public:
    SunFlower(const std::string& path) : Plant(path, 50 ,0.1f), produceInterval(5.0f), timeSinceLastProduction(0.0f) , scale(.1f) {}

    void act() override {
        // Implementation for producing suns
        // This method would be called when it's time to produce a sun
    }

    void update() override {
        //TODO
    }
};

#endif