#include "Entity.h"
#include "Engine2D.h"
#include "MyFunctions.h"

#define ENTITY_LIST game.getGameObjects()

Entity::Entity(Engine2D& pGame, const sf::Vector2f& pPosition) : GameObject{ pGame, pPosition }, speed{1}
{
}


void Entity::update()
{
	for (auto it = ENTITY_LIST.begin(); it; ++it)
	{
		if (*it == this || !(*it)->getColideAbility())
			continue;
		float distance = static_cast<float>(getDistanceTo(**it));
		if (distance <= 0)
		{
			sf::Vector2f direction = getVectorTo(**it);
			direction = MyFuncs::normolize(direction);
			direction *= distance * distance;
			addImpuls(-direction);
		}
	}


	GameObject::update();
}

void Entitys::ShooterEntity::update()
{
	skill.update();
	skill.execute(getDirectionTo(game.getPlayer()));

	float moveFrame = game.getTime() / (walkTime * FRAME_RATE_F) * 2 * Pi;
	addImpuls(direction * sinf(moveFrame) * PIXEL_SIZE_F);

	GameObject::update();
}
