#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class KeyBoardManager
{
private:
	bool up, left, right, bottom, escape;
	sf::Event ev;
public:
	KeyBoardManager();

	bool getUp() { return up; };
	bool getLeft() { return left; };
	bool getRight() { return right; };
	bool getBottom() { return bottom; };
	bool getEscape() { return escape; };

	void pollKeyPressed();
	void pollKeyReleased();
	void pollEvents(sf::RenderWindow* window);
};