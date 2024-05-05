#include "Plants.hpp"

class RegularPeaShooter : public Plant {
    float shootInterval;
    float timeSinceLastShot;

public:
    RegularPeaShooter(const std::string& path) : Plant(path, 100), shootInterval(2.0f), timeSinceLastShot(0.0f) {}

    void act() override {
        // Implementation for shooting peas
        // This method would be called when it's time to shoot a pea
    }

    void update() override {
        timeSinceLastShot += 1.0f / 60.0f; // Assuming a 60 FPS frame rate
        if (timeSinceLastShot >= shootInterval) {
            act();
            timeSinceLastShot = 0.0f;
        }
    }
};
