#include "Game.h"
#include "HairMetalZombie.h"
#include "RegularZombie.h"

const float zombieGenerateInterval = 3.0f;

void Game::initWindow()
{
	this->videoMode = sf::VideoMode::getDesktopMode();
	this->window = new sf::RenderWindow(videoMode, "Full Screen Image", sf::Style::Fullscreen);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

Game::Game(){
	sunsNum = 50;

	sf::Vector2f beginOfBoard;
	beginOfBoard.x = 350.f;
	beginOfBoard.y = 150.f;
	sf::Vector2f endOfBoard;
	endOfBoard.x = 1600.f;
	endOfBoard.y = 980.f;
	Board b(beginOfBoard , endOfBoard);
	this->board = &b;

	this->isDone = false;
	this->attacking = false;
	this->waveNum = 1;
	this->zombieAddedInWave=0;
	this->initWindow();

	this->music.openFromFile("extrafile/Main-Music.ogg");
	this->music.setLoop(true);
	this->music.play();

	this->sunFlowerPriceRectangle = new SunFlowerPriceRectangle();
	this->walnutPriceRectangle = new WalnutPriceRectangle();
	this->regularPeaShooterPriceRectangle = new RegularPeaShooterPriceRectangle();
	this->icyPeaShooterPriceRectangle = new IcyPeaShooterPriceRectangle();
}

Game::~Game()
{
	delete this->window;
	for(auto zombi : this->zombies)
		delete zombi;
	for(auto sun : this->suns)
		delete sun;
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
	if(!attacking && waveAttackClock.getElapsedTime().asSeconds()>=5.0f){
		attacking = true;
		waveAttackClock.restart();
	}

	if(attacking && waveAttackClock.getElapsedTime().asSeconds()<=zombieGenerateTime){
		if (zombiAttackClock.getElapsedTime().asSeconds() >= zombieGenerateInterval) {
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
		if(waveNum == 5){
			isDone = true;
		}
		showingRound.restart();
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
	this->window->getSize();
}

void Game::showRound(){
	if(showingRound.getElapsedTime().asSeconds() <= 2){
		sf::Font font;
		font.loadFromFile("extrafile/BROMPH_TOWN.ttf");
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(100);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		// text.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2);
		text.setPosition(850 , 450);
		if(!isDone){
			text.setString("Round " + std::to_string(waveNum));
			this->window->draw(text);
		}
	}
}

void Game::showWonState(){
		sf::Font font;
		font.loadFromFile("extrafile/BROMPH_TOWN.ttf");
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(100);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(800 , 450);
		text.setString("YOU WON!!!");
		this->window->draw(text);
}

void Game::showSunRectangle(){
	sf::RectangleShape rectangle(sf::Vector2f(150.f, 60.f));
    rectangle.setFillColor(sf::Color::Black);
	rectangle.setOrigin(rectangle.getLocalBounds().width / 2, rectangle.getLocalBounds().height / 2);
    rectangle.setPosition(185 , 50);
	//Create a text object
	sf::Text text;
    text.setString(std::to_string(this->sunsNum));
	text.setOrigin(30, 25);
    text.setCharacterSize(40);
	text.setColor(sf::Color::White);
    // Load a font
    sf::Font font;
    font.loadFromFile("extrafile/Dosis-Light.ttf");
    text.setFont(font);
	text.setPosition(185 , 50 );
	this->window->draw(rectangle);
    this->window->draw(text);
}

void Game::showSunsNum(){
	sf::Texture sun;
	sun.loadFromFile("extrafile/sun.png");
	sf::Sprite sunSprite;
	sunSprite.setTexture(sun);
	sunSprite.setScale(.3f,.3f);
	sunSprite.setOrigin(sun.getSize().x/2 , sun.getSize().y/2);
	sunSprite.setPosition(50,50);
	// sf::RenderTarget& target = *this->window;
	this->window->draw(sunSprite);
	this->showSunRectangle();
}

void Game::fallingSuns(){
	if(sunClock.getElapsedTime().asSeconds()>=5.0f){
		suns.push_back(new Sun);
		sunClock.restart();
	}
}

void Game::updateMousePositions(){
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateSuns(){
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->suns.size() && deleted == false; i++)
			{
				if (this->suns[i]->sprite.getGlobalBounds().contains(this->mousePosView)){
					this->sunsNum += 25;
					//Delete the sun
					deleted = true;
					this->suns.erase(this->suns.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}


void Game::clearDownSun(){
	for(int i=0 ; i<suns.size() ; i++)
		if(suns[i]->hasArrivedToDown()){
			delete suns[i];
			suns.erase(suns.begin() + i);
		}
}

void Game::update()
{
	this->pollEvents();
	this->beginAttackIfItsTime();
	this->fallingSuns();
	this->gameOver();
	for(auto zombi : this->zombies)
		zombi->move(-1.f,0.f);
	for(auto sun : this->suns)
		sun->move(0.f,1.f);

	this->updateMousePositions();
	this->updateSuns();

}

void Game::render()
{
	this->window->clear();
	//showing background
	this->ShowBackGround("extrafile/ext8waid79e81.jpg");
	//showing round
	this->showRound();
	//showing sun number
	this->showSunsNum();
	//deleting sun that reach the doown
	this->clearDownSun();
	//showing zombies
	if(!isDone){
		for(auto zombi : this->zombies)
			zombi->render(*this->window);
		for(auto sun : this->suns)
			sun->render(*this->window);
	}
	else{
		showWonState();
	}

	// showing the box of cost
	this->sunFlowerPriceRectangle->render(*this->window);
	this->walnutPriceRectangle->render(*this->window);
	this->regularPeaShooterPriceRectangle->render(*this->window);
	this->icyPeaShooterPriceRectangle->render(*this->window);

	// showing the mouse position
    sf::Vector2i position = sf::Mouse::getPosition(*this->window);
    std::cout << "Mouse position: " << position.x << " - " << window->getSize().x << ", " << position.y << " - " << window->getSize().y << std::endl;

	std::cout<<"the wave num"<<this->waveNum << std::endl;

	this->window->display();
}

/* std::vector<Plant*> plants; // Assuming you have a vector of pointers to Plant objects

void gameLoop() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plants vs. Zombies");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto& plant : plants) {
            plant->update();
            plant->render(window);
        }
        window.display();
    }
}
 */