#pragma once

#include "Engine2D.h"
#include "Player.h"

class Game : public Engine2D
{
private:
	Player* player;

	void update() override;
	void render() override;
public:
	Game();
	~Game();
};