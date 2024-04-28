#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>

/*
	Class that acts as the game engine.
	Wrapper class.
*/

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Private functions
	void initWindow();

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