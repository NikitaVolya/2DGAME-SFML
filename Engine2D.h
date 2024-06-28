#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "setup.h"
#include "Camera.h"
#include "Entity.h"
#include "KeyBoardManager.h"


class Engine2D
{
protected:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	DoubleLinkedList<GameObject*> gameObjectsList;

	Camera camera;
	KeyBoardManager kbc;

	virtual void initVariables();
	void initWindow();

	void pollEvents();

	virtual void update() = 0;
	virtual void render() = 0;

	void updateEntitys();
	void renderEntitys();
public:
	Engine2D();
	virtual ~Engine2D();

	void run();
};

