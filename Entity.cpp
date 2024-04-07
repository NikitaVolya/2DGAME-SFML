#include "Entity.h"

void Entity::loadTexture(const char* pFile)
{
	texture.loadFromFile(pFile);
	sf::Vector2u textureSize = texture.getSize();

	sprite.setTexture(texture);
	sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);
}


//Static methods
int Entity::getEntityNumber()
{
	return entityNumber;
}

Entity* Entity::getEntity(int index)
{
	if (0 <= index && index < entityNumber)
		return entityList[index];
	return nullptr;
}

void Entity::addEntity(Entity* pEntity)
{

	Entity** newEntityList = new Entity * [entityNumber + 1];
	for (int i = 0; i < entityNumber; i++)
		newEntityList[i] = entityList[i];
	newEntityList[entityNumber++] = pEntity;

	delete entityList;
	entityList = newEntityList;
}

void Entity::popEntity(int index)
{
	Entity** newEntityList = new Entity * [--entityNumber];
	int move = 0;
	for (int i = 0; i < entityNumber; i++)
		newEntityList[i] = entityList[i < index ? i : i - 1];

	delete entityList;
	entityList = newEntityList;
}

void Entity::popEntity(Entity* pEntity)
{
	int start = 0;
	int end = entityNumber - 1;

	int mid;

	while (start < end)
	{
		mid = (end + start) / 2;
		if (entityList[mid] == pEntity)
			break;
		else if (entityList[mid]->entityId < pEntity->entityId)
			end = mid - 1;
		else
			start = mid + 1;
	}

	popEntity((end + start) / 2);
}

void Entity::clearEntitys()
{
	if (!entityList)
		return;

	for (int i = 0; i < entityNumber; i++)
		delete entityList[i];
	delete[] entityList;
}


//Entity methods

Entity::Entity(sf::Vector2f pPosition) : entityId(globalID++), position(pPosition), rotate(false)
{
	movementVector = sf::Vector2f(0, 0);
	size = sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE);
	speed = 1.f * PIXEL_SIZE;

	loadTexture("resources\\sprites\\empty.png");

	Entity::addEntity(this);
}

Entity::~Entity()
{
}

void Entity::setSpeed(float pValue)
{
	if (pValue < 0)
	{
		std::cout << "[ Entity error : " << this << " ] invalid value to speed\n";
		return;
	}
	speed = pValue * PIXEL_SIZE;
}

void Entity::flip()
{
	sf::Vector2f scale = sprite.getScale();
	sprite.setScale(-scale.x, scale.y);
	rotate = !rotate;
}

void Entity::flipToRight()
{
	if (rotate)
	{
		sf::Vector2f scale = sprite.getScale();
		sprite.setScale(-scale.x, scale.y);
		rotate = !rotate;
	}
}

void Entity::flipToLeft()
{
	if (!rotate)
	{
		sf::Vector2f scale = sprite.getScale();
		sprite.setScale(-scale.x, scale.y);
		rotate = !rotate;
	}
}


void Entity::addMovementImpulse(sf::Vector2f pVector)
{
	movementVector += pVector;
}


void Entity::move()
{
	position += MyFuncs::divisionVector(movementVector, FRAME_RATE);

	sf::Vector2f fVector = movementVector * F;
	movementVector -= MyFuncs::divisionVector(fVector, FRAME_RATE);
}

void Entity::update()
{
	move();
}

void Entity::draw(sf::RenderWindow* window)
{
	sf::Vector2f drawPosition = position;

	if (rotate)
		drawPosition += sf::Vector2f(size.x, 0);

	sprite.setPosition(drawPosition);
	window->draw(sprite);
}