#pragma once

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "setup.h"

class GameSprite
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f size;
	bool rotate;
public:
	GameSprite(const char* href, const sf::Vector2f& pSize);

	void rotateRight();
	void rotateLeft();
	void rotateSprite();

	void draw(sf::RenderWindow* window, const sf::Vector2f& pPosition);
};


#endif // !GAME_SPRITE_H