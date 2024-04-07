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


class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	KeyBoardManager kbc;

	Player* player;

	void initVariables();
	void initWindow();
public:
	Game();
	virtual ~Game();

	const bool isRunning() const;

	void update();
	void render();
};