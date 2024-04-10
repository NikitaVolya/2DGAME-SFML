#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "setup.h"
#include "MyFunctions.h"

class Camera
{
private:
	sf::Vector2f position;
	float cameraSpeed, cameraScale;
public:
	Camera() : position{ 0, 0 }, cameraSpeed(2), cameraScale(1) {};

	sf::Vector2f getPosition() const { return position; };
	float getSpeed() const { return cameraSpeed; };
	float getScale() const { return cameraScale; };

	void setPosition(sf::Vector2f pPosition) { position = pPosition; };
	void setSpeed(float pSpeed);
	void setScale(float pScale);

	void moveCamera(float x, float y);
	void moveCamera(sf::Vector2f pVector);

	void draw(sf::RenderWindow* window);
};