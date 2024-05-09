#include "Sunflower.hpp"

SunFlower::SunFlower(Cell* cell, const std::string& texturePath)
    : Plant(0, 100, 5.0f, cell, texturePath), produceInterval(5.0f), timeSinceLastProduction(0.0f) {
    // Initialization of other Sunflower-specific members
}
