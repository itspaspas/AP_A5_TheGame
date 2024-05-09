#include "Plants.hpp"
#include "RegularPea.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class RegularPeaShooter : public Plant {
private:
    std::vector<RegularPea*> peas;
    float shootInterval;
    float timeSinceLastShoot;

public:
    RegularPeaShooter();
    ~RegularPeaShooter() {
        for (auto pea : peas) {
            delete pea;
        }
    }

    void update(const sf::Time& dt) {
        timeSinceLastShoot += dt.asSeconds();
        if (timeSinceLastShoot >= shootInterval) {
            shoot();
            timeSinceLastShoot = 0;
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
        sf::Vector2f position = this->sprite.getPosition();
        position.x += this->sprite.getGlobalBounds().width;
        peas.push_back(new RegularPea(position));
    }

    void render(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (auto& pea : peas) {
            pea->draw(window);
        }
    }
};
