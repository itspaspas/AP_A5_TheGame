#include "Game.h"

void Game::initWindow()
{
	// this->videoMode.height = 642;
	// this->videoMode.width = 1143;
	this->videoMode = sf::VideoMode::getDesktopMode();
	
	this->window = new sf::RenderWindow(videoMode, "Full Screen Image", sf::Style::Fullscreen);

	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

Game::Game()
{
	this->initWindow();
	this->initZombi();
}

Game::~Game()
{
	delete this->window;
	delete this->zombi;
}

void Game::initZombi(){
	this->zombi = new Zombi();
	
	// this->zombi->initPositin(this->window.getSize().x, this->window.getSize().y / 2);
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->zombi->move(-1.f,0.f);
}

void Game::render()
{
	/**
		@return void

		- clear old frame
		- render objects
		- display frame in window

		Renders the game objects.
	*/

	this->window->clear();

    //draw game object
	//showing background
    sf::Texture texture;
    texture.loadFromFile("extrafile/ext8waid79e81.jpg");
    sf::Sprite sprite(texture);
	sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(this->videoMode.width) / texture.getSize().x;
    float scaleY = static_cast<float>(this->videoMode.height) / texture.getSize().y;
    sprite.setScale(scaleX, scaleY);
    this->window->draw(sprite);
	//showing zombi
	this->zombi->render(*this->window);

	this->window->display();
}