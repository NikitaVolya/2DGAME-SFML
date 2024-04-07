#include "KeyBoardManager.h"

KeyBoardManager::KeyBoardManager()
{
	escape = false;
	up = false;
	left = false;
	right = false;
	bottom = false;
}

void KeyBoardManager::pollKeyPressed()
{
	if (ev.key.code == sf::Keyboard::Escape)
		escape = true;
	if (ev.key.code == sf::Keyboard::W)
		up = true;
	if (ev.key.code == sf::Keyboard::A)
		left = true;
	if (ev.key.code == sf::Keyboard::S)
		bottom = true;
	if (ev.key.code == sf::Keyboard::D)
		right = true;
}

void KeyBoardManager::pollKeyReleased()
{
	if (ev.key.code == sf::Keyboard::Escape)
		escape = false;
	if (ev.key.code == sf::Keyboard::W)
		up = false;
	if (ev.key.code == sf::Keyboard::A)
		left = false;
	if (ev.key.code == sf::Keyboard::S)
		bottom = false;
	if (ev.key.code == sf::Keyboard::D)
		right = false;
}

void KeyBoardManager::pollEvents(sf::RenderWindow* window)
{

	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			escape = true;
			break;
		case sf::Event::KeyPressed:
			pollKeyPressed();
			break;
		case sf::Event::KeyReleased:
			pollKeyReleased();
			break;
		}
	}
}
