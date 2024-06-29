#include "Entity.h"
#include "Engine2D.h"
#include "MyFunctions.h"

#define ENTITY_LIST game.getGameObjects()
#define ITERATOR DoubleLinkedList<GameObject*>::Iterator

Entity::Entity(Engine2D& pGame, const sf::Vector2f& pPosition) : GameObject{ pGame, pPosition }, movementVector{0, 0}, speed{1}
{
}

void Entity::addImpuls(const sf::Vector2f& value)
{
	movementVector += value;
}

void Entity::addImpuls(float x, float y)
{
	movementVector.x += x;
	movementVector.y += y;
}

void Entity::update()
{
	for (ITERATOR it = ENTITY_LIST.begin(); it != ENTITY_LIST.end(); ++it)
	{
		if (it.value() == this)
			continue;
		float distance = static_cast<float>(getDistanceTo(*it.value()));
		if (distance <= 0)
		{
			sf::Vector2f direction = getVectorTo(*it.value());
			direction = MyFuncs::normolize(direction);
			direction *= distance * distance;
			addImpuls(-direction);
		}
	}


	position += movementVector * (1.f / FRAME_RATE_F);
	movementVector -= movementVector * F;
}
