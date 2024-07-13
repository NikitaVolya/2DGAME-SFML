#include "Projectile.h"
#include "Engine2D.h"

Projectile::Projectile(Engine2D& pGame, GameObject* pOwner, const sf::Vector2f& pPosition, const sf::Vector2f& pDirection, float pSpeed, size_t pLiveTime) :
	GameObject(pGame, pPosition), owner(pOwner), moveDirection(pDirection), speed(pSpeed * PIXEL_SIZE_F), liveTime(pLiveTime * FRAME_RATE)
{
	loadSprite("resources\\sprites\\projectiles\\fireball.png", size);
	setColideAbility(false);
}

void Projectile::update()
{
	action();

	addImpuls(moveDirection * speed);
	if (!liveTime--)
		game.killGameObject(this);

	GameObject::update();
}

void Projectiles::FireBall::action()
{
	for (auto it = game.getGameObjects().begin(); it; ++it)
	{
		if (it.value() == this || *it == owner)
			continue;
		if (getDistanceTo(**it) <= 0)
		{
			game.killGameObject(*it);
			game.killGameObject(this);
		}
	}
}
