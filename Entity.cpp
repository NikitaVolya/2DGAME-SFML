#include "Entity.h"



//Static methods
void Entity::addEntity(Entity* pEntity)
{
	int i = 0;
	for (; i < EntityList->size(); i++)
	{
		if (pEntity->getEntityID() > EntityList->at(i)->getEntityID())
			break;
	}
	EntityList->emplace(EntityList->begin() + i, pEntity);
}

void Entity::popEntity(int index)
{
	EntityList->erase(EntityList->begin() + index);
}

void Entity::clearEntitys()
{
	std::cout << "[ INFO ] Entitys: clear entitys\n";

	for (int i = 0; i < EntityList->size(); i++)
		delete EntityList->at(i);
	delete EntityList;

	std::cout << "[ INFO ] Entitys: clear entitys - done\n";
}

//private functions
void Entity::loadTexture(const char* pFile)
{
	MyFuncs::loadTexture(pFile, &texture, &sprite, size);
}


//Entity methods

Entity::Entity(sf::Vector2f pPosition) : entityId(GlobaEntitylID++), position(pPosition), rotate(false)
{
	movementVector = sf::Vector2f(0, 0);
	size = sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE);
	speed = 1.f * PIXEL_SIZE;

	loadTexture("resources\\sprites\\empty.png");

	colideBox = new ColiderBox(*this, sf::Vector2f(.6f, .2f));

	Entity::addEntity(this);
}

Entity::~Entity()
{
	delete colideBox;
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

void Entity::update(MapManager* mapM)
{
	if (!colideBox->isColide(mapM, movementVector.x, 0))
		position.x += movementVector.x * (1.f / FRAME_RATE);

	if (!colideBox->isColide(mapM, 0, movementVector.y))
		position.y += movementVector.y * (1.f / FRAME_RATE);

	movementVector -= movementVector * F;
}

void Entity::draw(sf::RenderWindow* window, sf::Vector2f pCameraPosition)
{
	sf::Vector2f drawPosition = position - pCameraPosition;

	if (rotate)
		drawPosition += sf::Vector2f(size.x, 0);

	sprite.setPosition(drawPosition);
	window->draw(sprite);
}

Entity::ColiderBox::ColiderBox(Entity& pOwner, sf::Vector2f pSize)
	: owner(pOwner)
{
	size = sf::Vector2f(pSize.x * pOwner.getSize().x, pSize.y * pOwner.getSize().y);
	position = pOwner.getSize() - size;
	position.x -= (pOwner.getSize().x - size.x) / 2;
}

bool Entity::ColiderBox::isColide(const MapManager* mapM, const sf::Vector2f& moveVector)
{
	sf::Vector2f deltaPosition = moveVector * (1.f / FRAME_RATE);

	float positionLeft = owner.getPosition().x + position.x + deltaPosition.x;
	float positionRight = owner.getPosition().x + position.x + size.x + deltaPosition.x;

	float positionTop = owner.getPosition().y + position.y + deltaPosition.y;
	float positionBottom = owner.getPosition().y + position.y + size.y + deltaPosition.y;

	return mapM->getColision(positionLeft, positionTop) ||
		mapM->getColision(positionRight, positionTop) ||
		mapM->getColision(positionRight, positionBottom) ||
		mapM->getColision(positionLeft, positionBottom);
}
