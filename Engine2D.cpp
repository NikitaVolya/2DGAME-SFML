#include "Engine2D.h"
#include "GameObject.h"

#define GAME_OBJECT_LIST DoubleLinkedList<GameObject*>

void Engine2D::initVariables()
{
	window = nullptr;
	time = 0;

	player = new Player{ *this, sf::Vector2f(PIXEL_SIZE * 2, PIXEL_SIZE * 2) };
	gameObjectsListe.add(player);

	gameObjectsListe.append(new Entitys::ShooterEntity{ *this, sf::Vector2f(PIXEL_SIZE * 12, PIXEL_SIZE * 1), sf::Vector2f{0, 1}, 7 });
	gameObjectsListe.append(new Entitys::ShooterEntity{ *this, sf::Vector2f(PIXEL_SIZE * 6, PIXEL_SIZE * 2), sf::Vector2f{1, 1}, 5 });
	gameObjectsListe.append(new Entitys::ShooterEntity{ *this, sf::Vector2f(PIXEL_SIZE * 5, PIXEL_SIZE * 4), sf::Vector2f{0, 1}, 2 });
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
	time++;

	deleteToKillObjects();
}

void Engine2D::render()
{
	for (GAME_OBJECT_LIST::Revers_Iterator it = gameObjectsListe.rbegin(); it; ++it)
		(*it)->draw();
}

void Engine2D::updateEntitys()
{
	for (GAME_OBJECT_LIST::Forward_Iterator it = gameObjectsListe.begin(); it; ++it)
		(*it)->update();
}

void Engine2D::deleteToKillObjects()
{
	if (toDeleteListe.lenght() > 0)
	{
		for (auto it = toDeleteListe.begin(); it; ++it)
		{
			GameObject* tmp = gameObjectsListe.remove(*it);
			delete tmp;
		}
		toDeleteListe.clear();
	}
}

Engine2D::Engine2D()
{
	initVariables();
	initWindow();
}

Engine2D::~Engine2D()
{
	delete window;
	
	for (auto it = gameObjectsListe.begin(); it; ++it)
		delete *it;
}

void Engine2D::addEntity(GameObject* obj)
{
	int index = gameObjectsListe.find(obj);
	if (index != -1)
		return;

	gameObjectsListe.add(obj);
}

void Engine2D::killGameObject(GameObject* obj)
{
	bool find = false;
	for (auto it = toDeleteListe.begin(); it; ++it)
	{
		if (*it == obj)
		{
			find = true;
			break;
		}
	}

	if (!find)
		toDeleteListe.append(obj);
}

void Engine2D::run()
{
	while (window->isOpen())
	{
		updateEntitys();
		update();

		pollEvents();

		window->clear(sf::Color(0, 0, 0, 255));

		render();

		window->display();
	}
}
