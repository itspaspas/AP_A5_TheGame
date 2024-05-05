#include "Plants.hpp"

class SunFlower : public Plant {
    float produceInterval;
    float timeSinceLastProduction;

public:
    SunFlower(const std::string& path) : Plant(path, 50), produceInterval(5.0f), timeSinceLastProduction(0.0f) {}

    void act() override {
        // Implementation for producing suns
        // This method would be called when it's time to produce a sun
    }

    void update() override {
        timeSinceLastProduction += 1.0f / 60.0f; // Assuming a 60 FPS frame rate
        if (timeSinceLastProduction >= produceInterval) {
            act();
            timeSinceLastProduction = 0.0f;
        }
    }
};

