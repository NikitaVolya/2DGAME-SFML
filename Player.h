#pragma once


#include <SFML/Window/Event.hpp>

#include "Entity.h"
#include "KeyBoardManager.h"

class Player : public Entity
{
private:
	KeyBoardManager* kbc;

	sf::Vector2f getDirectionVector();
public:
	Player(KeyBoardManager* pKBC, sf::Vector2f pPosition);
	~Player();

	void update();
};