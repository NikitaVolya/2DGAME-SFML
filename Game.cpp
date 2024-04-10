#include "Game.h"

void Game::initVariables()
{
	window = nullptr;

	mapM.loadMap();
}

void Game::initWindow()
{
	videoMode.height = SCREEN_HEIGHT;
	videoMode.width = SCREEN_WIDTH;
	
	window = new sf::RenderWindow(videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(FRAME_RATE);
}

void Game::pollEvents()
{
	kbc.pollEvents(window);

	if (kbc.getEscape())
	{
		window->close();
		return;
	}
}

void Game::update()
{
	pollEvents();

	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->update();
}

void Game::render()
{
	window->clear(sf::Color(0, 0, 0, 255));

	mapM.draw(window);

	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->draw(window);

	window->display();
}

Game::Game()
{
	Entity::setMapManager(&mapM);

	player = new Player(&kbc, sf::Vector2f(PIXEL_SIZE * 2.f, PIXEL_SIZE * 2.f));

	initVariables();
	initWindow();
}

Game::~Game()
{
	Entity::clearEntitys();

	delete window;
}

void Game::gameLoop()
{
	while (window->isOpen())
	{
		update();

		render();
	}
}