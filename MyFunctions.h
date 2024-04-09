#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>

#include "setup.h"

namespace MyFuncs
{
	sf::Vector2i toVectorInteger(sf::Vector2f& pVector);
	sf::Vector2i toVectorInteger(sf::Vector2u& pVector);

	sf::Vector2f toVectorFloat(sf::Vector2i& pVector);
	sf::Vector2f toVectorFloat(sf::Vector2u& pVector);

	
	sf::Vector2f divisionVector(sf::Vector2f& a, sf::Vector2f& b);
	sf::Vector2f divisionVector(sf::Vector2f& a, float number);
	sf::Vector2f divisionVector(sf::Vector2f& a, int number);

	sf::Vector2i divisionVector(sf::Vector2i& a, sf::Vector2i& b);
	sf::Vector2i divisionVector(sf::Vector2i& a, float number);
	sf::Vector2i divisionVector(sf::Vector2i& a, int number);


	sf::Vector2f& normolize(sf::Vector2f& pVector);
	inline double lenghtVector(sf::Vector2f& pVector);

	void loadTexture(const char* pFile, sf::Texture* texture, sf::Sprite* sprite, sf::Vector2f size);
	void loadTexture(const char* pFile, sf::Texture* texture, sf::Sprite* sprite, float size);
	void setScale(sf::Sprite* sprite, const float pScale);
}