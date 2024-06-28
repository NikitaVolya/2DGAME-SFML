#include "GameSprite.h"

void GameSprite::uploadSprite()
{
	std::string tileHref("resources\\sprites\\tile\\");
	std::string entityHref("resources\\sprites\\entity\\");
	std::map<size_t, std::string> TileSprites{ {0, "empty.png"}, { 10 , "base_wall.png" } };
	std::map<size_t, std::string> EntitySprites{ {1, "skeleton2_v2_1.png"},{ 11, "skeleton2_v2_1.png" } };

	std::string spriteHref;
	if (spriteID % 10 == 0)
		spriteHref = tileHref + TileSprites.at(spriteID);
	else 
		spriteHref = entityHref + EntitySprites.at(spriteID);

	texture.loadFromFile(spriteHref);

	sprite.setTexture(texture);
	sf::Vector2u textureSize = texture.getSize();
	sprite.setScale((float)PIXEL_SIZE / textureSize.x, (float)PIXEL_SIZE / textureSize.y);

	GameSprite::GameSpriteListe.append(this);
}

GameSprite* GameSprite::loadSprite(size_t ID)
{
	for (DoubleLinkedList<GameSprite*>::Iterator it = GameSprite::GameSpriteListe.begin();
		it != GameSprite::GameSpriteListe.end(); ++it)
		if (it.value()->getId() == ID)
			return it.value();

	return new GameSprite(ID);
}

void GameSprite::clearSprites()
{
	for (DoubleLinkedList<GameSprite*>::Iterator it = GameSprite::GameSpriteListe.begin();
		it != GameSprite::GameSpriteListe.end(); ++it)
	{
		delete it.value();
	}
	GameSpriteListe.clear();
}

void GameSprite::flip()
{
	sprite.setScale(-sprite.getScale().x, sprite.getScale().y);
	rotate = !rotate;
}

void GameSprite::draw(sf::RenderWindow* renderWindow, sf::Vector2f position, bool rotate)
{
	sf::Vector2f drawPosition = position;
	if (this->rotate != rotate)
		flip();

	if (rotate)
		drawPosition.x += PIXEL_SIZE;

	sprite.setPosition(drawPosition);
	renderWindow->draw(sprite);
}
