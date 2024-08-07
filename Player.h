#pragma once

#ifndef PLAYER
#define PLAYER

#include "Entity.h"

class Engine2D;

class Player : public Entity
{
private:
	Skill::FireBall skill;
public:
	Player(Engine2D& pGame, const sf::Vector2f& pPosition);

	void update() override;
};


#endif // !PLAYER