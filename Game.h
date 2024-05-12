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
#include "WalnutPriceRectangle.h"
#include "RegularPeaShooterPriceRectangle.h"
#include "icyPeaShooterPriceRectangle.h"
#include "WatermelonShooterPriceRectangle.h"
#include "IcyPeaShooter.hpp"
#include "Plants.hpp"
#include "Sunflower.hpp"
#include "Walnut.hpp"
#include "RegularPeaShooter.hpp"
#include "RegularPea.hpp"
#include "IcyPea.hpp"
#include "WatermelonShooter.hpp"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	int sunsNum; 
	bool isDone;
	bool isGameOver;
	bool attacking;
	int waveNum;
	int zombieAddedInWave;

	SunFlower* sunflower;
	Walnut* walnut;
	RegularPeaShooter* regularPeaShooter;
	IcyPeaShooter* icyPeaShooter;
	WatermelonShooter* watermelonShooter;
	std::vector <Zombie*> zombies;
	std::vector <Sun*> suns;
	std::vector <Plant*> plants;
	std::vector <Projectile*> projectiles;
	sf::Clock showingRound;
	sf::Clock zombiAttackClock;
	sf::Clock waveAttackClock;
	sf::Clock sunClock;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseHeld;
	bool isPressedBeforForSun;
	bool isPressedBeforForWalnut;
	bool isPressedBeforForRegularPeaShooter;
	bool isPressedBeforForIcyPeaShooter;
	bool isPressedBeforForWatermelon;

	//Private functions
	void showWonState();
	void showRound();
	void initWindow();
	void addNewNormalZombie();
	void addNewBigZombie();
	void gameOver();
	void ShowGameOverPic();
	void showSunsNum();
	void showSunRectangle();
	void fallingSuns();
	void clearDownSun();
	void updateMousePositions();
	void updateSuns();
	void addNewSunFlower();
	void addNewWalnut();
	void addNewRegularPeaShooter();
	void addNewIcyPeaShooter();
	void addNewWatermelonShooter();
	bool plantIsOnBoard(sf::Vector2f mousePositionFloat);
	void checkZombiePlantCollision();
	void checkZombiePeaCollision();
	bool notClickForOther();
	bool isZombiAreInLineOf(Plant* plant);

	//music of game
	sf::Music music;
	// sf::Music gameOverMusic;
	// sf::Sound winMusic;

	//board of game
	Board* board;

	//price rectangle
	SunFlowerPriceRectangle* sunFlowerPriceRectangle;
	WalnutPriceRectangle* walnutPriceRectangle;
	RegularPeaShooterPriceRectangle* regularPeaShooterPriceRectangle;
	IcyPeaShooterPriceRectangle* icyPeaShooterPriceRectangle;
	WatermelonShooterPriceRectangle* watermelonShooterPriceRectangle;

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