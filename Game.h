#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Zombie.h"
#include "sun.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Board.h"
#include "SunFlowerPriceRectangle.h"

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
	std::vector <Zombie*> zombies;
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

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseHeld;

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
	void updateMousePositions();
	void updateSuns();
	//music of game
	sf::Music music;

	//board of game
	Board* board;

	//price rectangle
	SunFlowerPriceRectangle* sunFlowerPriceRectangle;
	sf::Sprite PRWalnut;
	sf::Sprite PRRegularPeaShooter;
	sf::Sprite PRicyPeaShooter;

	sf::Sprite WalnutCostSprite();
	sf::Sprite RegularPeaShooterCostSprite();
	sf::Sprite icyPeaShooterCostSprite();


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