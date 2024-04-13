#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "setup.h"
#include "Entity.h"
#include "MapManager.h"
#include "KeyBoardManager.h"


class Engine2D
{
protected:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	Camera camera;
	KeyBoardManager kbc;
	MapManager mapM;

	virtual void initVariables();
	void initWindow();

	void pollEvents();

	virtual void update();
	virtual void render();

	void updateEntitys();
	void renderEntitys();
public:
	Engine2D();
	virtual ~Engine2D();

	void run();
};

