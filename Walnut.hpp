#include "Plants.hpp"

class Walnut : public Plant {
    float scale;
    float stamina;

public:
    Walnut();// Walnuts have a high health value
    void act();
    void update();
};