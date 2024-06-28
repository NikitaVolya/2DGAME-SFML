#include "Engine2D.h"

void Engine2D::initVariables()
{
	window = nullptr;
}

void Engine2D::initWindow()
{
	videoMode.height = SCREEN_HEIGHT;
	videoMode.width = SCREEN_WIDTH;

	window = new sf::RenderWindow(videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(FRAME_RATE);
}

void Engine2D::pollEvents()
{
	kbc.pollEvents(window);

	if (kbc.getEscape())
	{
		window->close();
		return;
	}
}

void Engine2D::updateEntitys()
{
}

void Engine2D::renderEntitys()
{
}

Engine2D::Engine2D()
{
	initVariables();
	initWindow();
}

Engine2D::~Engine2D()
{
	for (DoubleLinkedList<GameObject*>::Iterator it = gameObjectsList.begin();
		it != gameObjectsList.end(); ++it)
		delete it.value();
	gameObjectsList.clear();

	delete window;
	GameSprite::clearSprites();
}

void Engine2D::run()
{
	while (window->isOpen())
	{
		updateEntitys();
		update();

		pollEvents();

		window->clear(sf::Color(0, 0, 0, 255));

		renderEntitys();

		render();

		window->display();
	}
}
