#include "KeyBoardManager.h"

void KeyBoardManager::pollKeyPressed(sf::Event ev)
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

void KeyBoardManager::pollKeyReleased(sf::Event ev)
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

void KeyBoardManager::pollMousePressed(sf::Event ev)
{
	if (ev.mouseButton.button == sf::Mouse::Left)
		mouseLeft = true;
	if (ev.mouseButton.button == sf::Mouse::Right)
		mouseRight = true;
}

void KeyBoardManager::pollMouseReleased(sf::Event ev)
{
	if (ev.mouseButton.button == sf::Mouse::Left)
		mouseLeft = false;
	if (ev.mouseButton.button == sf::Mouse::Right)
		mouseRight = false;
}

void KeyBoardManager::pollEvents(sf::RenderWindow* window)
{
	mouseWheel = 0;

	mousePosition = sf::Mouse::getPosition() - window->getPosition() - sf::Vector2i(8, 30);
	sf::Event ev;

	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			escape = true;
			break;
		case sf::Event::KeyPressed:
			pollKeyPressed(ev);
			break;
		case sf::Event::KeyReleased:
			pollKeyReleased(ev);
			break;
		case sf::Event::MouseButtonPressed:
			pollMousePressed(ev);
			break;
		case sf::Event::MouseButtonReleased:
			pollMouseReleased(ev);
			break;
		case sf::Event::MouseWheelMoved:
			mouseWheel = ev.mouseWheel.delta;
			break;
		}
	}
}
