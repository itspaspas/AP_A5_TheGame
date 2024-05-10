#include "Plants.hpp"

#ifndef SUNFLOWER_H
#define SUNFLOWER_H

class SunFlower : public Plant {
    float scale;
    float produceInterval;
    float timeSinceLastProduction;

public:
    SunFlower();  // Constructor declaration
    void update(){return;};  // Update method for timing and log
};

#endif