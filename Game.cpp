#include "Game.h"

void Game::update()
{
	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->update(&mapM);

	camera.moveCamera(0, 1);
}

void Game::render()
{
	for (int i = 0; i < Entity::getEntityNumber(); i++)
		Entity::getEntity(i)->draw(window, &camera);
}

Game::Game() : Engine2D()
{
	player = new Player(&kbc, sf::Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE));
}

Game::~Game()
{
	std::cout << "[ INFO ] Game: destructor\n";
	delete player;
}
