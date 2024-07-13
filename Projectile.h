#pragma once

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : public GameObject
{
protected:
	GameObject* owner;

	sf::Vector2f moveDirection;
	float speed;
	size_t liveTime;
public:
	Projectile(Engine2D& pGame, GameObject* pOwner, const sf::Vector2f& pPosition, const sf::Vector2f& pDirection, float pSpeed, size_t pLiveTime);

	virtual void action() = 0;
	virtual void update();
};

namespace Projectiles {

	class FireBall : public Projectile
	{
	private:
		float damage;
	public:
		FireBall(Engine2D& pGame, GameObject* pOwner, const sf::Vector2f& pPosition, const sf::Vector2f& pDirection, float pDamage)
			: Projectile(pGame, pOwner, pPosition, pDirection, 1, 2), damage(pDamage) {};

		void action() override;
	};
}

#endif // !PROJECTILE_H