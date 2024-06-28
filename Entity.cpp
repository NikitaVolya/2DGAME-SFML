#include "Entity.h"

//Entity methods

Entity::Entity(const sf::Vector2f& pPosition) : GameObject{ pPosition }, speed{PIXEL_SIZE}
{

}

Entity::~Entity()
{

}

void Entity::setSpeed(float pValue)
{
	if (pValue < 0)
	{
		std::cout << "[ Entity error : " << this << " ] invalid value to speed\n";
		return;
	}
	speed = pValue * PIXEL_SIZE;
}