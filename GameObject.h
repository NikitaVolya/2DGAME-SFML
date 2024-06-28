#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "setup.h"
#include "MyFunctions.h"
#include "GameSprite.h"

class GameObject
{
protected:
	class Colider
	{
	private:
		GameObject& owner;
		float radius;
	public:
		Colider(GameObject& pOwner, float pRadius) : owner{ pOwner }, radius{ pRadius } {};

		float getRadius() const { return radius; }
		sf::Vector2f getPosition() const { return owner.getCenterPosition(); }

		bool colideWith(const Colider& other) { return getDistance(other) <= 0; };
		sf::Vector2f vectorForce(const Colider& other);

		double getDistance(const Colider& other);
	};

	GameSprite* gameSprite;
	Colider* colider;

	sf::Vector2f movementVector;

	sf::Vector2f position;
	sf::Vector2f size;
	bool rotate;
public:
	GameObject(const sf::Vector2f& pPosition);
	~GameObject();

	sf::Vector2f getPosition() const { return position; }
	sf::Vector2f getCenterPosition() const { return position + size * 0.5f; }
	sf::Vector2f getSize() const { return size; }
	bool getRotate() const { return rotate; }

	const Colider& getColider() const { return *colider; }

	void setPosition(const sf::Vector2f& pPosition) { position = pPosition; };
	void setRotate(bool pValue) { rotate = pValue; }

	sf::Vector2f getMovementVector() { return movementVector; };
	void addMovementImpulse(const sf::Vector2f& pVector);

	virtual void events() {};
	void update(const DoubleLinkedList<GameObject*>& gameObjectList);
	virtual void draw(sf::RenderWindow* window, const sf::Vector2f& pCameraPosition);
};