#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <conio.h>

#include "MyFunctions.h"
#include "setup.h"

class TileData
{
public:
	TileData() : colision(false), textureHref("") {};
	TileData(bool pColision, const char* pTextureHref) : colision(pColision), textureHref("") {
		for (int i = 0; i < 43; i++) textureHref[i] = pTextureHref[i];
	};
	bool colision;
	char textureHref[43];
};

class Tile
{
private:
	unsigned int tileID;
	bool colision;
	char textureHref[43];
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Tile(unsigned int pTileID, TileData pData) : Tile(pTileID, pData.colision, pData.textureHref) {};
	Tile(unsigned int pTileID, bool pColision, const char* pImage) : tileID(pTileID), colision(pColision), textureHref("") {setTextrure(pImage); }

	unsigned int getTileID() { return tileID; };
	bool getColision() { return colision; };
	const char* getTextureHref() { return textureHref; };

	void setColision(bool pColision) { colision = pColision; };
	void setTextrure(const char* pImage);

	const TileData toTileData();

	void draw(sf::RenderWindow* window, sf::Vector2f pPosition, const float pScale = 1.f);
};