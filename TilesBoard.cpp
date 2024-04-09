#include "TilesBoard.h"

TilesBoard::TilesBoard(MapManager& pMapM) : mapM(pMapM) {
	board = sf::RectangleShape(size);
	board.setPosition(sf::Vector2f(0, SCREEN_HEIGHT));
	board.setFillColor(sf::Color::Black);
};

void TilesBoard::update(KeyBoardManager* kbc, int& paintbrush)
{
	if (kbc->getMouseLeft())
	{
		sf::Vector2i position = kbc->getMousePosition();
		if (position.y > SCREEN_HEIGHT && position.y < SCREEN_HEIGHT + PIXEL_SIZE * 2)
		{
			
			int tileIndex = position.x / (PIXEL_SIZE);
			if (tileIndex >= mapM.getTileNumber())
				tileIndex = mapM.getTileNumber() - 1;
			paintbrush = tileIndex;
		}
	}
}

void TilesBoard::draw(sf::RenderWindow* window)
{
	window->draw(board);

	for (int i = 0; i < mapM.getTileNumber(); i++)
	{
		Tile* tmpTile = mapM.getTileType(i);
		tmpTile->draw(window, sf::Vector2f(i * PIXEL_SIZE, SCREEN_HEIGHT + PIXEL_SIZE / 2));
	}
}