#include "Game.h"
#include "HairMetalZombie.h"
#include "RegularZombie.h"

const float zombieGenerateInterval = 2.0f;

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
	this->attacking = false;
	this->waveNum = 1;
	this->zombieAddedInWave=0;
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
	for(auto zombi : this->zombies)
		delete zombi;
}

void Game::addNewNormalZombie(){
	this->zombies.push_back(new RegularZombie());
}

void Game::addNewBigZombie(){
	this->zombies.push_back(new HairMetalZombie());
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

void Game::beginAttackIfItsTime(){

	int numberOfZombies = waveNum * 3 + 2;
	float zombieGenerateTime = numberOfZombies*zombieGenerateInterval;
		// If more than 2 minutes have passed since the last spawn

	if(!attacking && waveAttackClock.getElapsedTime().asSeconds()>=3.0f){
		attacking = true;
		waveAttackClock.restart();
	}

	if(attacking && waveAttackClock.getElapsedTime().asSeconds()<=zombieGenerateTime){
		if (zombiAttackClock.getElapsedTime().asSeconds() >= zombieGenerateInterval) {
			// Reset the clock
			zombieAddedInWave += 1;
			if (zombieAddedInWave % 3 == 0){
				addNewBigZombie();
			} else {
				addNewNormalZombie();
			}
			
			zombiAttackClock.restart();
		}
	}

	if(attacking && waveAttackClock.getElapsedTime().asSeconds()>=zombieGenerateTime && zombies.size()== 0){
		attacking = false;
		waveNum += 1;
		zombieAddedInWave = 0;
		waveAttackClock.restart();

	}
		
}

void Game::gameOver(){
	for(int i=0 ; i<zombies.size() ; i++)
		if(zombies[i]->hasArrivedHome()){
			delete zombies[i];
			zombies.erase(zombies.begin() + i);
		}

}

void Game::update()
{

	this->pollEvents();
	this->beginAttackIfItsTime();
	this->gameOver();
	for(auto zombi : this->zombies)
		//move zombi by time
		zombi->move(-1.f,0.f);

}

void Game::ShowBackGround(std::string backgroundPath){
    sf::Texture texture;
    texture.loadFromFile(backgroundPath);
    sf::Sprite sprite(texture);
	sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(this->videoMode.width) / texture.getSize().x;
    float scaleY = static_cast<float>(this->videoMode.height) / texture.getSize().y;
    sprite.setScale(scaleX, scaleY);
    this->window->draw(sprite);
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
	this->ShowBackGround("extrafile/ext8waid79e81.jpg");
	//showing zombies
	for(auto zombi : this->zombies)
		zombi->render(*this->window);
	//showing the mouse position
    sf::Vector2i position = sf::Mouse::getPosition(*this->window);
    // std::cout << "Mouse position: " << position.x << ", " << position.y << std::endl;

	this->window->display();
}