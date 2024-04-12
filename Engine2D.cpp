#include "Engine2D.h"

void Engine2D::initVariables()
{
	window = nullptr;

	mapM.loadMap();
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
}

void Engine2D::render()
{

}

Engine2D::Engine2D()
{
	initVariables();
	initWindow();
}

Engine2D::~Engine2D()
{
	std::cout << "[ INFO ] Engine2D: destructor\n";
	Entity::clearEntitys();

}

void Engine2D::run()
{
	while (window->isOpen())
	{
		

		update();
		pollEvents();

		window->clear(sf::Color(0, 0, 0, 255));

		mapM.draw(window, &camera);

		render();

		window->display();
	}
}
