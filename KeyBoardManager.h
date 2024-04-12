#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

class KeyBoardManager
{
private:
	bool up, left, right, bottom, escape;
	bool mouseLeft, mouseRight;
	int mouseWheel;

	sf::Vector2i mousePosition;

	void pollKeyPressed(sf::Event& ev);
	void pollKeyReleased(sf::Event& ev);

	void pollMousePressed(sf::Event& ev);
	void pollMouseReleased(sf::Event& ev);
public:
	KeyBoardManager() : up(false), left(false), right(false), bottom(false), escape(false), mouseLeft(false), mouseRight(false), mouseWheel(0) {};

	bool getUp() { return up; };
	bool getLeft() { return left; };
	bool getRight() { return right; };
	bool getBottom() { return bottom; };
	bool getEscape() { return escape; };

	bool getMouseLeft() { return mouseLeft; };
	bool getMouseRight() { return mouseRight; };

	int getMouseWheel() { return mouseWheel; };

	sf::Vector2i getMousePosition() { return mousePosition; };

	void pollEvents(sf::RenderWindow* window);
};