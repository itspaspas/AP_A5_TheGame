#include "Plants.hpp"

#ifndef SUNFLOWER_H
#define SUNFLOWER_H

class SunFlower : public Plant {
    float scale;
    float produceInterval;
    float timeSinceLastProduction;

public:
    SunFlower(Cell* cell, const std::string& texturePath);  // Constructor declaration
    void act();  // Method to produce suns
    void update();  // Update method for timing and logic
};

#endif