#pragma once

#include <iostream>

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


	sf::Vector2f& normolize(sf::Vector2f& pVector);
	inline double lenghtVector(const sf::Vector2f& pVector);

	bool questionYesNo(const char* pString);
}