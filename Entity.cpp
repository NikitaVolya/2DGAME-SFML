#include "Entity.h"

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

	entityNumber = 0;
}

void Entity::setMapManager(MapManager* pMapM)
{
	mapM = pMapM;
}


//private functions
void Entity::loadTexture(const char* pFile)
{
	MyFuncs::loadTexture(pFile, &texture, &sprite, size);
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
	sf::Vector2f deltaPosition = MyFuncs::divisionVector(movementVector, FRAME_RATE);

	sf::Vector2f positionLeftTop = position + sf::Vector2f(0, size.y * 0.6f);
	sf::Vector2f positionRightTop = position + sf::Vector2f(size.x, size.y * 0.6f);
	sf::Vector2f positionLeftBottom = position + sf::Vector2f(size.x * 0.1f, size.y * 0.9f);
	sf::Vector2f positionRightBottom = position + sf::Vector2f(size.x * 0.8f, size.y * 0.9f);

	if (!Entity::mapM->getColision(positionLeftTop.x + deltaPosition.x, positionLeftTop.y) && 
		!Entity::mapM->getColision(positionRightTop.x + deltaPosition.x, positionRightTop.y) &&
		!Entity::mapM->getColision(positionLeftBottom.x + deltaPosition.x, positionLeftBottom.y) &&
		!Entity::mapM->getColision(positionRightBottom.x + deltaPosition.x, positionRightBottom.y))
		position.x += deltaPosition.x;

	if (!Entity::mapM->getColision(positionRightTop.x, positionRightTop.y + deltaPosition.y) &&
		!Entity::mapM->getColision(positionRightTop.x, positionRightTop.y + deltaPosition.y) &&
		!Entity::mapM->getColision(positionLeftBottom.x, positionLeftBottom.y + deltaPosition.y) &&
		!Entity::mapM->getColision(positionRightBottom.x, positionRightBottom.y + deltaPosition.y))
		position.y += deltaPosition.y;

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