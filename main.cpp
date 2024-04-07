
#include <iostream>

#include "Game.h"

int Entity::globalID = 0;

Entity** Entity::entityList = nullptr;
int Entity::entityNumber = 0;

int main()
{
	Game game;
	
	while (game.isRunning())
	{
		game.update();

		game.render();
	}
}