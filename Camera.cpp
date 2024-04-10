#include "Camera.h"

void Camera::setSpeed(float pSpeed)
{
	if (pSpeed <= 0)
		return;
	cameraSpeed = pSpeed;
}

void Camera::setScale(float pScale)
{
	if (pScale <= 0)
		return;
	cameraScale = pScale;
}

void Camera::moveCamera(float x, float y)
{
	moveCamera(sf::Vector2f(x, y));
}

void Camera::moveCamera(sf::Vector2f pVector)
{
	position += MyFuncs::divisionVector(pVector, FRAME_RATE) * cameraSpeed;
}

void Camera::draw(sf::RenderWindow* window)
{

}