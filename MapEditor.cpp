#include "MapEditor.h"

void MapEditor::initVariables()
{
	window = nullptr;

	paintbrush = 0;

	mapM.loadMap();
	
	tileBoard = new TilesBoard(mapM);
}

void MapEditor::initWindow()
{
	videoMode.height = SCREEN_HEIGHT + tileBoard->getHeight();
	videoMode.width = SCREEN_WIDTH;

	window = new sf::RenderWindow(videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(FRAME_RATE);
}

void MapEditor::pollEvents()
{
	kbc.pollEvents(window);

	if (kbc.getEscape())
	{
		window->close();
		mapM.saveMap();
		return;
	}
}

void MapEditor::update()
{
	pollEvents();

	tileBoard->update(&kbc, paintbrush);

	if (kbc.getMouseLeft())
	{
		sf::Vector2i position = kbc.getMousePosition() + sf::Vector2i(camera.getPosition().x, camera.getPosition().y);


		if (kbc.getMousePosition().y < SCREEN_HEIGHT)
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
	window->clear(sf::Color(0, 0, 0, 255));

	mapM.draw(window, &camera);
	tileBoard->draw(window);

	window->display();
}

MapEditor::MapEditor()
{
	initVariables();
	initWindow();
}

MapEditor::~MapEditor()
{
	delete window;
	delete tileBoard;
}

void MapEditor::gameLoop()
{
	while (window->isOpen())
	{
		update();

		render();
	}
}