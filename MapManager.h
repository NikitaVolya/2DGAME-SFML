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

	unsigned short width;
	unsigned short height;

	void loadTiles();
	void saveTiles();

	void clearTileList();
	void clearTable();

	
public:
	MapManager();
	~MapManager();

	void createClearMap();

	void loadMap();
	void saveMap();

	short getWidth() const { return width; };
	short getHeight() const { return height; };

	unsigned int getTileNumber() const { return tileNumber; };

	bool getColision(sf::Vector2f& pPosition) const;
	bool getColision(int x, int y) const;
	bool getColision(float x, float y) const;

	Tile* getTileType(int pTileID) const;
	
	void changeTileOnMap(int pTileID, int x, int y);

	void addNewTileType(bool pColision, const char* pImage);
	void changeTileType(int pTileID, bool pColision, const char* pImage);
	void deleteTileType(int pTileID);

	void draw(sf::RenderWindow* window, float pScale = 1.f);
	void draw(sf::RenderWindow* window, sf::Vector2f& screenPosition);
	void draw(sf::RenderWindow* window, sf::Vector2f& screenPosition, float pScale = 1.f);
};

