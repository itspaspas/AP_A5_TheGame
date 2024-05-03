#include <SFML/Graphics.hpp>
#include "Zombi.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
	Class that acts as the game engine.
	Wrapper class.
*/

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	bool attacking;
	int waveNum;
	//zombi
	std::vector <Zombi*> zombies;
	sf::Clock zombiAttack;
	sf::Clock waveAttack;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Private functions
	void initWindow();
	void addNewZombi();
	void gameOver();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
    
	//Functions
	void beginAttackIfItsTime();
	void ShowBackGround(std::string backGrountpath);
	void pollEvents();
	void update();
	void render();

};

#endif