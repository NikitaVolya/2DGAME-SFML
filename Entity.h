#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"
#include "SkillCounter.h"

class Entity : public GameObject
{
protected:
	

	float speed;
public:
	Entity(Engine2D& pGame, const sf::Vector2f& pPosition);

	virtual void update();
};


namespace Entitys
{
	class ShooterEntity : public Entity
	{
	private:
		float walkTime;
		sf::Vector2f direction;
		size_t shootCD;
		size_t timeToShoot;
		
		Skill::FireBall skill;
	public :
		ShooterEntity(Engine2D& pGame, const sf::Vector2f& pPosition, const sf::Vector2f& pDirection, float pWalkTime) : 
			Entity(pGame, pPosition), direction(pDirection), walkTime(pWalkTime), shootCD(139), timeToShoot(0), skill{*this, 2} {};
		void update() override;
	};
}

#endif // !ENTITY_H