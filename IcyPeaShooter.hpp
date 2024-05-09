#include "Plants.hpp"

class IcyPeaShooter : public Plant {
    float shootInterval;
    float timeSinceLastShot;

public:
    IcyPeaShooter();
    void act();
    void update();
};
