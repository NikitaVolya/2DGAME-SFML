#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>
#include <vector>

#include "setup.h"
#include "MapManager.h"
#include "MyFunctions.h"

class Entity
{
private:
	static int GlobaEntitylID;
	static std::vector<Entity*>* EntityList;
public:
	static size_t getEntityNumber() { return EntityList->size(); };
	static Entity* getEntity(int index) { return EntityList->at(index); };

	static void addEntity(Entity* pEntity);
	static void popEntity(int index);
	static void clearEntitys();

private:
	int entityId;

	sf::Texture texture;
	sf::Sprite sprite;
	bool rotate;

	sf::Vector2f movementVector;

	class ColiderBox
	{
	private:
		Entity& owner;
		sf::Vector2f position;
		sf::Vector2f size;
	public:
		ColiderBox(Entity& pOwner, sf::Vector2f pSize);

		bool isColide(const MapManager* mapM, const sf::Vector2f& moveVector);
		bool isColide(const MapManager* mapM, float x, float y) { return isColide(mapM, sf::Vector2f(x, y)); };
	};
	ColiderBox* colideBox;
protected:
	sf::Vector2f position;
	sf::Vector2f size;

	float speed;

	void loadTexture(const char* pFile);
public:

	Entity(sf::Vector2f pPosition);
	~Entity();

	int getEntityID() const { return entityId; };
	sf::Vector2f getPosition() const { return position; };
	sf::Vector2f getCenterPosition() const { return position + size * 0.5f; }
	sf::Vector2f getSize() const { return size; };
	float getSpeed() const { return speed; };
	int getRotate() const { return rotate ? -1 : 1; };

	void setPosition(sf::Vector2f pPosition) { position = pPosition; };
	void setSpeed(float pValue);

	void flip();
	void flipToRight();
	void flipToLeft();

	sf::Vector2f getMovementVector() { return movementVector; };
	void addMovementImpulse(sf::Vector2f pVector);

	virtual void update(MapManager* mapM);
	virtual void draw(sf::RenderWindow* window, sf::Vector2f pCameraPosition);
};

