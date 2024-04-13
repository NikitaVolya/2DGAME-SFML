#include "MapManager.h"


void MapManager::loadTiles()
{
	std::cout << "[ INFO ] MapManager: load tiles\n";

	FILE* f = nullptr;
	fopen_s(&f, "resources\\data\\tilesData", "ab");
	fclose(f);
	fopen_s(&f, "resources\\data\\tilesData", "rb");

	tileNumber = _filelength(_fileno(f)) / sizeof(TileData);
	tileList = new Tile * [tileNumber];

	TileData data;
	for (int i = 0; i < tileNumber; i++)
	{
		fread(&data, sizeof(data), 1, f);
		tileList[i] = new Tile(i, data);
	}

	fclose(f);

	std::cout << "[ INFO ] MapManager: load tiles - done\n";
}

void MapManager::saveTiles()
{
	if (!tileList)
		return;

	std::cout << "[ INFO ] MapManager: save tiles\n";

	FILE* f = nullptr;
	fopen_s(&f, "resources\\data\\tilesData", "wb");
	for (int i = 0; i < tileNumber; i++)
	{
		if (tileList[i])
		{
			TileData data = tileList[i]->toTileData();
			fwrite(&data, sizeof(TileData), 1, f);
		}
		else
		{
			TileData data = tileList[0]->toTileData();
			fwrite(&data, sizeof(TileData), 1, f);
		}
	}

	fclose(f);
	std::cout << "[ INFO ] MapManager: save tiles - done\n";
}


void MapManager::clearTileList()
{
	for (unsigned int i = 0; i < tileNumber; i++)
		delete tileList[i];
	delete[] tileList;
	tileNumber = 0;
}

void MapManager::clearTable()
{
	for (int i = 0; i < (int) height; i++)
		delete[] table[i];
	delete[] table;
	height = 0;
	width = 0;
}


MapManager::MapManager() : tileList(nullptr), tileNumber(0), width(0), height(0), table(nullptr)
{
	loadTiles();
}

MapManager::~MapManager()
{
	clearTable();
	clearTileList();
}

void MapManager::createClearMap()
{
	if (table)
		clearTable();

	width = 10;
	height = 10;
	table = new Tile * *[height];
	for (int y = 0; y < height; y++)
	{
		table[y] = new Tile * [width];
		for (int x = 0; x < width; x++)
			table[y][x] = tileList[0];
	}
}

void MapManager::loadMap()
{
	clearTable();

	std::cout << "[ INFO ] MapManager: start load map\n";

	FILE* f = nullptr;

	fopen_s(&f, "resources\\data\\mapData", "ab");
	fclose(f);
	fopen_s(&f, "resources\\data\\mapData", "rb");

	fread(&width, sizeof(short), 1, f);
	fread(&height, sizeof(short), 1, f);
	
	unsigned short IdData;
	table = new Tile * *[height];
	for (int y = 0; y < height; y++)
	{
		table[y] = new Tile * [width];
		for (int x = 0; x < width; x++)
		{
			fread(&IdData, sizeof(short), 1, f);
			table[y][x] = getTileType(IdData);
		}
	}

	fclose(f);
	std::cout << "[ INFO ] MapManager: load map - done\n";
}

void MapManager::saveMap()
{
	std::cout << "[ INFO ] MapManager: save map\n";

	FILE* f = nullptr;
	fopen_s(&f, "resources\\data\\mapData", "wb");

	fwrite(&width, sizeof(short), 1, f);
	fwrite(&height, sizeof(short), 1, f);

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			unsigned int tileIdData = table[y][x]->getTileID();
			fwrite(&tileIdData, sizeof(short), 1, f);
		}

	fclose(f);
	std::cout << "[ INFO ] MapManager: save map - done\n";
}

bool MapManager::getColision(sf::Vector2f& pPosition) const
{
	sf::Vector2f position = MyFuncs::divisionVector(pPosition, PIXEL_SIZE);
	sf::Vector2i positionInteger = MyFuncs::toVectorInteger(position);

	if (0 > positionInteger.x && positionInteger.x >= width)
		return true;
	if (0 > positionInteger.y && positionInteger.y >= height)
		return true;
	return table[positionInteger.y][positionInteger.x]->getColision();
}

bool MapManager::getColision(int x, int y) const
{
	x /= PIXEL_SIZE;
	y /= PIXEL_SIZE;

	if (0 > x || x >= (int)width)
		return true;
	if (0 > y || y >= (int)height)
		return true;
	return table[y][x]->getColision();
}

bool MapManager::getColision(float x, float y) const
{
	x /= PIXEL_SIZE;
	y /= PIXEL_SIZE;

	if (0 > x || (int)x >= (int)width)
		return true;
	if (0 > y || (int)y >= (int)height)
		return true;
	return table[(int)y][(int)x]->getColision();
}

Tile* MapManager::getTileType(int pTileID) const
{
	if (pTileID < 0 || pTileID >= tileNumber)
	{
		std::cout << "[INFO] MapManager: Invalide tile ID\n";
		return nullptr;
	}
	return tileList[pTileID];
}


void MapManager::changeTileOnMap(int pTileID, int x, int y)
{
	if (pTileID < 0 || pTileID > tileNumber)
	{
		std::cout << "[INFO] MapManager: Invalide tile ID\n";
		return;
	}

	if (x < 0 || x > width)
	{
		std::cout << "[INFO] MapManager: Invalide x position\n";
		return;
	}

	if (y < 0 || y > height)
	{
		std::cout << "[INFO] MapManager: Invalide y position\n";
		return;
	}

	table[y][x] = tileList[pTileID];

	saveMap();
}


void MapManager::addNewTileType(bool pColision, const char* pImage)
{
	for (int i = 0; i < tileNumber; i++)
		if (tileList[i] == nullptr)
		{
			Tile* newTile = new Tile(i, pColision, pImage);
			tileList[i] = newTile;
			return;
		}

	Tile* newTile = new Tile(tileNumber, pColision, pImage);
	Tile** newTileList = new Tile * [tileNumber + 1];
	for (int i = 0; i < tileNumber; i++)
		newTileList[i] = tileList[i];
	newTileList[tileNumber++] = newTile;

	delete[] tileList;
	tileList = newTileList;
	saveTiles();
}

void MapManager::changeTileType(int pTileID, bool pColision, const char* pImage)
{
	if (pTileID < 0 || pTileID >= tileNumber)
	{
		std::cout << "[INFO] MapManager: invalid index \n";
		return;
	}
	
	tileList[pTileID]->setColision(pColision);
	tileList[pTileID]->setTextrure(pImage);
	saveTiles();
}

void MapManager::deleteTileType(int pTileID)
{
	delete tileList[pTileID];
	tileList[pTileID] = nullptr;

	saveTiles();
}

void MapManager::draw(sf::RenderWindow* window, Camera* camera)
{
	float pixelScale = PIXEL_SIZE * camera->getScale();

	sf::Vector2f screenPosition = camera->getPosition();
	sf::Vector2f startPosition = MyFuncs::divisionVector(screenPosition, pixelScale);

	sf::Vector2f endPosition = screenPosition + sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
	endPosition = MyFuncs::divisionVector(endPosition, pixelScale);

	int startY = std::max(0, (int)startPosition.y);
	int startX = std::max(0, (int)startPosition.x);

	int endY = std::min((int)endPosition.y + 1, (int)height);
	int endX = std::min((int)endPosition.x + 1, (int)width);

	for (int y = startY; y < endY; y++)
		for (int x = startX; x < endX; x++)
			table[y][x]->draw(window, sf::Vector2f(x * pixelScale, y * pixelScale) - screenPosition, camera->getScale());
}

