#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "setup.h"
#include "Entity.h"
#include "Player.h"
#include "KeyBoardManager.h"
#include "MapManager.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	Camera camera;
	KeyBoardManager kbc;
	MapManager mapM;

	Player* player;

	void initVariables();
	void initWindow();

	void pollEvents();

	void update();
	void render();
public:
	Game();
	virtual ~Game();

	void gameLoop();
};