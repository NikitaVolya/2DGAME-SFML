#include "GameObject.h"
#include "Engine2D.h"
#include "GameSprite.h"
#include "MyFunctions.h"

void GameObject::loadSprite(const char* href, const sf::Vector2f& pSize)
{
	if (objectSprite)
		delete objectSprite;
	objectSprite = new GameSprite(href, pSize);
}

void GameObject::deleteColider()
{
	if (colider)
		delete colider;
	colider = nullptr;
}

GameObject::GameObject(Engine2D& pGame, const sf::Vector2f& pPosition)
	: game(pGame), objectSprite(nullptr), size{PIXEL_SIZE_F, PIXEL_SIZE_F}, colider{nullptr}, movementVector{0, 0}, position(pPosition)
{
	colider = new Colider{ *this, size.x * 0.45f, true };
	loadSprite("resources\\sprites\\entity\\skeleton2_v2_1.png", size);
}

GameObject::~GameObject()
{
	if (objectSprite)
		delete objectSprite;
	deleteColider();
}

sf::Vector2f GameObject::getVectorToMouse() const
{
	return game.getKeyBoardManager().getMousePositionF() - getPositionCenter();
}

sf::Vector2f GameObject::getDirectionToMouse() const
{
	return MyFuncs::normolize(getVectorToMouse());
}

sf::Vector2f GameObject::getVectorTo(const GameObject& other) const
{
	return other.getPositionCenter() - getPositionCenter();
}

sf::Vector2f GameObject::getVectorTo(const GameObject* other) const
{
	return other->getPositionCenter() - getPositionCenter();
}

sf::Vector2f GameObject::getDirectionTo(const GameObject& other) const
{
	return MyFuncs::normolize(getVectorTo(other));
}

sf::Vector2f GameObject::getDirectionTo(const GameObject* other) const
{
	return MyFuncs::normolize(getVectorTo(other));
}

sf::Vector2f GameObject::getSize() const
{
	return size;
}

bool GameObject::getColideWith(const GameObject& other) const
{
	if (colider == nullptr)
		return false;
	return getDistanceTo(other) <= 0.f;
}

void GameObject::addImpuls(const sf::Vector2f& value)
{
	if (!getMoveAbility())
		return;
	movementVector += value;
}

void GameObject::addImpuls(float x, float y)
{
	if (!getMoveAbility())
		return;
	movementVector.x += x;
	movementVector.y += y;
}

void GameObject::update()
{
	if (movementVector.x != 0)
		if (movementVector.x > 0)
			objectSprite->rotateRight();
		else
			objectSprite->rotateLeft();

	position += movementVector * (1.f / FRAME_RATE_F);
	movementVector -= movementVector * F;
}

void GameObject::draw()
{
	objectSprite->draw(game.getWindow(), position);
}

double GameObject::Colider::distance(const Colider& other) const
{
	return MyFuncs::lenghtVector(other.getPosition() - getPosition()) - radius - other.getRadius();
}
