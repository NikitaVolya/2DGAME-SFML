#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>
#include <string.h>
#include <map>

#include "DoubleLinkedListe.h"
#include "setup.h"

class GameSprite
{
private:
	static DoubleLinkedList<GameSprite*> GameSpriteListe;
	size_t spriteID;
	sf::Texture texture;
	sf::Sprite sprite;

	bool rotate;

	void uploadSprite();
	GameSprite(size_t ID) : spriteID(ID), rotate(false) { uploadSprite(); };
public:
	
	static GameSprite* loadSprite(size_t ID);
	static void clearSprites();

	void flip();

	size_t getId() const { return spriteID; }

	void draw(sf::RenderWindow* renderWindow, sf::Vector2f position, bool rotate = false);
};