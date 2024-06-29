
#include <iostream>
#include <vector>

#include "Engine2D.h"

void startGame()
{
	Engine2D game;
	game.run();
}

void creatorMod()
{
	int choice;
	while (true)
	{
		std::cout << "Select mod:\n1. start game\n2. exit\n";
		std::cin >> choice;
		switch (choice)
		{
			case 1:
				startGame();
				return;
				break;
			case 2:
				return;
		}
	}
	
}

int main()
{

	if (CREATOR_MODE)
		creatorMod();
	else
		startGame();

	return 0;
}