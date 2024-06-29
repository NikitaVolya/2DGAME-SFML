#include "Engine2D.h"
#include "GameObject.h"

#define ITERATOR DoubleLinkedList<GameObject*>::Iterator

void Engine2D::initVariables()
{
	window = nullptr;

	player = new Player{ *this, sf::Vector2f(PIXEL_SIZE * 2, PIXEL_SIZE * 2) };
	gameObjectsListe.add(player);
	gameObjectsListe.append(new Entity{ *this, sf::Vector2f(PIXEL_SIZE * 3, PIXEL_SIZE * 2) });
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

void Engine2D::update()
{
	for (ITERATOR it = gameObjectsListe.begin();
		it != gameObjectsListe.end(); ++it)
		it.value()->update();
}

void Engine2D::render()
{
	for (ITERATOR it = gameObjectsListe.begin();
		it != gameObjectsListe.end(); ++it)
		it.value()->draw();
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
	delete window;
	
	for (DoubleLinkedList<GameObject*>::Iterator it = gameObjectsListe.begin();
		it != gameObjectsListe.end(); ++it)
		delete it.value();
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
