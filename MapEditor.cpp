#include "MapEditor.h"

void MapEditor::initVariables()
{
	window = nullptr;

	screenPosition = sf::Vector2f(0, 0);
	scale = 1.f;
	speed = 2.5f;
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
		sf::Vector2i position = kbc.getMousePosition() + MyFuncs::toVectorInteger(screenPosition);


		if (position.y > 0 && position.y < SCREEN_HEIGHT)
		{
			position = MyFuncs::divisionVector(position, scale * PIXEL_SIZE);

			mapM.changeTileOnMap(paintbrush, position.x, position.y);
		}
	}

	if (kbc.getUp())
		screenPosition.y -= (float)PIXEL_SIZE / FRAME_RATE * speed;
	if (kbc.getLeft())
		screenPosition.x -= (float)PIXEL_SIZE / FRAME_RATE * speed;
	if (kbc.getBottom())
		screenPosition.y += (float) PIXEL_SIZE / FRAME_RATE * speed;
	if (kbc.getRight())
		screenPosition.x += (float)PIXEL_SIZE / FRAME_RATE * speed;

	scale += kbc.getMouseWheel() / 10.f;
}

void MapEditor::render()
{
	window->clear(sf::Color(0, 0, 0, 255));

	mapM.draw(window, screenPosition, scale);
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