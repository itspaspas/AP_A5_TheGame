#ifndef ICYPEASHOOTER_HPP
#define ICYPEASHOOTER_HPP

#include "Plants.hpp"
#include <vector>
#include "IcyPea.hpp"
#include <SFML/Graphics.hpp>

class IcyPeaShooter : public Plant {
private:
    std::vector<IcyPea*> icyPeas;
    sf::Clock clock;

public:
    IcyPeaShooter();
    ~IcyPeaShooter() {
        for (auto pea : icyPeas) {
            delete pea;
        }
    }

    void update() {
        float dt = clock.getElapsedTime().asSeconds();
        if (dt >= activationTime) {
            shoot();
            clock.restart();
        }

        for (auto it = icyPeas.begin(); it != icyPeas.end();) {
            (*it)->move();
            if ((*it)->isOffScreen(800)) {  // Assuming screen width is 800
                delete *it;
                it = icyPeas.erase(it);
            } else {
                ++it;
            }
        }
    }

    void shoot() {
        sf::Vector2f position = this->sprite.getPosition();
        position.x += this->sprite.getGlobalBounds().width;
        icyPeas.push_back(new IcyPea(position));
    }

    void render(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (auto& pea : icyPeas) {
            pea->draw(window);
        }
    }
};

#endif