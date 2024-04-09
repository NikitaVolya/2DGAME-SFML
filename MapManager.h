#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"

#include <io.h>


class MapManager
{
private:
	Tile** tileList;
	unsigned int tileNumber;

	Tile*** table;

	unsigned int width;
	unsigned int height;

	void clearTileList();
	void clearTable();
public:
	MapManager();
	~MapManager();

	void createClearMap();

	void loadTiles();
	void saveTiles();

	void loadMap();
	void saveMap();

	int getWidth() { return width; };
	int getHeight() { return height; };

	unsigned int getTileNumber() { return tileNumber; };

	bool getColision(sf::Vector2f pPosition);
	bool getColision(int x, int y);

	Tile* getTileType(int pTileID);
	void changeTileOnMap(int pTileID, int x, int y);

	void addNewTile(bool pColision, const char* pImage);
	void changeTile(int pTileID, bool pColision, const char* pImage);
	void deleteTile(int pTileID);

	void draw(sf::RenderWindow* window, float pScale = 1.f);
	void draw(sf::RenderWindow* window, sf::Vector2f screenPosition, float pScale = 1.f);

	void printTileListe();
};

