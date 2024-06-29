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

	public:
		Colider(GameObject& pOwner, float pRadius) : owner(pOwner), radius(pRadius) {};

		float getRadius() const { return radius; }
		sf::Vector2f getPosition() const { return owner.getPositionCenter(); }

		bool colideWith(const Colider& other) const;
		double distance(const Colider& other) const;
	};

	Engine2D& game;
	GameSprite* objectSprite;
	

	sf::Vector2f size;
	Colider colider;

	sf::Vector2f position;
public:
	GameObject(Engine2D& pGame, const sf::Vector2f& pPosition);
	~GameObject();

	const Engine2D* getGame() const { return &game; }

	sf::Vector2f getPosition() const { return position; }
	sf::Vector2f getPositionCenter() const { return position + size * 0.5f; }
	const Colider& getColider() const { return colider; }

	sf::Vector2f getVectorTo(const GameObject& other) const { return other.getPositionCenter() - getPositionCenter(); }
	double getDistanceTo(const GameObject& other) const { return colider.distance(other.colider); }

	virtual void update();
	void draw();
};

#endif // !GAME_OBJECT