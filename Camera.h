#pragma once


#include <SFML/Graphics/RenderWindow.hpp>

#include "setup.h"
#include "MyFunctions.h"
#include "Entity.h"

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
	void setSpeed(float pSpeed) { if (pSpeed <= 0) return; cameraSpeed = pSpeed; }
	void setScale(float pScale) { if (pScale <= 0) return; cameraScale = pScale; }

	void moveCamera(float x, float y) { moveCamera(sf::Vector2f(x, y)); }
	void moveCamera(sf::Vector2f pVector);

	void moveTo(Entity* pEntity);

	void draw(sf::RenderWindow* window);
};