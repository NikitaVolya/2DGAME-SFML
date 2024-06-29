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

	bool getUp() const { return up; };
	bool getLeft() const { return left; };
	bool getRight() const { return right; };
	bool getBottom() const { return bottom; };
	bool getEscape() const { return escape; };

	bool getMouseLeft() const { return mouseLeft; };
	bool getMouseRight() const { return mouseRight; };

	int getMouseWheel() const { return mouseWheel; };

	sf::Vector2i getMousePosition() { return mousePosition; };
	sf::Vector2f getMousePositionF() { return sf::Vector2f((float)mousePosition.x, (float)mousePosition.y); };

	void pollEvents(sf::RenderWindow* window);
};