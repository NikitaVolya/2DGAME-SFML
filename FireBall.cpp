#include "FireBall.h"

EntityData::FireBall::FireBall(sf::Vector2f pPosition, sf::Vector2f pDirection, float pSpeed) : Entity(pPosition)
{
	directionVector = pDirection;
	setSpeed(pSpeed);
}

void EntityData::FireBall::update(MapManager* mapM)
{

	addMovementImpulse(directionVector * speed);

	sf::Vector2f directionX = position;
	sf::Vector2f directionY = position;
	directionX.x += directionVector.x * PIXEL_SIZE;
	directionY.y += directionVector.y * PIXEL_SIZE;

	if (mapM->getColision(directionX))
		directionVector.x = -directionVector.x;
	if (mapM->getColision(directionY))
		directionVector.y = -directionVector.y;

	Entity::update(mapM);
}
