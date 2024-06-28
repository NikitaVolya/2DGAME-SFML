#pragma once

#include "Engine2D.h"

class MapEditor : public Engine2D
{
private:
	size_t paintbrush;

	void update() override;
	void render() override;
public:
	MapEditor();
	~MapEditor();
};