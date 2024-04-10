#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "MyFunctions.h"
#include "setup.h"

class TileData
{
public:
	TileData() : colision(false), textureHref("") {};
	TileData(bool pColision, const char* pTextureHref) : colision(pColision), textureHref("") { MyFuncs::CharCpy(textureHref, pTextureHref, 43);};
	bool colision;
	char textureHref[43];
};

class Tile
{
private:
	unsigned short tileID;
	bool colision;
	char textureHref[43];
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Tile(unsigned short pTileID, TileData pData) : Tile(pTileID, pData.colision, pData.textureHref) {};
	Tile(unsigned short pTileID, bool pColision, const char* pImage) : tileID(pTileID), colision(pColision), textureHref("") {setTextrure(pImage); }

	unsigned int getTileID() const { return tileID; };
	bool getColision() const { return colision; };
	const char* getTextureHref() const { return textureHref; };

	void setColision(const bool pColision) { colision = pColision; };
	void setTextrure(const char* pImage);

	const TileData toTileData() const;

	void draw(sf::RenderWindow* window, const sf::Vector2f pPosition, const float pScale = 1.f);
};