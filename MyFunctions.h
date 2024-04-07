#pragma once

#include <SFML/System/Vector2.hpp>
#include <math.h>

namespace MyFuncs
{
	sf::Vector2f divisionVector(sf::Vector2f& a, sf::Vector2f& b);
	sf::Vector2f divisionVector(sf::Vector2f& a, float number);
	sf::Vector2f divisionVector(sf::Vector2f& a, int number);
	sf::Vector2f& normolize(sf::Vector2f& pVector);
	float lenghtVector(sf::Vector2f& pVector);
}