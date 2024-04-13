#include "Game.h"

void Game::update()
{
	

	camera.moveCamera(0, 1);
}

void Game::render()
{
	
}

Game::Game() : Engine2D()
{
	player = new Player(kbc, sf::Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE));
}

Game::~Game()
{
	std::cout << "[ INFO ] Game: destructor\n";
}
