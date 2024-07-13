#pragma once

#include <SFML/System/Vector2.hpp>

#ifndef GAME_OBJECT
#define GAME_OBJECT

class GameSprite;
class Engine2D;

class GameObject
{
protected:
	class Colider
	{
	private:
		GameObject& owner;
		float radius;
		bool moveAbility;
		bool colideAbility;
	public:
		Colider(GameObject& pOwner, float pRadius, bool pMoveAbility) : owner(pOwner), radius(pRadius), moveAbility(pMoveAbility), colideAbility(true) {};

		float getRadius() const { return radius; }
		sf::Vector2f getPosition() const { return owner.getPositionCenter(); }

		bool getMoveAbility() const { return moveAbility; }
		void setMoveAbility(bool value) { moveAbility = value; }

		bool getColideAbility() const { return colideAbility; }
		void setColideAbility(bool value) { colideAbility = value; }

		double distance(const Colider& other) const;
	};

	Engine2D& game;
	GameSprite* objectSprite;
	
	sf::Vector2f size;
	Colider* colider;

	sf::Vector2f movementVector;

	sf::Vector2f position;

	void loadSprite(const char* href, const sf::Vector2f& pSize);
	void deleteColider();
public:
	GameObject(Engine2D& pGame, const sf::Vector2f& pPosition);
	~GameObject();

	const Engine2D* getGame() const { return &game; }
	Engine2D* getGame() { return &game; }

	void setPosition(const sf::Vector2f& value) { position = value; }

	sf::Vector2f getPosition() const { return position; }
	sf::Vector2f getPositionCenter() const { return position + size * 0.5f; }

	sf::Vector2f getVectorToMouse() const;
	sf::Vector2f getDirectionToMouse() const;

	sf::Vector2f getVectorTo(const GameObject& other) const;
	sf::Vector2f getVectorTo(const GameObject* other) const;
	sf::Vector2f getDirectionTo(const GameObject& other) const;
	sf::Vector2f getDirectionTo(const GameObject* other) const;

	sf::Vector2f getSize() const;

	bool getColideWith(const GameObject& other) const;
	double getDistanceTo(const GameObject& other) const { return colider->distance(*other.colider); }

	bool getMoveAbility() const { return colider->getMoveAbility(); }
	void setMoveAbility(bool value) { colider->setMoveAbility(value); }

	bool getColideAbility() const { return colider->getColideAbility(); }
	void setColideAbility(bool value) { colider->setColideAbility(value); }

	void addImpuls(const sf::Vector2f& value);
	void addImpuls(float x, float y);

	virtual void update();
	void draw();
};

#endif // !GAME_OBJECT