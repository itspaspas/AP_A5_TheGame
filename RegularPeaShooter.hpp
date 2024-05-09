#include "Plants.hpp"

class RegularPeaShooter : public Plant {
    float shootInterval;
    float timeSinceLastShot;

public:
    RegularPeaShooter();
    void act();
    void update();
};
