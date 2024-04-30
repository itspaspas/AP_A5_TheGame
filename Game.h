#include <SFML/Graphics.hpp>
#include "Zombi.h"
#include<string>
#include<sstream>


/*
	Class that acts as the game engine.
	Wrapper class.
*/

#ifndef GAME_H
#define GAME_H

class Game
{
private:

	//zombi
	Zombi* zombi;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Private functions
	void initWindow();
	void initZombi();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
    
	//Functions
	void pollEvents();
	void update();
	void render();
};

#endif