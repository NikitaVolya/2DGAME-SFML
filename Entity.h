#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
protected:
	sf::Vector2f movementVector;

	float speed;
public:
	Entity(Engine2D& pGame, const sf::Vector2f& pPosition);

	void addImpuls(const sf::Vector2f& value);
	void addImpuls(float x, float y);

	virtual void update();
};


#endif // !ENTITY_H