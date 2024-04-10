#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

#include "setup.h"
#include "MapManager.h"
#include "MyFunctions.h"

class Entity
{
private:
	static int globalID;

	static Entity** entityList;
	static int entityNumber;

	static MapManager* mapM;
public:
	static int getEntityNumber();
	static Entity* getEntity(int index);

	static void addEntity(Entity* pEntity);
	static void popEntity(int index);
	static void popEntity(Entity* pEntity);
	static void clearEntitys();

	static void setMapManager(MapManager* pMapM);
private:

	int entityId;

	sf::Texture texture;
	sf::Sprite sprite;
	bool rotate;

	sf::Vector2f movementVector;
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

	void move();

	virtual void update();
	virtual void draw(sf::RenderWindow* window);
};

