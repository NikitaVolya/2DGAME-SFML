
#include <iostream>
#include <vector>

#include "Game.h"
#include "MapEditor.h"

DoubleLinkedList<GameSprite*> GameSprite::GameSpriteListe{};

void startMapEditor()
{
	MapEditor mapEditor;
	mapEditor.run();
}

void startGame()
{
	Game game;
	game.run();
}

void creatorMod()
{
	int choice;
	while (true)
	{
		std::cout << "Select mod:\n1. create map\n2. start game\n3. exit\n";
		std::cin >> choice;
		switch (choice)
		{
			case 1:
				startMapEditor();
				return;
			case 2:
				startGame();
				return;
				break;
			case 3:
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