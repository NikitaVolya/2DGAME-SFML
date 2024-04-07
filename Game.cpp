#include "Game.h"

void Game::initVariables()
{
	window = nullptr;
}

void Game::initWindow()
{
	videoMode.height = SCREEN_HEIGHT;
	videoMode.width = SCREEN_WIDTH;
	
	window = new sf::RenderWindow(videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(FRAME_RATE);
}


Game::Game()
{
	player = new Player(&kbc , sf::Vector2f(0.f, 0.f));

	initVariables();
	initWindow();
}

Game::~Game()
{
	Entity::clearEntitys();

	delete window;
}

const bool Game::isRunning() const
{
	return window->isOpen();
}

void Game::update()
{
	kbc.pollEvents(window);

	if (kbc.getEscape())
	{
		window->close();
		return;
	}

	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->update();
}

void Game::render()
{
	window->clear(sf::Color(0, 0, 0, 255));

	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->draw(window);

	window->display();
}