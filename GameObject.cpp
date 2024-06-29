#include "GameObject.h"
#include "Engine2D.h"
#include "GameSprite.h"
#include "MyFunctions.h"

GameObject::GameObject(Engine2D& pGame, const sf::Vector2f& pPosition)
	: game(pGame), size{ PIXEL_SIZE_F, PIXEL_SIZE_F }, colider{ *this, size.x * 0.45f }, position(pPosition)
{
	objectSprite = new GameSprite("resources\\sprites\\entity\\skeleton2_v2_1.png");
}

GameObject::~GameObject()
{
	delete objectSprite;
}

void GameObject::update()
{

}

void GameObject::draw()
{
	objectSprite->draw(game.getWindow(), position);
}

bool GameObject::Colider::colideWith(const Colider& other) const
{
	return distance(other) <= 0.f;
}

double GameObject::Colider::distance(const Colider& other) const
{
	return MyFuncs::lenghtVector(other.getPosition() - getPosition()) - radius - other.getRadius();
}
