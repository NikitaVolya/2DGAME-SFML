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
	delete entityList[index];
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
	std::cout << "[ INFO ] Entitys: clear entitys\n";

	if (!entityList)
		return;

	for (int i = 0; i < entityNumber; i++)
		delete entityList[i];
	delete[] entityList;

	entityNumber = 0;

	std::cout << "[ INFO ] Entitys: clear entitys - done\n";
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


void Entity::move(MapManager* mapM)
{
	sf::Vector2f deltaPosition = MyFuncs::divisionVector(movementVector, FRAME_RATE);

	float positionLeft = position.x + size.x * .4f;
	float positionRight = position.x + size.x * .6f;

	float positionTop = position.y + size.y * .6f;
	float positionBottom = position.y + size.y * .9f;

	if (mapM->getColision(positionLeft + deltaPosition.x, positionTop) ||
		mapM->getColision(positionRight + deltaPosition.x, positionTop) ||
		mapM->getColision(positionRight + deltaPosition.x, positionBottom) ||
		mapM->getColision(positionLeft + deltaPosition.x, positionBottom))
		deltaPosition.x = 0;

	if (mapM->getColision(positionLeft, positionTop + deltaPosition.y) ||
		mapM->getColision(positionRight, positionTop + deltaPosition.y) ||
		mapM->getColision(positionRight, positionBottom + deltaPosition.y) ||
		mapM->getColision(positionLeft, positionBottom + deltaPosition.y))
		deltaPosition.y = 0;

	position += deltaPosition;

	sf::Vector2f fVector = movementVector * F;
	movementVector -= MyFuncs::divisionVector(fVector, FRAME_RATE);
}

void Entity::update(MapManager* mapM)
{
	move(mapM);
}

void Entity::draw(sf::RenderWindow* window, Camera* camera)
{
	sf::Vector2f drawPosition = position - camera->getPosition();

	if (rotate)
		drawPosition += sf::Vector2f(size.x, 0);

	sprite.setPosition(drawPosition);
	window->draw(sprite);
}