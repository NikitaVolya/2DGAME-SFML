#pragma once

#ifndef ENGINE_2D_H
#define ENGINE_2D_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "setup.h"
#include "KeyBoardManager.h"
#include "DoubleLinkedListe.h"
#include "Player.h"

class GameObject;
class Entity;

class Engine2D
{
protected:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	KeyBoardManager kbc;

	Player* player;

	DoubleLinkedList<GameObject*> gameObjectsListe;

	void initVariables();
	void initWindow();

	void pollEvents();

	void update();
	void render();

	void updateEntitys();
	void renderEntitys();
public:
	Engine2D();
	~Engine2D();

	const KeyBoardManager& getKeyBoardManager() const { return kbc; }
	sf::RenderWindow* getWindow() { return window; }
	DoubleLinkedList<GameObject*>& getGameObjects() { return gameObjectsListe; }
	const DoubleLinkedList<GameObject*>& getGameObjects() const { return gameObjectsListe; }

	void run();
};

#endif // !ENGINE_2D_H