
#include <iostream>
#include "Game.h"
#include "MapEditor.h"

int Entity::globalID = 0;
Entity** Entity::entityList = nullptr;
int Entity::entityNumber = 0;
MapManager* Entity::mapM = nullptr;

void tileManager()
{
	MapManager mapM;

	int choice;
	while (true)
	{
		std::cout << "Creator menu: \n"
			<< "1. get list\n"
			<< "2. create tile\n"
			<< "3. change tile\n"
			<< "4. delete tile\n"
			<< "5. exit\n";
		std::cin >> choice;

		unsigned int pIndex;
		bool pColision;
		char pImage[43];

		switch (choice)
		{
		case 1:
			for (int i = 0; i < mapM.getTileNumber(); i++)
			{
				const Tile* tmp = mapM.getTileType(i);
				if (tmp)
					std::cout << tmp->getTileID() << " | " << tmp->getColision() << " | " << tmp->getTextureHref() << std::endl;
			}
			break;
		case 2:
			std::cout << "Start adding new tile. \n";

			std::cout << "Enter colision of new tile: ";
			std::cin >> pColision;

			std::cout << "Enter filename to image of new tile: ";
			std::cin >> pImage;

			mapM.addNewTileType(pColision, pImage);
			break;
		case 3:
			std::cout << "Start adding new tile. \n";
			std::cout << "Enter index of tile: ";
			std::cin >> pIndex;
			std::cout << "Enter new colision of new tile: ";
			std::cin >> pColision;
			std::cout << "Enter new filename to image of new tile: ";
			std::cin >> pImage;

			mapM.changeTileType(pIndex, pColision, pImage);
			break;
		case 4:
			std::cout << "Start deleting one tile. \n";

			std::cout << "Enter index of tile: ";
			std::cin >> pIndex;
			mapM.deleteTileType(pIndex);
			break;
		case 5:
			return;
		}
	}
}

void startMapEditor()
{
	MapEditor mapEditor;
	mapEditor.gameLoop();
}

void creatorMod()
{
	int choice;
	while (true)
	{
		std::cout << "Select mod:\n1. create map\n2. tile manager\n";
		std::cin >> choice;
		switch (choice)
		{
			case 1:
				startMapEditor();
				break;
			case 2:
				tileManager();
				break;
		}
	}
	
}

int main()
{

	if (CREATOR_MODE)
		creatorMod();
	else
	{
		Game game;
		game.gameLoop();
	}
	
}