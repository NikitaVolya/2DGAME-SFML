#include "Engine2D.h"

void Engine2D::initVariables()
{
	window = nullptr;

	mapM.loadMap();
}

void Engine2D::initWindow()
{
	std::cout << "[ INFO ] Engine2D: init window\n";
	videoMode.height = SCREEN_HEIGHT;
	videoMode.width = SCREEN_WIDTH;

	window = new sf::RenderWindow(videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(FRAME_RATE);
	std::cout << "[ INFO ] Engine2D: init window - done\n";
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

void Engine2D::updateEntitys()
{
	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->update(&mapM);
}

void Engine2D::renderEntitys()
{
	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->draw(window, &camera);
}

Engine2D::Engine2D()
{
	std::cout << "[ INFO ] Engine2D: init\n";
	initVariables();
	initWindow();
	std::cout << "[ INFO ] Engine2D: init - done\n";
}

Engine2D::~Engine2D()
{
	std::cout << "[ INFO ] Engine2D: destructor\n";

	delete window;

	Entity::clearEntitys();
	std::cout << "[ INFO ] Engine2D: destructor - done\n";
}

void Engine2D::run()
{
	while (window->isOpen())
	{
		pollEvents();

		updateEntitys();
		update();

		window->clear(sf::Color(0, 0, 0, 255));

		mapM.draw(window, &camera);
		renderEntitys();

		render();

		window->display();
	}
}
