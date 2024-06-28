#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f& pPosition) : 
	gameSprite(nullptr), movementVector{ 0, 0 }, position{ pPosition },
	size{PIXEL_SIZE, PIXEL_SIZE}, rotate(false)
{
	gameSprite = GameSprite::loadSprite(1);
	colider = new Colider{ *this, size.x * 0.45f };
}

GameObject::~GameObject()
{
	delete colider;
}

void GameObject::addMovementImpulse(const sf::Vector2f& pVector)
{
	movementVector += pVector;
}

void GameObject::update(const DoubleLinkedList<GameObject*>& gameObjectList)
{
	events();

	for (DoubleLinkedList<GameObject*>::Iterator it = gameObjectList.begin();
		it != gameObjectList.end(); ++it)
	{
		movementVector += colider->vectorForce(it.value()->getColider());
	}

	position += movementVector * (1.f / FRAME_RATE);
	movementVector -= movementVector * F;
}

void GameObject::draw(sf::RenderWindow* window, const sf::Vector2f& pCameraPosition)
{
	sf::Vector2f drawPosition = position - pCameraPosition;
	gameSprite->draw(window, drawPosition, rotate);
}

sf::Vector2f GameObject::Colider::vectorForce(const Colider& other)
{
	if (&other == this)
		return sf::Vector2f{ 0, 0 };
	float dist = static_cast<float>(getDistance(other));
	if (dist > 0)
		return sf::Vector2f{ 0, 0 };
	sf::Vector2f direction = other.getPosition() - getPosition();
	direction = MyFuncs::normolize(direction);

	return direction * -(dist * dist);
}

double GameObject::Colider::getDistance(const Colider& other)
{
	sf::Vector2f dis = other.getPosition() - getPosition();
	return MyFuncs::lenghtVector(dis) - radius - other.getRadius();
}
