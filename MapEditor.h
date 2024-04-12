#pragma once

#include "Engine2D.h"
#include "TilesBoard.h"

class MapEditor : public Engine2D
{
private:
	TilesBoard* tileBoard;
	int paintbrush;

	void update();
	void render();
public:
	MapEditor();
	~MapEditor();
};