#include "Plants.hpp"
#include "RegularPea.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class RegularPeaShooter : public Plant {
private:
    std::vector<RegularPea*> peas;
    sf::Clock clock;

public:
    RegularPeaShooter();
    ~RegularPeaShooter() {
        for (auto pea : peas) {
            delete pea;
        }
    }

    void update() {
        float dt = clock.getElapsedTime().asSeconds();
        if (dt >= activationTime) {
            shoot();
            clock.restart();
        }

        for (auto it = peas.begin(); it != peas.end();) {
            (*it)->move();
            if ((*it)->isOffScreen(800)) {  // Assuming screen width is 800
                delete *it;
                it = peas.erase(it);
            } else {
                ++it;
            }
        }
    }

    void shoot() {
        std::cout << "Shooting a pea" << std::endl;  // Debug output
        sf::Vector2f position = this->sprite.getPosition();
        position.x += this->sprite.getGlobalBounds().width;
        peas.push_back(new RegularPea(position));
        std::cout << "Pea position: " << position.x << ", " << position.y << std::endl;  // Debug output
    }

    void render(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (auto& pea : peas) {
            pea->draw(window);
        }
    }
};
