#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"

int main(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	Game game;

	//Game loop
	while (game.running())
	{
		//Update
		game.update();

		//Render
		game.render();
	}

    return 0;
}