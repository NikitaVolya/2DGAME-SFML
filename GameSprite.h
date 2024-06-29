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
	bool rotate;
public:
	GameSprite(const char* href);

	void draw(sf::RenderWindow* window, const sf::Vector2f& pPosition);
};


#endif // !GAME_SPRITE_H