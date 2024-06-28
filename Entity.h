#pragma once

#include "GameObject.h"

class Entity : public GameObject
{
private:
	float speed;
public:
	Entity(const sf::Vector2f& pPosition);
	~Entity();

	float getSpeed() const { return speed; };

	void setSpeed(float pValue);

	virtual void events() override {};
};

