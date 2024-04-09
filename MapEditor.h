#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "setup.h"
#include "KeyBoardManager.h"
#include "MapManager.h"
#include "TilesBoard.h"

class MapEditor
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	sf::Vector2f screenPosition;

	KeyBoardManager kbc;
	MapManager mapM;
	TilesBoard* tileBoard;

	float scale;
	float speed;

	int paintbrush;

	void initVariables();
	void initWindow();

	void pollEvents();

	void update();
	void render();
public:
	MapEditor();
	virtual ~MapEditor();

	void gameLoop();
};