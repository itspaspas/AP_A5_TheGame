#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Zombi.h"
#include "sun.h"
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
	int sunsNum; 
	bool isDone;
	bool attacking;
	int waveNum;
	//zombi
	std::vector <Zombi*> zombies;
	std::vector <Sun*> suns;
	sf::Clock showingRound;
	sf::Clock zombiAttackClock;
	sf::Clock waveAttackClock;
	sf::Clock sunClock;
	int zombieAddedInWave;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Private functions
	void showWonState();
	void showRound();
	void initWindow();
	void addNewNormalZombie();
	void addNewBigZombie();
	void gameOver();
	void showSunsNum();
	void showSunRectangle();
	void fallingSuns();
	void clearDownSun();

	//music of game
	sf::Music music;
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