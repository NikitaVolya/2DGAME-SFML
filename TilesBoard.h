#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "setup.h"
#include "MapManager.h"
#include "KeyBoardManager.h"
#include "Tile.h"

class TilesBoard
{
private:
	MapManager& mapM;
	sf::RectangleShape board;

	const sf::Vector2f size = sf::Vector2f(SCREEN_WIDTH, PIXEL_SIZE * 2);
public:
	TilesBoard(MapManager& pMapM);

	int getHeight() { return size.y; };

	void update(KeyBoardManager* kbc, int& paintbrush);
	void draw(sf::RenderWindow* window);
};