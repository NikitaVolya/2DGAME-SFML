#include "MapEditor.h"

void MapEditor::update()
{
	pollEvents();

	tileBoard->update(&kbc, paintbrush);

	if (kbc.getMouseLeft())
	{
		sf::Vector2i position = kbc.getMousePosition() + sf::Vector2i(camera.getPosition().x, camera.getPosition().y);


		if (kbc.getMousePosition().y < SCREEN_HEIGHT - tileBoard->getHeight())
		{
			position = MyFuncs::divisionVector(position, camera.getScale() * PIXEL_SIZE);

			mapM.changeTileOnMap(paintbrush, position.x, position.y);
		}
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

	camera.setScale(camera.getScale() + kbc.getMouseWheel() / 10.f);
}

void MapEditor::render()
{
	mapM.draw(window, &camera);
	tileBoard->draw(window);
}

MapEditor::MapEditor() : Engine2D()
{
	paintbrush = 0;
	tileBoard = new TilesBoard(mapM);
}

MapEditor::~MapEditor()
{
	std::cout << "[ INFO ] MapEditor: destructor\n";
	delete tileBoard;
}