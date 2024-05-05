#include "Plants.hpp"

class Walnut : public Plant {
    float stamina;

public:
    Walnut(const std::string& path) : Plant(path, 4000) { // Walnuts have a high health value
        sprite.setScale(0.5f, 0.5f); // Scale the sprite if needed
    }

    void act() override {
        // Walnut does not act but could react to being hit by zombies
    }

    void update() override {
        //TODO
    }
};