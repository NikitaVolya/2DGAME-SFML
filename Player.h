#pragma once

#include <SFML/Window/Event.hpp>

#include "Entity.h"
#include "KeyBoardManager.h"
#include "Camera.h"


class Player : public Entity
{
private:
	KeyBoardManager& kbc;
	Camera& camera;

	int actionCD;

	sf::Vector2f getDirectionVector();
	sf::Vector2f getVectorToMouse();
public:
	Player(KeyBoardManager& pKBC, Camera& pCamera, sf::Vector2f pPosition);

	void events() override;
};