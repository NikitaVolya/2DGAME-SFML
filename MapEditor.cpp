#include "MapEditor.h"

void MapEditor::update()
{
	pollEvents();

	if (kbc.getMousePosition().y > 0 && kbc.getMousePosition().y < SCREEN_HEIGHT)
	{
		
		camera.setScale(camera.getScale() + kbc.getMouseWheel() / 10.f);
	}

	sf::Vector2f cameraMoveVector(0, 0);
	if (kbc.getUp())
		cameraMoveVector.y -= PIXEL_SIZE * 2;
	if (kbc.getLeft())
		cameraMoveVector.x -= PIXEL_SIZE * 2;
	if (kbc.getBottom())
		cameraMoveVector.y += PIXEL_SIZE * 2;
	if (kbc.getRight())
		cameraMoveVector.x += PIXEL_SIZE * 2;
	camera.moveCamera(cameraMoveVector);

	
}

void MapEditor::render()
{
}

MapEditor::MapEditor() : Engine2D()
{
	paintbrush = 0;
}

MapEditor::~MapEditor()
{
	std::cout << "[ INFO ] MapEditor: destructor\n";
}