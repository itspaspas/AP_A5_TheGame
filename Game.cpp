#include "Game.h"
#include "HairMetalZombie.h"
#include "RegularZombie.h"

const float zombieGenerateInterval = 3.0f;

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800,600);
	this->window = new sf::RenderWindow(videoMode, "Plant vs Zombie");
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

Game::Game(){
	sunsNum = 50;

	sf::Vector2f beginOfBoard;
	beginOfBoard.x = 150.f;
	beginOfBoard.y = 90.f;
	sf::Vector2f endOfBoard;
	endOfBoard.x = 660.f;
	endOfBoard.y = 550.f;

	this->board = new Board(beginOfBoard , endOfBoard);

	this->isDone = false;
	this->attacking = false;
	this->isPressedBeforForSun = false;
	this->isPressedBeforForWalnut =false;
	this->isPressedBeforForRegularPeaShooter = false;
	this->isPressedBeforForIcyPeaShooter = false;
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

	this->sunflower = new SunFlower();
	this->walnut = new Walnut();
	this ->regularPeaShooter = new RegularPeaShooter();
	this->icyPeaShooter = new IcyPeaShooter();
}

Game::~Game()
{
	delete this->window;
	for(auto zombie : this->zombies)
		delete zombie;
	for(auto sun : this->suns)
		delete sun;
	delete this->board;
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
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		// text.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2);
		text.setPosition(325 , 225);
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
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Red);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(300 , 225);
		text.setString("YOU WON!!!");
		this->window->draw(text);
}

void Game::showSunRectangle(){
	sf::RectangleShape rectangle(sf::Vector2f(75.f, 30.f));
    rectangle.setFillColor(sf::Color::Black);
	rectangle.setOrigin(rectangle.getLocalBounds().width / 2, rectangle.getLocalBounds().height / 2);
    rectangle.setPosition(92 , 25);
	//Create a text object
	sf::Text text;
    text.setString(std::to_string(this->sunsNum));
	text.setOrigin(15, 12);
    text.setCharacterSize(20);
	text.setColor(sf::Color::White);
    // Load a font
    sf::Font font;
    font.loadFromFile("extrafile/Dosis-Light.ttf");
    text.setFont(font);
	text.setPosition(92 , 25);
	this->window->draw(rectangle);
    this->window->draw(text);
}

void Game::showSunsNum(){
	sf::Texture sun;
	sun.loadFromFile("extrafile/sun.png");
	sf::Sprite sunSprite;
	sunSprite.setTexture(sun);
	sunSprite.setScale(.15f,.15f);
	sunSprite.setOrigin(sun.getSize().x/2 , sun.getSize().y/2);
	sunSprite.setPosition(25,25);
	// sf::RenderTarget& target = *this->window;
	this->window->draw(sunSprite);
	this->showSunRectangle();
}

void Game::fallingSuns(){
	if(sunClock.getElapsedTime().asSeconds()>=5.0f){
		Sun* newFallingSun = new Sun(1);
		sf::Vector2f fallingSunPos = {150 + static_cast<float>(rand() % static_cast<int>(500)) ,0.f};
		newFallingSun->setPosition(fallingSunPos.x , fallingSunPos.y);
		suns.push_back(newFallingSun);
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
				if (this->suns[i]->getSprite().getGlobalBounds().contains(this->mousePosView)){
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

bool Game::plantIsOnBoard(sf::Vector2f mousePositionFloat){
	return this->board->isContain(mousePositionFloat);
}

void Game::addNewSunFlower(){
	if(this->isPressedBeforForSun && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) && this->board->isCellEmpty(this->mousePosView)){
		SunFlower* newSunFlower = new SunFlower();
		sf::Vector2f posOfAddedSunflower = this->board->plantAt(this->mousePosView , newSunFlower);
		newSunFlower->setPosition(posOfAddedSunflower);
		plants.push_back(newSunFlower);
		this->sunFlowerPriceRectangle->startCoolDown();
		this->sunsNum -= 50;
		this->isPressedBeforForSun = false;
	}
	if(this->isPressedBeforForSun || this->sunFlowerPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForSun || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->sunFlowerPriceRectangle->isAbleToAdd() && this->sunsNum >= 50){
			this->sunflower->setPosition(this->mousePosView);
			this->sunflower->render(*this->window);
			this->isPressedBeforForSun = true;
		}
	}
}

void Game::addNewWalnut(){
	if(this->isPressedBeforForWalnut && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) && this->board->isCellEmpty(this->mousePosView)){
		Walnut* newWalnut = new Walnut();
		sf::Vector2f posOfAddedWalnut = this->board->plantAt(this->mousePosView , newWalnut);
		newWalnut->setPosition(posOfAddedWalnut);
		plants.push_back(newWalnut);
		this->walnutPriceRectangle->startCoolDown();
		this->sunsNum -= 50;
		this->isPressedBeforForWalnut = false;
	}
	if(this->isPressedBeforForWalnut || this->walnutPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForWalnut || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->walnutPriceRectangle->isAbleToAdd()  && this->sunsNum >= 50){
			this->walnut->setPosition(this->mousePosView);
			this->walnut->render(*this->window);
			this->isPressedBeforForWalnut = true;
		}
	}
}

void Game::addNewRegularPeaShooter(){
	if(this->isPressedBeforForRegularPeaShooter && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) && this->board->isCellEmpty(this->mousePosView)){
		RegularPeaShooter* regularPeaShooter = new RegularPeaShooter();
		sf::Vector2f posOfAddedRegularPeaShooter = this->board->plantAt(this->mousePosView , regularPeaShooter);
		regularPeaShooter->setPosition(posOfAddedRegularPeaShooter);
		plants.push_back(regularPeaShooter);
		this->regularPeaShooterPriceRectangle->startCoolDown();
		this->sunsNum -= 100;
		this->isPressedBeforForRegularPeaShooter = false;
	}
	if(this->isPressedBeforForRegularPeaShooter || this->regularPeaShooterPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForRegularPeaShooter || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->regularPeaShooterPriceRectangle->isAbleToAdd() && this->sunsNum >= 100){
			this->regularPeaShooter->setPosition(this->mousePosView);
			this->regularPeaShooter->render(*this->window);
			this->isPressedBeforForRegularPeaShooter = true;
		}
	}
}

void Game::addNewIcyPeaShooter(){
	if(this->isPressedBeforForIcyPeaShooter && sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->plantIsOnBoard(this->mousePosView) && this->board->isCellEmpty(this->mousePosView)){
		IcyPeaShooter* icyPeaShooter = new IcyPeaShooter();
		sf::Vector2f posOfAddedIcyPeaShooter = this->board->plantAt(this->mousePosView , icyPeaShooter);
		icyPeaShooter->setPosition(posOfAddedIcyPeaShooter);
		plants.push_back(icyPeaShooter);
		this->icyPeaShooterPriceRectangle->startCoolDown();
		this->sunsNum -= 150;
		this->isPressedBeforForIcyPeaShooter = false;
	}
	if(this->isPressedBeforForIcyPeaShooter || this->icyPeaShooterPriceRectangle->isContains(this->mousePosView)){
		if(this->isPressedBeforForIcyPeaShooter || sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->icyPeaShooterPriceRectangle->isAbleToAdd() && this->sunsNum >= 150){
			this->icyPeaShooter->setPosition(this->mousePosView);
			this->icyPeaShooter->render(*this->window);
			this->isPressedBeforForIcyPeaShooter = true;
		}
	}
}

bool Game::zombiesArrived(Projectile* projectile, Zombie* zombie){
	if (projectile->getSprite().getPosition().y ==  zombie->getSprite().getPosition().y){
		return true;
	}
	else {
		return false;
	}
}


void Game::checkZombiePlantCollision() {
    for(auto &zombie : zombies) {
        for(auto &plant : plants) {
            sf::FloatRect plantBounds = plant->getSprite().getGlobalBounds();
            sf::FloatRect zombieBounds = zombie->getSprite().getGlobalBounds();
			sf::Vector2f zombieCenter = sf::Vector2f(
                zombieBounds.left + zombieBounds.width / 2.0f,
                zombieBounds.top + zombieBounds.height / 2.0f);
            if(plantBounds.contains(zombieCenter)){
                zombie->startEating(plant);
                break;
            }
			else{
				zombie->isNotEating();
			}
        }
    }
}

void Game::checkZombiePeaCollision(){
	for(auto pea : projectiles){
		for(auto zombie : zombies){
			sf::FloatRect zombieBounds = zombie->getSprite().getGlobalBounds();
			sf::FloatRect peaBound = pea->getSprite().getGlobalBounds();
			sf::Vector2f peaCenter = sf::Vector2f(
                peaBound.left + peaBound.width / 2.0f,
                peaBound.top + peaBound.height / 2.0f);
			if(zombieBounds.contains(peaCenter)){
				zombie->hitByPea(pea);
				pea->getHit();
				break;
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->beginAttackIfItsTime();
	this->fallingSuns();
	this->gameOver();
	for(auto zombie : this->zombies){
		if(!zombie->isEating())
			zombie->move(-1.f,0.f);
	}
	for(auto sun : this->suns)
		sun->move(0.f,1.f);

	//delete the dead plant
	for(int i=0 ; i<plants.size() ; i++){
		if(plants[i]->isDead()){
			plants[i]->makeCellEmpty();
			delete plants[i];
			plants.erase(plants.begin() + i);
		}
	}


	for(auto plant :plants){
		plant->update();
		if(plant->isHaveSun()){
			Sun* newSun = new Sun(0);
			sf::Vector2f posOfSun = plant->getSunPos();
			newSun->setPosition(posOfSun.x , posOfSun.y);
			this->suns.push_back(newSun);
		}

		if(plant->isHaveRegularPea()){
			RegularPea* newPea = new RegularPea();
			sf::Vector2f posOfNewPea = plant->getPeaAddr();
			newPea->setPosition(posOfNewPea.x , posOfNewPea.y);
			this->projectiles.push_back(newPea);
		}
		if(plant->isHaveSnowPea()){
			IcyPea* newIcePea = new IcyPea();
			sf::Vector2f posOfNewPea = plant->getPeaAddr();
			newIcePea->setPosition(posOfNewPea.x , posOfNewPea.y);
			this->projectiles.push_back(newIcePea);
		}
	}

	for(auto projectile : projectiles){
		// for (auto zombie : zombies){
		// 	do{
				projectile->move(1.f,0.f);
		// 	}
		// 	while (zombiesArrived(projectile, zombie));
		// }
	}

	for(int i=0 ; i<projectiles.size() ; i++){
		if(projectiles[i]->isOffScreen(800) || projectiles[i]->isHit()){
			delete projectiles[i];
			projectiles.erase(projectiles.begin() + i);
		}
	}

	for(int i=0 ; i<zombies.size();i++){
		zombies[i]->upDate();
		if(zombies[i]->isDead()){
			delete zombies[i];
			zombies.erase(zombies.begin() + i);			
		}
	}


	this->checkZombiePlantCollision();
	this->updateMousePositions();
	this->updateSuns();
	this->checkZombiePeaCollision();
}

void Game::render()
{
	this->window->clear();
	//showing background
	this->ShowBackGround("extrafile/ext8waid79e81.jpg");
	//showing sun number
	this->showSunsNum();
	//deleting sun that reach the doown
	this->clearDownSun();
	//showing sunflower
	for(auto plant : plants)
		plant->render(*this->window);

	//showing zombies
	if(!isDone){
		for(auto zombie : this->zombies)
			zombie->render(*this->window);
		for(auto sun : this->suns)
			sun->render(*this->window);
		
    }
	else{
		showWonState();
	}

	//showing peas
	for(auto projectile :projectiles){
		projectile->render(*this->window);
	}
	
	//showing round
	this->showRound();

	// showing the box of cost
	this->sunFlowerPriceRectangle->render(*this->window);
	this->walnutPriceRectangle->render(*this->window);
	this->regularPeaShooterPriceRectangle->render(*this->window);
	this->icyPeaShooterPriceRectangle->render(*this->window);
	//showing sunflower when adding one
	this->addNewSunFlower();
	this->addNewWalnut();
	this->addNewRegularPeaShooter();
	this->addNewIcyPeaShooter();


	// showing the mouse position
    // sf::Vector2i position = sf::Mouse::getPosition(*this->window);
    // std::cout << "Mouse position: " << position.x << " - " << window->getSize().x << ", " << position.y << " - " << window->getSize().y << std::endl;
	this->window->display();
}
