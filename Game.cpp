#include "Game.h"

void Game::initWindow()
{
	this->videoMode.height = 1800;
	this->videoMode.width = 2000;
	
	this->window = new sf::RenderWindow(this->videoMode,"Plant vs Zombi", sf::Style::Titlebar | sf::Style::Close);

	// this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
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

	this->window->display();
}