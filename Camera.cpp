#include "Camera.h"

void Camera::moveCamera(sf::Vector2f pVector)
{
	position += pVector * (1.f / FRAME_RATE) * cameraSpeed;
}

void Camera::moveTo(Entity* pEntity)
{
	sf::Vector2f positionToCenter = SCREEN_SIZE * .5f - pEntity->getCenterPosition() + position;
	double lengthEntityToCenter = MyFuncs::lenghtVector(positionToCenter);

	if (lengthEntityToCenter < MINIMUM_SCREEN_STEP)
		return;

	sf::Vector2f vectorToCenter = positionToCenter * -1.f;
	MyFuncs::normolize(vectorToCenter);

	sf::Vector2f moveVector = vectorToCenter * (float)(lengthEntityToCenter * lengthEntityToCenter * SPEED_SCREEN_TO_ENTITY) * (1.f / FRAME_RATE);

	position += moveVector;

}

void Camera::draw(sf::RenderWindow* window)
{

}