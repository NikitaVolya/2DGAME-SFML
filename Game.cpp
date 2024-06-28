#include "Game.h"

void Game::update()
{
	for (DoubleLinkedList<GameObject*>::Iterator it = gameObjectsList.begin();
		it != gameObjectsList.end(); ++it)
	{
		it.value()->update(gameObjectsList);
	}
}

void Game::render()
{
	for (DoubleLinkedList<GameObject*>::Iterator it = gameObjectsList.begin();
		it != gameObjectsList.end(); ++it)
	{
		it.value()->draw(window, camera.getPosition());
	}
}

Game::Game() : Engine2D()
{
	player = new Player(kbc, camera, sf::Vector2f(5 * PIXEL_SIZE, 2 * PIXEL_SIZE));
	gameObjectsList.add(player);
	gameObjectsList.append(new Entity(sf::Vector2f(10 * PIXEL_SIZE, 2 * PIXEL_SIZE)));
	gameObjectsList.append(new Entity(sf::Vector2f(10 * PIXEL_SIZE, 2 * PIXEL_SIZE)));
	gameObjectsList.append(new Entity(sf::Vector2f(10 * PIXEL_SIZE, 2 * PIXEL_SIZE)));
}

Game::~Game()
{

}
