#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Zombi{

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;

    void initTexture();
    void initSprite();

public:
    Zombi();
    virtual ~Zombi();

    void setPosition(float x, float y);
    void update();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
};